// $Id$

#include "cuts/Port_Agent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Agent.inl"
#endif

#include "cuts/Activation_Record.h"
#include "cuts/Activation_Record_Entry.h"
#include "cuts/Benchmark_Visitor.h"
#include "cuts/Port_Measurement.h"

#include <algorithm>

//=============================================================================
/**
 * struct Record_Record_Entry
 */
//=============================================================================

struct Record_Record_Entry
{
  Record_Record_Entry (CUTS_Port_Measurement * port_measurement)
    : port_measurement_ (port_measurement)
  {

  }

  void operator () (const CUTS_Activation_Record_Entry & entry)
  {
    this->port_measurement_->record_entry (
      entry.reps_,
      entry.worker_id_,
      entry.action_id_,
      entry.stop_time_ - entry.start_time_);
  }

private:
  CUTS_Port_Measurement * port_measurement_;
};

//=============================================================================
/*
 * class CUTS_Port_Agent
 */
//=============================================================================

//
// CUTS_Port_Agent
//
CUTS_Port_Agent::CUTS_Port_Agent (void)
: name_ ("unknown"),
  active_ (false),
  measurement_pool_ (2)
{

}

//
// ~CUTS_Port_Agent
//
CUTS_Port_Agent::~CUTS_Port_Agent (void)
{
  this->deactivate ();
}

//
// update
//
void CUTS_Port_Agent::
update (const CUTS_Activation_Record * record)
{
  // Get the current collection point in the mapping.
  CUTS_Port_Measurement_Map & pmmap = this->measurement_pool_.current ();

  // Locate the measurements for this owner. If we can not
  // find the records then we need to create a new entry for it.
  CUTS_Port_Measurement * measurement = 0;

  if (pmmap.find (record->owner (), measurement) == -1)
  {
    ACE_NEW (measurement, CUTS_Port_Measurement);

    if (measurement != 0)
    {
      if (pmmap.bind (record->owner (), measurement) != 0)
      {
        delete measurement;
        measurement = 0;
      }
    }
  }

  if (measurement != 0)
  {
    // Record the processing time for the activation record.
    measurement->process_time (record->stop_time () - record->start_time ());
    measurement->transit_time (record->queue_time ());

    // Record all the entries in the activation record.
    std::for_each (record->entries ().begin (),
                   record->entries ().end (),
                   Record_Record_Entry (measurement));

    // Transfer the collected endpoints to the port agent.
    CUTS_Activation_Record_Endpoints::const_iterator
      iter (record->endpoints ());

    while (!iter.done ())
    {
      ACE_Time_Value duration = iter->item () - record->start_time ();
      measurement->record_exit_point_time (iter->key (), duration);

      iter.advance ();
    }
  }
}

//
// accept
//
void CUTS_Port_Agent::accept (CUTS_Benchmark_Visitor & visitor)
{
  visitor.visit_port_agent (*this);
}
