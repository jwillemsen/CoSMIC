// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorImplements.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTS_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorImplements_Impl;
  typedef ConnectorImplements_Impl * ConnectorImplements_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorImplements_Impl > ConnectorImplements;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorImplements_Impl
   *
   * Implementation for the ConnectorImplements model element.
   */
  class PICML_Export ConnectorImplements_Impl :
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
    static ConnectorImplements _create (const ConnectorImplementationContainer_in parent, ConnectorImplementation_in src, ConnectorType_in dst);
    ///@}

    // Default constructor.
    ConnectorImplements_Impl (void);

    // Initializing constructor.
    ConnectorImplements_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ConnectorImplements_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementationContainer parent_ConnectorImplementationContainer (void);
    ///@}
    ConnectorImplementation src_ConnectorImplementation (void) const;
    ConnectorType dst_ConnectorType (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorImplements.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORIMPLEMENTS
