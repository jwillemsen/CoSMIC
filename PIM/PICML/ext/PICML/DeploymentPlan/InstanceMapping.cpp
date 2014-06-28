// $Id$

#include "StdAfx.h"
#include "InstanceMapping.h"

#if !defined (__GAME_INLINE__)
#include "InstanceMapping.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InstanceMapping_Impl::metaname ("InstanceMapping");

  //
  // _create (const DeploymentPlan_in)
  //
  InstanceMapping InstanceMapping_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < InstanceMapping > (parent, InstanceMapping_Impl::metaname);
  }

  //
  // accept
  //
  void InstanceMapping_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InstanceMapping (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan InstanceMapping_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // CollocationGroup
  //
  CollocationGroup InstanceMapping_Impl::src_CollocationGroup (void) const
  {
    return CollocationGroup::_narrow (this->src ());
  }

  //
  // NodeReference
  //
  NodeReference InstanceMapping_Impl::dst_NodeReference (void) const
  {
    return NodeReference::_narrow (this->dst ());
  }
}

