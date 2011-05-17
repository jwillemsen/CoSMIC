// -*- C++ -*-

//============================================================================
/**
 * @file    ComplexType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_COMPLEXTYPE_H_
#define _PICML_COMMON_COMPLEXTYPE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComplexType_Impl;
  typedef ComplexType_Impl * ComplexType_in;
  typedef ::GAME::Mga::Smart_Ptr <ComplexType_Impl> ComplexType;

  class PICML_Export ComplexType_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComplexType_Impl (void);

    /// Initializing constructor
    ComplexType_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~ComplexType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif