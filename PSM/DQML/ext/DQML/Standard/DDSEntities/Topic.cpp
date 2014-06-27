// $Id$

#include "StdAfx.h"
#include "Topic.h"

#if !defined (__GAME_INLINE__)
#include "Topic.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DeadlineQosPolicy/top_deadline_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/topic_dursvc_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/topic_transpri_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/topic_ownership_Connection.h"
#include "DQML/Standard/TopicDataQosPolicy/topic_topicdata_Connection.h"
#include "DQML/Standard/Main/dp_topic_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/topic_res_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/topic_durqos_Connection.h"
#include "DQML/Standard/Main/dr_topic_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/topic_lifespan_Connection.h"
#include "DQML/Standard/Main/dw_topic_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/topic_reliability_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/topic_dstOrder_Connection.h"
#include "DQML/Standard/LatencyBudgetQosPolicy/top_latency_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/topic_liveliness_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/topic_history_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string Topic_Impl::metaname ("Topic");

  //
  // _create (const DDSQoS_in)
  //
  Topic Topic_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < Topic > (parent, Topic_Impl::metaname);
  }

  //
  // accept
  //
  void Topic_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Topic (this);
    else
      v->visit_Model (this);
  }

  //
  // src_top_deadline_Connection
  //
  size_t Topic_Impl::src_top_deadline_Connection (std::vector <top_deadline_Connection> & items) const
  {
    return this->in_connections <top_deadline_Connection> (items);
  }

  //
  // src_topic_dursvc_Connection
  //
  size_t Topic_Impl::src_topic_dursvc_Connection (std::vector <topic_dursvc_Connection> & items) const
  {
    return this->in_connections <topic_dursvc_Connection> (items);
  }

  //
  // src_topic_transpri_Connection
  //
  size_t Topic_Impl::src_topic_transpri_Connection (std::vector <topic_transpri_Connection> & items) const
  {
    return this->in_connections <topic_transpri_Connection> (items);
  }

  //
  // src_topic_ownership_Connection
  //
  size_t Topic_Impl::src_topic_ownership_Connection (std::vector <topic_ownership_Connection> & items) const
  {
    return this->in_connections <topic_ownership_Connection> (items);
  }

  //
  // src_topic_topicdata_Connection
  //
  size_t Topic_Impl::src_topic_topicdata_Connection (std::vector <topic_topicdata_Connection> & items) const
  {
    return this->in_connections <topic_topicdata_Connection> (items);
  }

  //
  // src_topic_res_Connection
  //
  size_t Topic_Impl::src_topic_res_Connection (std::vector <topic_res_Connection> & items) const
  {
    return this->in_connections <topic_res_Connection> (items);
  }

  //
  // src_topic_durqos_Connection
  //
  size_t Topic_Impl::src_topic_durqos_Connection (std::vector <topic_durqos_Connection> & items) const
  {
    return this->in_connections <topic_durqos_Connection> (items);
  }

  //
  // src_topic_lifespan_Connection
  //
  size_t Topic_Impl::src_topic_lifespan_Connection (std::vector <topic_lifespan_Connection> & items) const
  {
    return this->in_connections <topic_lifespan_Connection> (items);
  }

  //
  // src_topic_reliability_Connection
  //
  size_t Topic_Impl::src_topic_reliability_Connection (std::vector <topic_reliability_Connection> & items) const
  {
    return this->in_connections <topic_reliability_Connection> (items);
  }

  //
  // src_topic_dstOrder_Connection
  //
  size_t Topic_Impl::src_topic_dstOrder_Connection (std::vector <topic_dstOrder_Connection> & items) const
  {
    return this->in_connections <topic_dstOrder_Connection> (items);
  }

  //
  // src_top_latency_Connection
  //
  size_t Topic_Impl::src_top_latency_Connection (std::vector <top_latency_Connection> & items) const
  {
    return this->in_connections <top_latency_Connection> (items);
  }

  //
  // src_topic_liveliness_Connection
  //
  size_t Topic_Impl::src_topic_liveliness_Connection (std::vector <topic_liveliness_Connection> & items) const
  {
    return this->in_connections <topic_liveliness_Connection> (items);
  }

  //
  // src_topic_history_Connection
  //
  size_t Topic_Impl::src_topic_history_Connection (std::vector <topic_history_Connection> & items) const
  {
    return this->in_connections <topic_history_Connection> (items);
  }

  //
  // dst_dp_topic_Connection
  //
  size_t Topic_Impl::dst_dp_topic_Connection (std::vector <dp_topic_Connection> & items) const
  {
    return this->in_connections <dp_topic_Connection> (items);
  }

  //
  // dst_dr_topic_Connection
  //
  size_t Topic_Impl::dst_dr_topic_Connection (std::vector <dr_topic_Connection> & items) const
  {
    return this->in_connections <dr_topic_Connection> (items);
  }

  //
  // dst_dw_topic_Connection
  //
  size_t Topic_Impl::dst_dw_topic_Connection (std::vector <dw_topic_Connection> & items) const
  {
    return this->in_connections <dw_topic_Connection> (items);
  }
}
