#include "StdAfx.h"
#include "sub_groupdata_Connection.h"

#if !defined (__GAME_INLINE__)
#include "sub_groupdata_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string sub_groupdata_Connection_Impl::metaname ("sub_groupdata_Connection");

  //
  // is_abstract
  //
  const bool sub_groupdata_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Subscriber_in src, GroupDataQosPolicy_in dst)
  //
  sub_groupdata_Connection sub_groupdata_Connection_Impl::_create (const DDSQoS_in parent, Subscriber_in src, GroupDataQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, sub_groupdata_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void sub_groupdata_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_sub_groupdata_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS sub_groupdata_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Subscriber
  //
  Subscriber sub_groupdata_Connection_Impl::src_Subscriber (void) const
  {
    return Subscriber::_narrow (this->src ());
  }

  //
  // GroupDataQosPolicy
  //
  GroupDataQosPolicy sub_groupdata_Connection_Impl::dst_GroupDataQosPolicy (void) const
  {
    return GroupDataQosPolicy::_narrow (this->dst ());
  }
}

