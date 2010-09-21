// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstance_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_INSTANCE_HANDLER_H_
#define _PICML_MI_COMPONENT_INSTANCE_HANDLER_H_

#include "game/GAME.h"
#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

/**
 * @class ComponentInstance_Event_Handler
 *
 * Event handler for managing the functionality of a ComponentInstance
 * in PICML.
 */
class ComponentInstance_Event_Handler : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ComponentInstance_Event_Handler (void);

  /// Destructor.
  virtual ~ComponentInstance_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);

  virtual int handle_lost_child (GAME::Object obj);
};

}
}

#endif