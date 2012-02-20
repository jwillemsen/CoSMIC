// $Id$

#include "StdAfx.h"
#include "DomainParticipantFactory.h"

#if !defined (__GAME_INLINE__)
#include "DomainParticipantFactory.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/Main/dpf_dp_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dpfactory_entityfactory_Connection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DomainParticipantFactory_Impl::metaname ("DomainParticipantFactory");

  //
  // _create (const DDSQoS_in)
  //
  DomainParticipantFactory DomainParticipantFactory_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < DomainParticipantFactory > (parent, DomainParticipantFactory_Impl::metaname);
  }

  //
  // accept
  //
  void DomainParticipantFactory_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DomainParticipantFactory (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // src_dpf_dp_Connection
  //
  size_t DomainParticipantFactory_Impl::src_dpf_dp_Connection (std::vector <dpf_dp_Connection> & items) const
  {
    return this->in_connections <dpf_dp_Connection> (items);
  }

  //
  // src_dpfactory_entityfactory_Connection
  //
  size_t DomainParticipantFactory_Impl::src_dpfactory_entityfactory_Connection (std::vector <dpfactory_entityfactory_Connection> & items) const
  {
    return this->in_connections <dpfactory_entityfactory_Connection> (items);
  }
}

