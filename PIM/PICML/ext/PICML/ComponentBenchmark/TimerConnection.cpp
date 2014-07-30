// $Id$

#include "StdAfx.h"
#include "TimerConnection.h"

#if !defined (__GAME_INLINE__)
#include "TimerConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TimerConnection_Impl::metaname ("TimerConnection");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  TimerConnection TimerConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < TimerConnection > (parent, TimerConnection_Impl::metaname);
  }

  //
  // accept
  //
  void TimerConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TimerConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TimerConnection_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // OperationRef
  //
  OperationRef TimerConnection_Impl::src_OperationRef (void) const
  {
    return OperationRef::_narrow (this->src ());
  }

  //
  // TimeProbe
  //
  TimeProbe TimerConnection_Impl::dst_TimeProbe (void) const
  {
    return TimeProbe::_narrow (this->dst ());
  }
}
