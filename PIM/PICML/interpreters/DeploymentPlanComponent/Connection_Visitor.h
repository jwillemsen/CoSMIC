// -*- C++ -*-

//=============================================================================
/**
 * @file        Connection_Visitor.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_DEPLOYMENT_CONNECTION_VISITOR_H_
#define _PICML_DEPLOYMENT_CONNECTION_VISITOR_H_

#include "PICML/PICML.h"
#include "XML_Document.h"

/**
 * @class DeploymentPlanVisitor
 */
class Connection_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  /**
   * Initializing constructor.
   */
  Connection_Visitor (xercesc::DOMDocument * doc,
                      std::vector <xercesc::DOMElement *> & conns,
                      const std::map <PICML::ComponentInstance, xercesc::DOMElement *> & insts);

  /// Destructor.
  virtual ~Connection_Visitor (void);

  virtual void Visit_ComponentInstance (const PICML::ComponentInstance &);

  virtual void Visit_ProvidedRequestPortInstance (const PICML::ProvidedRequestPortInstance &);

  virtual void Visit_RequiredRequestPortInstance (const PICML::RequiredRequestPortInstance &);

  virtual void Visit_OutEventPortInstance ( PICML::OutEventPortInstance & );

  virtual void Visit_InEventPortInstance (const PICML::InEventPortInstance & sink);

  virtual void Visit_Invoke (const PICML::Invoke &);

  virtual void Visit_SendsTo (const PICML::SendsTo & sends);

  virtual void Visit_ReceptacleDelegate (const PICML::ReceptacleDelegate &);

  virtual void Visit_RequiredRequestPortDelegate (const PICML::RequiredRequestPortDelegate &);

  virtual void Visit_FacetDelegate (const PICML::FacetDelegate &);

  virtual void Visit_ProvidedRequestPortDelegate (const PICML::ProvidedRequestPortDelegate &);

  virtual void Visit_EventSourceDelegate (const PICML::EventSourceDelegate &);

  virtual void Visit_OutEventPortDelegate (const PICML::OutEventPortDelegate &);

  virtual void Visit_EventSinkDelegate (const PICML::EventSinkDelegate &);

  virtual void Visit_InEventPortDelegate (const PICML::InEventPortDelegate &);

  const std::vector <xercesc::DOMElement *> & connections (void) const;

private:
  /// Helper method for creating a connection.
  void create_connection (const std::string & name,
                          xercesc::DOMNode * e1,
                          xercesc::DOMNode * e2,
                          bool is_local);

  void make_local_connection (xercesc::DOMElement * conn);

  /// The target document.
  xercesc::DOMDocument * doc_;

  /// Set of connection gathered.
  std::vector <xercesc::DOMElement *> & conns_;

  /// Set of deployed instances.
  const std::map <PICML::ComponentInstance, xercesc::DOMElement *> & insts_;

  PICML::ComponentInstance inst_;

  std::string name_;

  xercesc::DOMElement * endpoint_;
};

#endif  // !defined _PICML_DEPLOYMENT_CONNECTION_VISITOR_H_