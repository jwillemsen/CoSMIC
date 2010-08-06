// -*- C++ -*-

//=============================================================================
/**
 *  @file       ToConnector_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_TO_CONNECTOR_EVENT_HANDLER_H_
#define _PICML_MI_TO_CONNECTOR_EVENT_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"

namespace PICML
{
namespace MI
{
/**
 * Implementation of the FacetToConnector event handlers. It's
 * main purpose to the assist the modeler in completing the
 * name of the connection, which represents the target port.
 */
class ToConnector_Event_Handler : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  ToConnector_Event_Handler (void);

  /// Destructor.
  virtual ~ToConnector_Event_Handler (void);

  virtual int handle_xml_import_begin (void);
  virtual int handle_xml_import_end (void);

protected:
  int create_connection (GAME::Object obj,
                         const std::string & port_role,
                         const std::string & connector_role,
                         const std::string & target_port_type);

private:
  bool get_connector_object (const GAME::Model & inst, GAME::Model & conobj);

  void get_matching_ports (const GAME::Model & connector,
                           const GAME::Model & object,
                           const std::string & type,
                           std::vector <GAME::Reference> & ports);

  void get_matching_inner_ports (const GAME::Reference & extended,
                                 const GAME::Model & object,
                                 const std::string & type,
                                 std::vector <GAME::Reference> & ports);

  bool is_importing_;
};

/**
 * Implementation of the FacetToConnector event handlers. It's main
 * purpose to the assist the modeler in completing the name of the
 * connection, which represents the target port.
 */
class FacetToConnector_Event_Handler :
  public ToConnector_Event_Handler
{
public:
  /// Default constructor.
  FacetToConnector_Event_Handler (void);

  /// Destructor.
  virtual ~FacetToConnector_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);
};

/**
 * Implementation of the FacetToConnector event handlers. It's main
 * purpose to the assist the modeler in completing the name of the
 * connection, which represents the target port.
 */
class ReceptacleToConnector_Event_Handler :
  public ToConnector_Event_Handler
{
public:
  /// Default constructor.
  ReceptacleToConnector_Event_Handler (void);

  /// Destructor.
  virtual ~ReceptacleToConnector_Event_Handler (void);

  virtual int handle_object_created (GAME::Object obj);
};

}
}

#endif  // !defined _PICML_MI_FACET_TO_CONNECTOR_EVENT_HANDLER_H_
