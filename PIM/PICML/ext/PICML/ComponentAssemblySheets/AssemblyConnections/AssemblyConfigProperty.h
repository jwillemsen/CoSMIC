// -*- C++ -*-

//============================================================================
/**
 * @file    AssemblyConfigProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTY_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AssemblyConfigProperty_Impl;
  typedef AssemblyConfigProperty_Impl * AssemblyConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < AssemblyConfigProperty_Impl > AssemblyConfigProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class AssemblyConfigProperty_Impl
   *
   * Implementation for the AssemblyConfigProperty model element.
   */
  class PICML_Export AssemblyConfigProperty_Impl :
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
    static AssemblyConfigProperty _create (const ComponentAssembly_in parent, AssemblyConfigPropertyEnd_in src, Property_in dst);
    ///@}

    // Default constructor.
    AssemblyConfigProperty_Impl (void);

    // Initializing constructor.
    AssemblyConfigProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~AssemblyConfigProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    AssemblyConfigPropertyEnd src_AssemblyConfigPropertyEnd (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "AssemblyConfigProperty.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTY
