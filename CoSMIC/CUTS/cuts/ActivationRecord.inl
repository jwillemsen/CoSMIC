// $Id$

//
// start_time
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Activation_Record::start_time (void) const
{
  return this->start_time_;
}

//
// stop_time
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Activation_Record::stop_time (void) const
{
  return this->stop_time_;
}

//
// close
//
CUTS_INLINE
void CUTS_Activation_Record::close (void)
{
  this->stop_time_ = ACE_OS::gettimeofday ();
  this->active_ = false;
}

//
// entries
//
CUTS_INLINE
const CUTS_Activation_Record::Entries &
CUTS_Activation_Record::entries (void) const
{
  return this->entries_;
}

//
// log_time_measurement
//
CUTS_INLINE
void CUTS_Activation_Record::log_time_measurement (size_t reps,
                                                   long worker_id,
                                                   long action_id)
{
  this->entries_.push (
    Entry (reps, worker_id, action_id,
    this->action_state_time_, this->action_stop_time_));
}

//
// reset
//
CUTS_INLINE
void CUTS_Activation_Record::reset (void)
{
  this->entries_.c.clear ();
}

//
// activate
//
CUTS_INLINE
void CUTS_Activation_Record::activate (void)
{
  this->start_time_ = ACE_OS::gettimeofday ();
  this->active_ = true;
}
