// $Id$

#include "StdAfx.h"
#include "ActionType.h"

#if !defined (__GAME_INLINE__)
#include "ActionType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ActionType_Impl::metaname ("ActionType");

  //
  // _create (const Action_in)
  //
  ActionType ActionType_Impl::_create (const Action_in parent)
  {
    return ::GAME::Mga::create_object < ActionType > (parent, ActionType_Impl::metaname);
  }

  //
  // accept
  //
  void ActionType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ActionType (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Action
  //
  Action ActionType_Impl::parent_Action (void)
  {
    return Action::_narrow (this->parent ());
  }

  //
  // Operation_is_nil
  //
  bool ActionType_Impl::Operation_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_Operation
  //
  void ActionType_Impl::set_Operation (Operation_in item)
  {
    this->refers_to (item);
  }

  //
  // get_Operation
  //
  Operation ActionType_Impl::get_Operation (void) const
  {
    return Operation::_narrow (this->refers_to ());
  }
}

