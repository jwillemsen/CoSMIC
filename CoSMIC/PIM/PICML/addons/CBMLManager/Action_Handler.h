// -*- C++ -*-

//=============================================================================
/**
 * @file        Action_Handler.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CBML_ACTION_HANDLER_H_
#define _CBML_ACTION_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"

/**
 * @class CBML_Output_Action_Handler
 *
 * Handler that is responsible for generating connections that
 * connect with the State element.
 */
class CBML_Action_Handler :
  public GAME::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  CBML_Action_Handler (void);

  /// Destructor.
  virtual ~CBML_Action_Handler (void);

  virtual int handle_object_created (GAME::Object obj);

private:
  bool get_worker_type (const GAME::Model & component,
                        GAME::Reference & worker_type);
};

#endif  // !defined _CBML_CONNECTION_GENERATION_HANDLER_H_