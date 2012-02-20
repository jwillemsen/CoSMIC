// -*- C++ -*-
// $Id$

///////////////////////////////////////////////////////////////////////////////
// Source_Connection_Endpoint_Visitor

//
// Source_Connection_Endpoint_Visitor
//
GAME_INLINE
Source_Connection_Endpoint_Visitor::
Source_Connection_Endpoint_Visitor (GAME::Mga::FCO_in dst, std::set <GAME::Mga::Atom> & items)
: dst_ (dst),
  items_ (items)
{

}

//
// ~Source_Connection_Endpoint_Visitor
//
GAME_INLINE
Source_Connection_Endpoint_Visitor::~Source_Connection_Endpoint_Visitor (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// Destination_Connection_Endpoint_Visitor

//
// Destination_Connection_Endpoint_Visitor
//
GAME_INLINE
Destination_Connection_Endpoint_Visitor::
Destination_Connection_Endpoint_Visitor (GAME::Mga::FCO_in src, std::set <GAME::Mga::Atom> & items)
: src_ (src),
  items_ (items)
{

}

//
// ~Destination_Connection_Endpoint_Visitor
//
GAME_INLINE
Destination_Connection_Endpoint_Visitor::~Destination_Connection_Endpoint_Visitor (void)
{

}
