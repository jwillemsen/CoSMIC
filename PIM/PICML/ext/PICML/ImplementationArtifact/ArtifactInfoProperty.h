// -*- C++ -*-

//============================================================================
/**
 * @file    ArtifactInfoProperty.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTINFOPROPERTY_H_
#define _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTINFOPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactInfoProperty_Impl;
  typedef ArtifactInfoProperty_Impl * ArtifactInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < ArtifactInfoProperty_Impl > ArtifactInfoProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class ArtifactInfoProperty_Impl
   *
   * Implementation for the ArtifactInfoProperty model element.
   */
  class PICML_Export ArtifactInfoProperty_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactInfoProperty _create (const ArtifactContainer_in parent, ImplementationArtifact_in src, Property_in dst);
    ///@}

    // Default constructor.
    ArtifactInfoProperty_Impl (void);

    // Initializing constructor.
    ArtifactInfoProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ArtifactInfoProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ArtifactContainer parent_ArtifactContainer (void);
    ///@}
    ImplementationArtifact src_ImplementationArtifact (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ArtifactInfoProperty.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTINFOPROPERTY
