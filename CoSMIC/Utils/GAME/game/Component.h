// -*- C++ -*-

//=============================================================================
/**
 * @file      Component.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_COMPONENT_H_
#define _GME_COMPONENT_H_

#include "Project.h"

#if !defined (__ComponentLib_h__)
#include "Mga.h"
#endif

namespace GAME
{
/**
 * @class Component
 *
 * Wrapper class for GME components.
 */
class GAME_Export Component
{
public:
  /// Type definition of the interface type.
  typedef IMgaComponent interface_type;

  /**
   * Load a component with the specified program id. This is useful
   * when automating a interpreter from another client application.
   *
   * @param[in]   progid      Program id of the component.
   */
  static Component _load (const std::string & progid);

  /// Default constructor.
  Component (void);

  /**
   * Copy constructor
   *
   * @param[in]   c           The source component
   */
  Component (const Component & c);

  /// Destructor
  virtual ~Component (void);

  /**
   * Initialize the component.
   *
   * @param[in]   project     The target project.
   */
  void initialize (GAME::Project & project);

  bool interative (void) const;
  void interative (bool flag);

  /**
   * Get the name of the component.
   *
   * @return      The name of the component.
   */
  std::string name (void) const;

  /**
   * Get the component's type.
   *
   * @return      The type of the component.
   */
  componenttype_enum type (void) const;

  /**
   * Get the name(s) of the paradigms to which the component is
   * registered.
   *
   * @return      The names of the paradigm.
   */
  std::string registered_paradigm (void) const;

  /**
   * Invoke the interpreter.
   *
   * @param[in]     project       The project to interpret.
   * @param[in]     selected      Collection of selected FCOs.
   * @param[in]     param         User-defined parameter.
   */
  void invoke (Project & project, std::vector <FCO> & selected, long param);

  /// Explicitly release the component.
  void release (void);

  /// Attach to the specified inteface.
  void attach (IMgaComponent * c);

  virtual IMgaComponent * operator -> (void) const;

protected:
  /// The underlying component interface.
  ATL::CComPtr <IMgaComponent> component_;
};

}

#endif  // !defined _GME_COMPONENT_H_
