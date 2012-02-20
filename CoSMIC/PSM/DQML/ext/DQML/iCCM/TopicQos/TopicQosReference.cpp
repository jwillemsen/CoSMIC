// $Id$

#include "StdAfx.h"
#include "TopicQosReference.h"

#if !defined (__GAME_INLINE__)
#include "TopicQosReference.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TopicQosReference_Impl::metaname ("TopicQosReference");

  //
  // _create (const DataWriterQos_in)
  //
  TopicQosReference TopicQosReference_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < TopicQosReference > (parent, TopicQosReference_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  TopicQosReference TopicQosReference_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < TopicQosReference > (parent, TopicQosReference_Impl::metaname);
  }

  //
  // accept
  //
  void TopicQosReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TopicQosReference (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // TopicQos_is_nil
  //
  bool TopicQosReference_Impl::TopicQos_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_TopicQos
  //
  TopicQos TopicQosReference_Impl::get_TopicQos (void) const
  {
    return TopicQos::_narrow (this->refers_to ());
  }
}

