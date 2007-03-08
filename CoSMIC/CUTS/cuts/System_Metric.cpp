// $Id$

#include "cuts/System_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/System_Metric.inl"
#endif

#include "cuts/Component_Metric.h"
#include "cuts/System_Metrics_Visitor.h"
#include "ace/Guard_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/OS_NS_sys_time.h"

//
// CUTS_System_Metric
//
CUTS_System_Metric::CUTS_System_Metric (void)
{

}

//
// ~CUTS_System_Metric
//
CUTS_System_Metric::~CUTS_System_Metric (void)
{
  CUTS_Component_Metric_Map::iterator iter;

  for (iter = this->component_metrics_.begin ();
       iter != this->component_metrics_.end ();
       iter ++)
  {
    delete iter->second;
  }
}

//
// insert_component
//
CUTS_Component_Metric *
CUTS_System_Metric::insert_component (long regid)
{
  // Create a new <CUTS_Component_Metric>.
  CUTS_Component_Metric * metric = 0;
  ACE_NEW_RETURN (metric, CUTS_Component_Metric (), 0);
  ACE_Auto_Ptr <CUTS_Component_Metric> auto_clean (metric);

  std::pair <
    CUTS_Component_Metric_Map::iterator, bool>
    result;

  ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);

  result = this->component_metrics_.insert (
    CUTS_Component_Metric_Map::value_type (regid, metric));

  // If the <component> was already in the <component_metrics_>
  // then we can save the <metric> as the preexisting component.
  // We do not have to worry about the previously allocated
  // metric since the <auto_clean> will handle it.
  if (!result.second)
  {
    metric = result.first->second;
  }
  else
  {
    auto_clean.release ();
  }

  return metric;
}

//
// component_metrics
//
CUTS_Component_Metric *
CUTS_System_Metric::component_metrics (long regid)
{
  CUTS_Component_Metric * metric = 0;
  CUTS_Component_Metric_Map::iterator result;

  // Locate the <name> of the component in the
  // <component_metrics_>.
  do
  {
    ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
    result = this->component_metrics_.find (regid);
  } while (false);

  // If we found the component the we just return it. Otherwise,
  // we have to insert the new component into the <component_metrics_>.
  if (result != this->component_metrics_.end ())
  {
    metric = result->second;
  }
  else
  {
    metric = insert_component (regid);
  }

  return metric;
}

//
// accept
//
void CUTS_System_Metric::
accept (CUTS_System_Metrics_Visitor & visitor) const
{
  return visitor.visit_system_metrics (*this);
}

//
// timestamp
//
void CUTS_System_Metric::
set_timestamp (const ACE_Time_Value * timestamp)
{
  // Save the previous timestamp before we set the
  // new timestamp value.
  ACE_Time_Value prev_time = this->timestamp_;
  this->timestamp_i (timestamp);

  // Calculate the duration between time values.
  this->duration_ = prev_time - this->timestamp_;
}

//
// init_timestamp
//
void CUTS_System_Metric::
init_timestamp (const ACE_Time_Value * timestamp)
{
  this->timestamp_i (timestamp);
  this->duration_ = ACE_Time_Value::zero;
}

//
// timestamp_i
//
void CUTS_System_Metric::
timestamp_i (const ACE_Time_Value * timestamp)
{
  if (timestamp)
    this->timestamp_ = *timestamp;
  else
    this->timestamp_ = ACE_OS::gettimeofday ();
}

//
// operator +=
//
const CUTS_System_Metric & CUTS_System_Metric::
operator += (const CUTS_System_Metric & metric)
{
  // Add the <duration_> of the source metrics.
  this->duration_ += metric.duration_;

  CUTS_Component_Metric_Map::const_iterator iter;

  for (iter  = metric.component_metrics ().begin ();
       iter != metric.component_metrics ().end ();
       iter ++)
  {
    CUTS_Component_Metric * cmetric = this->component_metrics (iter->first);
    *cmetric += *iter->second;
  }

  return *this;
}
