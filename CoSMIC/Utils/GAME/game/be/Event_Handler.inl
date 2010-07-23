// $Id$

#include "Event_Handler_Impl.h"

namespace GAME
{
//
// Event_Handler
//
GAME_INLINE
Event_Handler::Event_Handler (Event_Handler_Impl * impl)
: impl_ (impl),
  enable_ (true)
{

}

//
// ~Event_Handler
//
GAME_INLINE
Event_Handler::~Event_Handler (void)
{

}

//
// attach
//
GAME_INLINE
void Event_Handler::attach (Event_Handler_Impl * impl)
{
  this->impl_ = impl;
}


//
// enable
//
GAME_INLINE
void Event_Handler::enable (bool state)
{
  this->enable_ = state;
}

}
