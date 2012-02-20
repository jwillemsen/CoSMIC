// $Id$

#include "StdAfx.h"
#include "dr_userdata_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dr_userdata_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "DQML/Standard/QoSPolicies/UserDataQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dr_userdata_Connection_Impl::metaname ("dr_userdata_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dr_userdata_Connection dr_userdata_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dr_userdata_Connection > (parent, dr_userdata_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dr_userdata_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dr_userdata_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // DataReader
  //
  DataReader dr_userdata_Connection_Impl::src_DataReader (void) const
  {
    return DataReader::_narrow (this->src ());
  }

  //
  // UserDataQosPolicy
  //
  UserDataQosPolicy dr_userdata_Connection_Impl::dst_UserDataQosPolicy (void) const
  {
    return UserDataQosPolicy::_narrow (this->dst ());
  }
}

