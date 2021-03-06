// -*- C++ -*-

//============================================================================
/**
 * @file    PredefinedType.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_PREDEFINEDTYPE_H_
#define _PICML_PREDEFINEDTYPES_PREDEFINEDTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/SimpleType.h"
#include "PICML/NamedTypes/MemberType.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PredefinedType_Impl;
  typedef PredefinedType_Impl * PredefinedType_in;
  typedef ::GAME::Mga::Smart_Ptr < PredefinedType_Impl > PredefinedType;

  /**
   * @class PredefinedType_Impl
   *
   * Implementation for the PredefinedType model element.
   */
  class PICML_Export PredefinedType_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual SimpleType_Impl,
    public virtual MemberType_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    PredefinedType_Impl (void);

    // Initializing constructor.
    PredefinedType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~PredefinedType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    PredefinedTypes parent_PredefinedTypes (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PredefinedType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_PREDEFINEDTYPE
