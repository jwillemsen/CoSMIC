// -*- C++ -*-
// $Id$

//
// CUTS_Port_Measurement_Map
//
CUTS_INLINE
CUTS_Port_Measurement_Map::CUTS_Port_Measurement_Map (void)
{

}

//
// ~CUTS_Port_Measurement_Map
//
CUTS_INLINE
CUTS_Port_Measurement_Map::~CUTS_Port_Measurement_Map (void)
{
  this->empty ();
}

//
// size
//
CUTS_INLINE
size_t CUTS_Port_Measurement_Map::size (void) const
{
  return this->hash_map_.current_size ();
}

//
// hash_map
//
CUTS_INLINE
const CUTS_Port_Measurement_Map::hash_map_t &
CUTS_Port_Measurement_Map::hash_map (void) const
{
  return this->hash_map_;
}
