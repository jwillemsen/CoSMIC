// -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstance_Event_Handler.h
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_COMPONENT_INSTANCE_HANDLER_H_
#define _PICML_MI_COMPONENT_INSTANCE_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/Model.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

// Forward decl.
class Component_Observer_Event_Handler;

/**
 * @class ComponentInstance_Creator_Event_Handler
 *
 * Event handler for managing the creation and deletion of a
 * ComponentInstance in PICML.
 */
class ComponentInstance_Creator_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor.
  ComponentInstance_Creator_Event_Handler (Component_Observer_Event_Handler * observer);

  /// Destructor.
  virtual ~ComponentInstance_Creator_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
  virtual int handle_lost_child (GAME::Mga::Object_in obj);

private:
  /// Pointer to the component observer event handler.
  Component_Observer_Event_Handler * observer_;
};

}
}

#endif
