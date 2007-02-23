// $Id$

#include "CIAO_Proxy_Source_Traits.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Proxy_Source_Traits.inl"
#endif

// CUTS headers
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"
#include "CIAO_Var_Type.h"

#include "cuts/be/BE_Preprocessor.h"
#include "cuts/be/BE_Options.h"

// UDM headers
#include "Uml.h"

// STL headers
#include <sstream>
#include <fstream>
#include <algorithm>

// BOOST headers
#include "boost/bind.hpp"

//
// CUTS_CIAO_Proxy_Source_Traits
//
CUTS_CIAO_Proxy_Source_Traits::
CUTS_CIAO_Proxy_Source_Traits (void)
{

}

//
// ~CUTS_CIAO_Proxy_Source_Traits
//
CUTS_CIAO_Proxy_Source_Traits::
~CUTS_CIAO_Proxy_Source_Traits (void)
{

}

//
// open_file
//
bool CUTS_CIAO_Proxy_Source_Traits::
open_file (const PICML::ComponentImplementationContainer & container)
{
  const CUTS_BE_Impl_Node * node = 0;
  if (!CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), node))
    return false;

  if (!node->is_proxy_)
    return false;

  return this->_super::open_file (container);
}

//
// write_prologue
//
void CUTS_CIAO_Proxy_Source_Traits::
write_prologue (const PICML::ComponentImplementationContainer & container)
{
  std::string basename = (std::string) container.name ();
  size_t index = basename.find_last_of ('/');

  if (index != std::string::npos)
    basename.erase (0, index + 1);

  this->outfile ()
    << single_line_comment ("This file was generated by")
    << single_line_comment ("$Id$")
    << std::endl
    << include (basename + CUTS_BE_OPTIONS ()->exec_suffix_)
    << include ("cuts/Activation_Record")
    << include ("cuts/Thread_Activation_Record")
    << std::endl;
}

//
// write_epilogue
//
void CUTS_CIAO_Proxy_Source_Traits::
write_epilogue (const PICML::ComponentImplementationContainer & container)
{

}

//
// write_impl_begin
//
void CUTS_CIAO_Proxy_Source_Traits::
write_impl_begin (const PICML::MonolithicImplementation & monoimpl,
                  const PICML::Component & component)
{
  // Create some of the commonly used names.
  this->object_impl_ = (std::string) component.name ();
  std::string destructor = "~" + this->object_impl_;
  std::string ctx_proxy = (std::string)component.name () + "_Context_Proxy";

  // Generate the event sinks for the context.
  typedef std::vector <PICML::OutEventPort> OutEventPort_Set;
  OutEventPort_Set sources = component.OutEventPort_kind_children ();

  this->outfile ()
    << "namespace CIDL_" << monoimpl.name () << "{"
    << function_header (ctx_proxy)
    << ctx_proxy << "::" << std::endl
    << ctx_proxy << " (::Components::SessionContext::_ptr_type ctx," << std::endl
    << "CUTS_Benchmark_Agent * agent)" << std::endl
    << ": CUTS_CCM_Context_T <" << scope (component, "::")
    << "CCM_" << component.name () << "_Context> (ctx, agent) {";

  std::for_each (
    sources.begin (),
    sources.end (),
    boost::bind (&CUTS_CIAO_Proxy_Source_Traits::write_endpoint_register,
                 this,
                 _1));

  this->outfile ()
    << "}"
    << function_header ("~" + ctx_proxy)
    << ctx_proxy << "::" << std::endl
    << "~" << ctx_proxy << " (void) {"
    << "}";


  typedef
    void (CUTS_CIAO_Proxy_Source_Traits::*OutEventPort_method) (
    const PICML::OutEventPort &);

  std::for_each (sources.begin (),
                 sources.end (),
                 boost::bind (reinterpret_cast <OutEventPort_method> (
                 &CUTS_CIAO_Proxy_Source_Traits::write_method),
                 this,
                 _1));

  // Generate the receptacles for the context.
  typedef std::vector <PICML::RequiredRequestPort> RequiredRequestPort_Set;
  RequiredRequestPort_Set receptacles = component.RequiredRequestPort_kind_children ();

  typedef
    void (CUTS_CIAO_Proxy_Source_Traits::*RequiredRequestPort_method) (
    const PICML::RequiredRequestPort &);

  std::for_each (receptacles.begin (),
                 receptacles.end (),
                 boost::bind (reinterpret_cast <RequiredRequestPort_method> (
                 &CUTS_CIAO_Proxy_Source_Traits::write_method),
                 this,
                 _1));

  // We are now ready to generate the executor.
  this->outfile ()
    << function_header (this->object_impl_)
    << this->object_impl_ << "::" << this->object_impl_ << " (void)"
    << "{";

  typedef std::vector <PICML::InEventPort> InEventPort_Set;
  InEventPort_Set sinks = component.InEventPort_kind_children ();

  std::for_each (
    sinks.begin (),
    sinks.end (),
    boost::bind (&CUTS_CIAO_Proxy_Source_Traits::write_agent_register,
                 this,
                 _1));

  this->outfile ()
    << "}"

    << function_header (destructor)
    << this->object_impl_ << "::" << destructor << " (void)"
    << "{"
    << "}";
}

//
// write_impl_end
//
void CUTS_CIAO_Proxy_Source_Traits::
write_impl_end (const PICML::MonolithicImplementation & monoimpl,
                const PICML::Component & component)
{
  this->in_events_.clear ();
}

//
// write_ReadonlyAttribute_begin
//
void CUTS_CIAO_Proxy_Source_Traits::
write_ReadonlyAttribute_begin (const PICML::ReadonlyAttribute & attr)
{
  this->_super::write_ReadonlyAttribute_begin (attr);

  if ((std::string)attr.name () == "cuts_proxy_impl")
  {
    this->outfile ()
      << "return this->_proxy_type::cuts_proxy_impl ();";
  }
  else
  {
    this->outfile ()
      << "return this->type_impl_->" << attr.name () << " ();";
  }
}

//
// write_method
//
void CUTS_CIAO_Proxy_Source_Traits::
write_method (const PICML::OutEventPort & source)
{
  this->_super::write_method (source);

  std::string name = source.name ();

  this->outfile ()
    << single_line_comment ("record time of exit for event")
    << "CUTS_Activation_Record * record = CUTS_THR_ACTIVATION_RECORD ();"
    << "record->log_endpoint (this->" << name << "_id_);"
    << std::endl
    << single_line_comment ("continue sending event")
    << "this->ctx_->push_" << name << " (ev);"
    << "}";
}

//
// write_method
//
void CUTS_CIAO_Proxy_Source_Traits::
write_method (const PICML::RequiredRequestPort & receptacle)
{
  this->_super::write_method (receptacle);

  this->outfile ()
    << "return this->ctx_->get_connection_" << receptacle.name () << " ();"
    << "}";
}

//
// write_method_begin
//
void CUTS_CIAO_Proxy_Source_Traits::
write_Attribute_begin (const PICML::Attribute & attr)
{
  this->_super::write_Attribute_begin (attr);

  if ((std::string)attr.name () == "cuts_proxy_impl")
  {
    this->outfile ()
      << single_line_comment ("load the implementation")
      << "this->_proxy_type::cuts_proxy_impl (cuts_proxy_impl);"
      << std::endl
      << single_line_comment ("set context of hosted component")
      << "if (!::CORBA::is_nil (this->sc_.in ()))" << std::endl
      << "  this->sc_->set_session_context (this->context_.get ());"
      << std::endl
      << single_line_comment ("bind event handlers to new component");

    // We need to boost::bind the newly loaded component to the event
    // handlers. We can only do it now since this is when we know
    // for sure the component is loaded into the proxy.
    PICML::Component component = PICML::Component::Cast (attr.parent ());

    typedef std::vector <PICML::InEventPort> InEventPort_Set;
    InEventPort_Set sinks = component.InEventPort_kind_children ();

    std::for_each (sinks.begin (),
                   sinks.end (),
                   boost::bind (&CUTS_CIAO_Proxy_Source_Traits::
                                write_event_handler_bind,
                                this,
                                _1));
  }
  else
  {
    this->outfile ()
      << "if (!::CORBA::is_nil (this->type_impl_.in ()))" << std::endl
      << "  this->type_impl_->"
      << attr.name () << " (" << attr.name () << ");"
      << "else {"
      << single_line_comment ("wait until the real component is loaded")
      << "this->pending_ops_.insert (" << std::endl
      << "CUTS_Pending_Op (&_proxy_type::_impl_type::"
      << attr.name () << "," << std::endl
      << attr.name () << "));"
      << "}";
  }
}

//
// write_set_session_context
//
void CUTS_CIAO_Proxy_Source_Traits::
write_set_session_context (const PICML::Component & component)
{
  this->_super::write_set_session_context (component);

  std::string name = (std::string)component.name ();
  std::string context = name + "_Context";
  std::string context_proxy = context + "_Proxy";

  this->outfile ()
    << "{"
    << single_line_comment ("initialize the context proxy")
    << context_proxy << " * temp = 0;"
    << "ACE_NEW_THROW_EX (temp," << std::endl
    << context_proxy << " (ctx, this->agent_)," << std::endl
    << "::CORBA::NO_MEMORY ());"
    << "this->context_.reset (temp);"
    << std::endl
    << single_line_comment ("cache the instance name of hosted component")
    << context << " * ciao_ctx = " << context << "::_narrow (ctx);"
    << "this->instance_ = ciao_ctx->_ciao_instance_id ();"
    << std::endl;

  std::for_each (
    this->in_events_.begin (),
    this->in_events_.end (),
    boost::bind (&CUTS_CIAO_Proxy_Source_Traits::write_register_obv_factory,
                 this,
                 _1));

  // Close off the function.
  this->outfile ()
    << "}";
}

//
// write_register_obv_factory
//
void CUTS_CIAO_Proxy_Source_Traits::
write_register_obv_factory (const PICML::Event & event)
{
  std::string name = event.name ();
  std::string event_scope = scope (event, "::");

  this->outfile ()
    << single_line_comment ("Event Registration: " + name)
    << "CUTS_REGISTER_OBV_FACTORY (ciao_ctx," << std::endl
    << event_scope << name << "_init," << std::endl
    << event_scope << name << ");"
    << std::endl;
}

//
// write_event_handler_bind
//
void CUTS_CIAO_Proxy_Source_Traits::
write_event_handler_bind (const PICML::InEventPort & sink)
{
  this->outfile ()
    << "this->push_" << sink.name () << "_.bind (" << std::endl
    << "this->type_impl_.ptr (), " << std::endl
    << "&_proxy_type::_impl_type::push_" << sink.name ()
    << ");"
    << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Proxy_Source_Traits::
write_InEventPort_begin (const PICML::InEventPort & sink)
{
  this->_super::write_InEventPort_begin (sink);

  this->outfile ()
    << "this->push_" << sink.name () << "_.handle_event (ev);";

  // Now, we need to save the event type for this sink so that
  // we can register it's valuetype w/ the ORB.
  PICML::Event event = sink.ref ();

  if (event != Udm::null)
    this->in_events_.insert (event);
}

//
// write_method_begin
//
void CUTS_CIAO_Proxy_Source_Traits::
write_ProvidedRequestPort_begin (const PICML::ProvidedRequestPort & facet)
{
  this->_super::write_ProvidedRequestPort_begin (facet);

  this->outfile ()
    << "return this->type_impl_->get_" << facet.name () << " ();";
}

//
// write_method_end
//
void CUTS_CIAO_Proxy_Source_Traits::
write_Attribute_end (const PICML::Attribute & attr)
{
  if ((std::string)attr.name () == "cuts_proxy_impl")
  {
    this->outfile ()
      << single_line_comment ("process any pending operations")
      << "if (this->pending_ops_.size () > 0)" << std::endl
      << "  this->pending_ops_.process (this->type_impl_.ptr ());";
  }

  this->_super::write_Attribute_end (attr);
}

//
// write_endpoint_register
//
void CUTS_CIAO_Proxy_Source_Traits::
write_endpoint_register (const PICML::OutEventPort & source)
{
  this->outfile ()
    << "this->agent_->register_endpoint (\"" << source.name ()
    << "\", this->" << source.name () << "_id_);";
}

//
// write_agent_register
//
void CUTS_CIAO_Proxy_Source_Traits::
write_agent_register (const PICML::InEventPort & sink)
{
  this->outfile ()
    << "this->push_" << sink.name () << "_.port_agent ().name (\""
    << sink.name () << "\");"
    << "this->agent_->register_agent (&this->push_"
    << sink.name () << "_.port_agent ());"
    << std::endl;
}
