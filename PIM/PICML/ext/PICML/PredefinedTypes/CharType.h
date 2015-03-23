// -*- C++ -*-

//============================================================================
/**
 * @file    CharType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_CHARTYPE_H_
#define _PICML_PREDEFINEDTYPES_CHARTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CharType_Impl;
  typedef CharType_Impl * CharType_in;
  typedef ::GAME::Mga::Smart_Ptr < CharType_Impl > CharType;

  /**
   * @class CharType_Impl
   *
   * Implementation for the CharType model element.
   */
  class PICML_Export CharType_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual PredefinedType_Impl,
    public virtual ConstantType_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    CharType_Impl (void);

    // Initializing constructor.
    CharType_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~CharType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CharType.inl"
#endif

#endif  // !defined _PICML_PREDEFINEDTYPES_CHARTYPE
