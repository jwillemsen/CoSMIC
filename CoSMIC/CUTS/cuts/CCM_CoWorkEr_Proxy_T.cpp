// $Id$

#if !defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr_Proxy_T.inl"
#endif

#include "cuts/Thread_Activation_Record.h"

//
// CUTS_CCM_CoWorkEr_Proxy_T
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
CUTS_CCM_CoWorkEr_Proxy_T (void)
{

}

//
// CUTS_CCM_CoWorkEr_Proxy_T
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
~CUTS_CCM_CoWorkEr_Proxy_T (void)
{

}

//
// cuts_proxy_impl
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
void CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
cuts_proxy_impl (const char * impl)
ACE_THROW_SPEC ((::CORBA::SystemException))
{
  // This method can only be called once during the lifetime of
  // the proxy if it has already been contaminated.
  if (!::CORBA::is_nil (this->type_impl_.in ()))
    return;

  // Now, lets butcher the original string. :o) We are going
  // to seperate the module from the entry point. The <impl>
  // string is in the format [module:entry]
  this->cuts_proxy_impl_.set (impl);
  char * entry = ACE_OS::strchr (ACE_const_cast (char *, impl), ':');

  if (entry == 0)
  {
    ACE_ERROR ((LM_ERROR,
                "failed to located entry point in %s\n",
                this->cuts_proxy_impl_.c_str ()));

    ACE_THROW ((::CORBA::BAD_PARAM ()));
  }

  *entry ++ = '\0';

  if (this->load_implementation (impl, entry) == -1)
    ACE_THROW (::CORBA::BAD_PARAM ());
}

//
// cuts_proxy_impl
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
char * CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
cuts_proxy_impl (void)
ACE_THROW_SPEC ((::CORBA::SystemException))
{
  ::CORBA::String_var str =
    ::CORBA::string_dup (this->cuts_proxy_impl_.c_str ());

  return str._retn ();
}

//
// load_implementation
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
int CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
load_implementation (const char * dllname, const char * entry)
{
  ACE_DLL module;

  if (module.open (dllname, ACE_DEFAULT_SHLIB_MODE, 0) != 0)
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (load_implementation) : %s\n",
                       module.error ()),
                       -1);
  }

  // Extract the entry point from the module.
  void * symbol = module.symbol (entry);

  if (symbol == 0)
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (load_implementation): "
                       "failed to locate entry point '%s' in %s\n",
                       entry,
                       module.dll_name_),
                       -1);
  }

  // Convert to function pointer that returns to correct type.
  typedef ::Components::HomeExecutorBase_ptr (* ENTRY_POINT) (void);
  ENTRY_POINT entry_point = reinterpret_cast <ENTRY_POINT> (symbol);

  // Create the base home executor from the entry point, then
  // narrow it to the correct home to created the executor.
  ::Components::HomeExecutorBase_var home_base = entry_point ();
  CCM_HOME::_var_type home_impl = CCM_HOME::_narrow (home_base.in ());

  if (::CORBA::is_nil (home_impl.in ()))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (load_implemenation): failed to "
                       "extract component home\n"),
                       -1);
  }

  // Create the component from the home and store it in <proxy_impl_>.
  ::CORBA::Object_var obj = home_impl->create ();
  this->type_impl_ = _impl_type::_narrow (obj.in ());

  if (::CORBA::is_nil (this->type_impl_.in ()))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (load_implemenation): failed to "
                       "create component\n"),
                       -1);
  }

  // Extract the session component and set its context. We need to
  // save the session component as well since we will be using it
  // quite often during the component's lifecycle.
  this->sc_ =
    ::Components::SessionComponent::_narrow (this->type_impl_.in ());

  if (::CORBA::is_nil (this->sc_.in ()))
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (load_implemenation): loaded component "
                       "is not a session component\n"),
                       -1);
  }

  return 0;
}

//
// ciao_preactivate
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
void CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::CCMException))
{
  // Let's get the testing service so that we can go ahead
  // and get a registration id for this component we are hosting.
  ::CUTS::Testing_Service_var tsvc =
    this->context_->get_connection_cuts_testing_service ();

  if (::CORBA::is_nil (tsvc.in ()))
    {
      ACE_DEBUG ((LM_INFO,
                  "[%M] (preactivate) -%T - %s not connected to data collector\n",
                  this->instance_.c_str ()));
    }
  else if (::CORBA::is_nil (this->type_impl_.in ()))
    {
      ACE_DEBUG ((LM_WARNING,
                  "[%M] (preactivate) -%T - %s does not have a loaded component\n",
                  this->instance_.c_str ()));
    }
  else
    {
      try
        {
          ::CUTS::Component_Registration reg;
          reg.name = ::CORBA::string_dup (this->instance_.c_str ());
          reg.type = ::CORBA::string_dup (this->type_impl_->_interface_repository_id ());

          reg.generic_object = this->context_->get_CCM_object ();
          reg.agent = ::CUTS::Benchmark_Agent::_duplicate (this->agent_->_this ());

          // Pass control to the base class to finish the registration.
          size_t regid = this->register_i (tsvc.in (), reg);

          if (regid == CUTS_UNKNOWN_IMPL)
            {
              ACE_ERROR ((LM_ERROR,
                          "failed to register %s; setting id to %u\n",
                          reg.name.in (),
                          regid));
            }

          // Store registration id and pass control to hosted component.
          this->agent_->parent (regid);
        }
      catch (const ::CORBA::Exception & ex)
        {
          ACE_ERROR ((LM_ERROR,
                      "[%M] (preactivate) -%T - %s\n",
                      ex._info ().c_str ()));
        }
      catch (...)
        {
          ACE_ERROR ((LM_ERROR,
                      "[%M] (preactivate) -%T - unknown exception has occurred\n"));
        }
    }

  // We still need to invoke the preactivate method for the
  // hosted component regardless of it is connected to the BDC.
  if (!::CORBA::is_nil (this->sc_.in ()))
    this->sc_->ciao_preactivate ();
}

//
// ccm_passivate
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
void CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
ccm_passivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::CCMException))
{
  // We need to let the real component passivate itself before
  // we try to do anything. This is just in case the real component
  // still want to perform some operations that requires its id.
  if (!::CORBA::is_nil (this->sc_.in ()))
    this->sc_->ccm_passivate ();

  // Let's get the testing service so that we can go ahead
  // and get a registration id for this component we are hosting.
  ::CUTS::Testing_Service_var tsvc =
    this->context_->get_connection_cuts_testing_service ();

  if (!::CORBA::is_nil (tsvc.in ()))
  {
    try
    {
      // Initialize registration data structure to unregister component.
      ::CUTS::Component_Registration reg;
      reg.name  = ::CORBA::string_dup (this->instance_.c_str ());
      reg.agent = ::CUTS::Benchmark_Agent::_duplicate (this->agent_->_this ());

      if (this->agent_->parent () != CUTS_UNKNOWN_IMPL)
        {
          this->agent_->parent (CUTS_UNKNOWN_IMPL);
          tsvc->unregister_component (reg);
        }
    }
    catch (const ::CORBA::Exception & ex)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] (passivate) -%T - %s\n",
                  ex._info ().c_str ()));
    }
    catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  "[%M] (passivate) -%T - unknown exception has occurred\n"));
    }
  }
  else
  {
    ACE_DEBUG ((LM_INFO,
                "[%M] (passivate) -%T - %s not connected to data collector\n",
                this->instance_.c_str ()));
  }
}

//
// ccm_remove
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
void CUTS_CCM_CoWorkEr_Proxy_T <PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
ccm_remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException,
                 ::Components::CCMException))
{
  if (!::CORBA::is_nil (this->sc_.in ()))
    this->sc_->ccm_remove ();

  this->reset ();
}

//
// reset
//
template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
void CUTS_CCM_CoWorkEr_Proxy_T <
PROXY_EXEC, CTX_TYPE, CCM_TYPE, CCM_HOME>::
reset (void)
{
  this->type_impl_ = CCM_TYPE::_nil ();
  this->sc_ = ::Components::SessionComponent::_nil ();
}

