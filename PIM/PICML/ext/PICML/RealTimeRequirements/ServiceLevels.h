// -*- C++ -*-

//============================================================================
/**
 * @file    ServiceLevels.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_SERVICELEVELS_H_
#define _PICML_REALTIMEREQUIREMENTS_SERVICELEVELS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ServiceLevels_Impl;
  typedef ServiceLevels_Impl * ServiceLevels_in;
  typedef ::GAME::Mga::Smart_Ptr < ServiceLevels_Impl > ServiceLevels;

  // Forward decl.
  class Visitor;

  /**
   * @class ServiceLevels_Impl
   *
   * Implementation for the ServiceLevels model element.
   */
  class PICML_Export ServiceLevels_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ServiceLevels _create (const ServiceProvider_in parent);
    ///@}

    // Default constructor.
    ServiceLevels_Impl (void);

    // Initializing constructor.
    ServiceLevels_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ServiceLevels_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ServiceProvider parent_ServiceProvider (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of varying_service_levels
    void varying_service_levels (bool val);

    /// Get the value of varying_service_levels
    bool varying_service_levels (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ServiceLevels.inl"
#endif

#endif  // !defined _PICML_REALTIMEREQUIREMENTS_SERVICELEVELS