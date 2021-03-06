#include "StdAfx.h"
#include "WorkerType.h"

#if !defined (__GAME_INLINE__)
#include "WorkerType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerType_Impl::metaname ("WorkerType");

  //
  // is_abstract
  //
  const bool WorkerType_Impl::is_abstract = false;

  //
  // _create (const TopLevelBehavior_in)
  //
  WorkerType WorkerType_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create < WorkerType > (parent, WorkerType_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkerType (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior WorkerType_Impl::parent_TopLevelBehavior (void)
  {
    return TopLevelBehavior::_narrow (this->parent ());
  }

  //
  // Worker_is_nil
  //
  bool WorkerType_Impl::Worker_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_Worker
  //
  void WorkerType_Impl::refers_to_Worker (Worker_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Worker
  //
  Worker WorkerType_Impl::refers_to_Worker (void) const
  {
    return Worker::_narrow (this->refers_to ());
  }
}

