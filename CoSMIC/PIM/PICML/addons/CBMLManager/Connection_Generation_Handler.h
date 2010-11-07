// -*- C++ -*-

//=============================================================================
/**
 * @file        Connection_Generation_Handler.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CBML_CONNECTION_GENERATION_HANDLER_H_
#define _CBML_CONNECTION_GENERATION_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"
#include "game/FCO.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

/**
 * @class CBML_Connection_Generation_Handler
 *
 * Handler that is responsible for generating connections that
 * connect with the State element.
 */
class CBML_Connection_Generation_Handler :
  public GAME::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_SELECT |
                                         OBJEVENT_CREATED |
                                         OBJEVENT_DESTROYED;

  /// Default constructor.
  CBML_Connection_Generation_Handler (void);

  /// Destructor.
  virtual ~CBML_Connection_Generation_Handler (void);

  virtual int handle_object_created (GAME::Object obj);

  virtual int handle_object_destroyed (GAME::Object obj);

  virtual int handle_object_select (GAME::Object obj);

private:
  void create_state_and_connect (GAME::FCO action,
                                 const std::string & conntype);

  /// The active state.
  GAME::FCO active_state_;

  ACE_Hash_Map_Manager <ACE_CString,
                        std::string,
                        ACE_Null_Mutex> state_transition_map_;

};

#endif  // !defined _CBML_CONNECTION_GENERATION_HANDLER_H_