// $Id$

#include "cuts/Port_Metric.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Metric.inl"
#endif

#include "cuts/Time_Metric.h"

//
// CUTS_Port_Metric
//
CUTS_Port_Metric::CUTS_Port_Metric (void)
{

}

//
// ~CUTS_Port_Metric
//
CUTS_Port_Metric::~CUTS_Port_Metric (void)
{
  for (End_Point_Metrics::iterator iter = this->endpoints_.begin ();
       iter != this->endpoints_.end ();
       iter ++)
  {
    delete iter->second;
  }
}

//
// insert_endpoint
//
CUTS_Time_Metric * CUTS_Port_Metric::insert_endpoint (const char * endpoint)
{
  CUTS_Time_Metric * metric = 0;
  ACE_NEW_RETURN (metric, CUTS_Time_Metric (), false);

  std::pair <End_Point_Metrics::iterator, bool> result;

  do {
    ACE_WRITE_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, false);
    result =
      this->endpoints_.insert (
      End_Point_Metrics::value_type (endpoint, metric));
  } while (false);

  if (!result.second)
  {
    delete metric;
    metric = result.first->second;
  }

  return metric;
}

//
// remove_endpoint
//
void CUTS_Port_Metric::remove_endpoint (const char * endpoint)
{
  ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, this->lock_);
  this->endpoints_.erase (endpoint);
}

//
// time_metric
//
CUTS_Time_Metric * CUTS_Port_Metric::endpoint (const char * endpoint)
{
  CUTS_Time_Metric * metric = 0;
  End_Point_Metrics::iterator result;

  do {
    // Locate the endpoint in the mapping.
    ACE_READ_GUARD_RETURN (ACE_RW_Thread_Mutex, guard, this->lock_, 0);
    result = this->endpoints_.find (endpoint);
  } while (false);

  if (result != this->endpoints_.end ())
  {
    // Save the located endpoint.
    metric = result->second;
  }
  else
  {
    // Since we could not locate it, we have to create a new one.
    metric = insert_endpoint (endpoint);
  }

  return metric;
}