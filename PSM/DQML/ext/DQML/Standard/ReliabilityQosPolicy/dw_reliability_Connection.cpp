#include "StdAfx.h"
#include "dw_reliability_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_reliability_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/ReliabilityQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_reliability_Connection_Impl::metaname ("dw_reliability_Connection");

  //
  // is_abstract
  //
  const bool dw_reliability_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, DataWriter_in src, ReliabilityQosPolicy_in dst)
  //
  dw_reliability_Connection dw_reliability_Connection_Impl::_create (const DDSQoS_in parent, DataWriter_in src, ReliabilityQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dw_reliability_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dw_reliability_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_reliability_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_reliability_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_reliability_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // ReliabilityQosPolicy
  //
  ReliabilityQosPolicy dw_reliability_Connection_Impl::dst_ReliabilityQosPolicy (void) const
  {
    return ReliabilityQosPolicy::_narrow (this->dst ());
  }
}

