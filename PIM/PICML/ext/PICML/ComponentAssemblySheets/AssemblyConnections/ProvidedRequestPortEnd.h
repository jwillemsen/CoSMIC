// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPortEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTEND_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPortEnd_Impl;
  typedef ProvidedRequestPortEnd_Impl * ProvidedRequestPortEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < ProvidedRequestPortEnd_Impl > ProvidedRequestPortEnd;

  /**
   * @class ProvidedRequestPortEnd_Impl
   *
   * Implementation for the ProvidedRequestPortEnd model element.
   */
  class PICML_Export ProvidedRequestPortEnd_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual ExternalPortEnd_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    ProvidedRequestPortEnd_Impl (void);

    // Initializing constructor.
    ProvidedRequestPortEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ProvidedRequestPortEnd_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ConnectorToFacet connection.
    size_t dst_ConnectorToFacet (std::vector <ConnectorToFacet> & items) const;

    /// Get the dst Invoke connection.
    size_t dst_Invoke (std::vector <Invoke> & items) const;

    /// Get the dst FacetDelegate connection.
    size_t dst_FacetDelegate (std::vector <FacetDelegate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ProvidedRequestPortEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_PROVIDEDREQUESTPORTEND