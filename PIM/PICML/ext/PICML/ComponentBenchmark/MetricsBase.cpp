#include "StdAfx.h"
#include "MetricsBase.h"

#if !defined (__GAME_INLINE__)
#include "MetricsBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "PICML/ComponentBenchmark/Jitter.h"
#include "PICML/ComponentBenchmark/Maximum.h"
#include "PICML/ComponentBenchmark/Minimum.h"
#include "PICML/ComponentBenchmark/Average.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MetricsBase_Impl::metaname ("MetricsBase");

  //
  // is_abstract
  //
  const bool MetricsBase_Impl::is_abstract = true;

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis MetricsBase_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // src_of_WorkloadCharacteristics
  //
  size_t MetricsBase_Impl::src_of_WorkloadCharacteristics (std::vector <WorkloadCharacteristics> & items) const
  {
    return this->in_connections <WorkloadCharacteristics> (items);
  }

  //
  // has_src_of_WorkloadCharacteristics
  //
  bool MetricsBase_Impl::has_src_of_WorkloadCharacteristics (void) const
  {
    return this->in_connections <WorkloadCharacteristics> ("src").count () == 1;
  }

  //
  // src_of_WorkloadCharacteristics
  //
  WorkloadCharacteristics MetricsBase_Impl::src_of_WorkloadCharacteristics (void) const
  {
    return this->in_connections <WorkloadCharacteristics> ("src").first ();
  }

  //
  // dst_of_MetricConnection
  //
  size_t MetricsBase_Impl::dst_of_MetricConnection (std::vector <MetricConnection> & items) const
  {
    return this->in_connections <MetricConnection> (items);
  }

  //
  // dst_of_MetricConnection
  //
  MetricConnection MetricsBase_Impl::dst_of_MetricConnection (void) const
  {
    return this->in_connections <MetricConnection> ("dst").first ();
  }

  //
  // dst_of_BenchmarkCharacteristics
  //
  size_t MetricsBase_Impl::dst_of_BenchmarkCharacteristics (std::vector <BenchmarkCharacteristics> & items) const
  {
    return this->in_connections <BenchmarkCharacteristics> (items);
  }

  //
  // has_dst_of_BenchmarkCharacteristics
  //
  bool MetricsBase_Impl::has_dst_of_BenchmarkCharacteristics (void) const
  {
    return this->in_connections <BenchmarkCharacteristics> ("dst").count () == 1;
  }

  //
  // dst_of_BenchmarkCharacteristics
  //
  BenchmarkCharacteristics MetricsBase_Impl::dst_of_BenchmarkCharacteristics (void) const
  {
    return this->in_connections <BenchmarkCharacteristics> ("dst").first ();
  }

  //
  // get_Jitters
  //
  size_t MetricsBase_Impl::get_Jitters (std::vector <Jitter> & items) const
  {
    return this->children (items);
  }

  //
  // get_Jitters
  //
  ::GAME::Mga::Collection_T <Jitter> MetricsBase_Impl::get_Jitters (void) const
  {
    return this->children <Jitter> ();
  }

  //
  // get_Maximums
  //
  size_t MetricsBase_Impl::get_Maximums (std::vector <Maximum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Maximums
  //
  ::GAME::Mga::Collection_T <Maximum> MetricsBase_Impl::get_Maximums (void) const
  {
    return this->children <Maximum> ();
  }

  //
  // get_Minimums
  //
  size_t MetricsBase_Impl::get_Minimums (std::vector <Minimum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Minimums
  //
  ::GAME::Mga::Collection_T <Minimum> MetricsBase_Impl::get_Minimums (void) const
  {
    return this->children <Minimum> ();
  }

  //
  // get_Averages
  //
  size_t MetricsBase_Impl::get_Averages (std::vector <Average> & items) const
  {
    return this->children (items);
  }

  //
  // get_Averages
  //
  ::GAME::Mga::Collection_T <Average> MetricsBase_Impl::get_Averages (void) const
  {
    return this->children <Average> ();
  }
}

