// $Id$

#include "StdAfx.h"
#include "ComponentFactoryInstance.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactoryInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryInstance_Impl::metaname ("ComponentFactoryInstance");

  //
  // _create (const ComponentFactoryImplementationContainer_in)
  //
  ComponentFactoryInstance ComponentFactoryInstance_Impl::_create (const ComponentFactoryImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentFactoryInstance > (parent, ComponentFactoryInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactoryInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentFactoryInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentFactoryImplementationContainer
  //
  ComponentFactoryImplementationContainer ComponentFactoryInstance_Impl::parent_ComponentFactoryImplementationContainer (void)
  {
    return ComponentFactoryImplementationContainer::_narrow (this->parent ());
  }

  //
  // ComponentFactory_is_nil
  //
  bool ComponentFactoryInstance_Impl::ComponentFactory_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ComponentFactory
  //
  void ComponentFactoryInstance_Impl::set_ComponentFactory (ComponentFactory_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ComponentFactory
  //
  ComponentFactory ComponentFactoryInstance_Impl::get_ComponentFactory (void) const
  {
    return ComponentFactory::_narrow (this->refers_to ());
  }
}

