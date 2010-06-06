/* -*- C++ -*- */

//=============================================================================
/**
 * @file      RawComponent.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef RAWCOMPONENT_H
#define RAWCOMPONENT_H

#ifdef BUILDER_OBJECT_NETWORK
#error   This file should only be included in the RAW COM configurations
#endif

#include "game/GME.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include <set>

/**
 * @class RawComponent
 *
 * Raw COM implementation of the PICML manager add-on.
 */
class RawComponent
{
public:
  /// Constructor.
  RawComponent (void);

  /// Destructor.
  virtual ~RawComponent (void);

  /* GME specific members */
  CComPtr <IMgaAddOn> addon;
  bool interactive;

  /* RawComponent specific methods */
  STDMETHODIMP Initialize (struct IMgaProject *);
  STDMETHODIMP Invoke (IMgaProject*, IMgaFCOs *, long );
  STDMETHODIMP InvokeEx (IMgaProject *, IMgaFCO *, IMgaFCOs *, long);
  STDMETHODIMP ObjectsInvokeEx (IMgaProject *, IMgaObject *, IMgaObjects *, long);
  STDMETHODIMP get_ComponentParameter (BSTR, VARIANT *);
  STDMETHODIMP put_ComponentParameter (BSTR, VARIANT);
  STDMETHODIMP GlobalEvent (globalevent_enum);
  STDMETHODIMP ObjectEvent (IMgaObject *, unsigned long, VARIANT);

private:
  void handle_AttributeMember (unsigned long eventmask, GAME::Object & obj);
  void handle_AttributeValue (unsigned long eventmask, GAME::Object & obj);
  void handle_ExternalDelegate (unsigned long eventmask, GAME::Object & obj);
  void handle_PublishConnector (unsigned long eventmask, GAME::Object & obj);
  void handle_DeploymentPlan (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentAssembly (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentPackage (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentRef (unsigned long eventmask, GAME::Object & obj);

  void handle_ConnectorObject (unsigned long eventmask, GAME::Object & obj);
  void handle_Component (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentInstance (unsigned long eventmask, GAME::Object & obj);
  void handle_ConnectorInstance (unsigned long eventmask, GAME::Object & obj);

  void handle_ComponentFactoryInstance (unsigned long eventmask, GAME::Object & obj);
  void handle_Domain (unsigned long eventmask, GAME::Object & obj);
 
  void handle_MonolithicImplementation (unsigned long eventmask, GAME::Object & obj);
  void handle_ConnectorImplementation (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentImplementation (unsigned long eventmask, GAME::Object & obj);

  void handle_ImplementationArtifact (unsigned long eventmask, GAME::Object & obj);
  void handle_PackageConfiguration (unsigned long eventmask, GAME::Object & obj);
  void handle_NodeReference (unsigned long eventmask, GAME::Object & obj);
  void handle_CollocationGroup (unsigned long eventmask, GAME::Object & obj);
  void handle_ComponentInstanceType (unsigned long eventmask, GAME::Object & obj);
  void handle_UUID (unsigned long eventmask, GAME::FCO & fco);

  /**
   * Create a UUID for the FCO.
   *
   * @param[in]       fco         Target FCO.
   */
  void create_uuid (const GAME::FCO & fco);

  /**
   * Verify the UUID of an FCO.
   *
   * @param[in]       fco         Target FCO.
   */
  void verify_uuid (const GAME::FCO & fco);

  /// This verifies all UUID's in the project.
  void verify_all_uuids (void);

  void handle_pending (void);

  /**
   * Get the UUID from a FCO object.
   *
   * @param[in]     fco       Source FCO
   * @param[out]    attr      Pointer to the UUID attribute.
   * @retval        true      The attribute was found.
   * @retval        false     The attribute was not found.
   */
  bool get_uuid_i (const GAME::FCO & fco,
                   GAME::Attribute & attr);

  static void set_property_datatype (GAME::Model & property,
                                     const GAME::FCO & type);

  static void verify_property_datatype (GAME::ConnectionPoint & attr,
                                        const GAME::FCO & attr_type);

  static void verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
                                              const GAME::FCO & attr_type);

  /// The project is in import mode.
  int importing_;

  /// Collection of pending FCO's to validate.
  std::vector <GAME::FCO> pending_;

  /// Interface pointer to the hosting project.
  GAME::Project project_;

  /// PICML types with a UUID attribute.
  std::set <std::string> uuid_types_;

  typedef
    void (RawComponent::*_member_function) (unsigned long,
                                            GAME::Object &);

  ACE_Hash_Map_Manager <std::string,
                        _member_function,
                        ACE_Null_Mutex> handlers_;

  /// Latest member of the collocation group.
  GAME::FCO cg_member_;
};


#endif /* RAWCOMPONENT_H */
