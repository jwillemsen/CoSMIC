#include "StdAfx.h"
#include "WorkLoadOperationConnection.h"

#if !defined (__GAME_INLINE__)
#include "WorkLoadOperationConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkLoadOperationConnection_Impl::metaname ("WorkLoadOperationConnection");

  //
  // is_abstract
  //
  const bool WorkLoadOperationConnection_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in, OperationRef_in src, Task_in dst)
  //
  WorkLoadOperationConnection WorkLoadOperationConnection_Impl::_create (const BenchmarkAnalysis_in parent, OperationRef_in src, Task_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, WorkLoadOperationConnection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void WorkLoadOperationConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkLoadOperationConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis WorkLoadOperationConnection_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // OperationRef
  //
  OperationRef WorkLoadOperationConnection_Impl::src_OperationRef (void) const
  {
    return OperationRef::_narrow (this->src ());
  }

  //
  // Task
  //
  Task WorkLoadOperationConnection_Impl::dst_Task (void) const
  {
    return Task::_narrow (this->dst ());
  }
}

