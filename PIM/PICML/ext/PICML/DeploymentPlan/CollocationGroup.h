// -*- C++ -*-

//============================================================================
/**
 * @file    CollocationGroup.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUP_H_
#define _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUP_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Set.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollocationGroup_Impl;
  typedef CollocationGroup_Impl * CollocationGroup_in;
  typedef ::GAME::Mga::Smart_Ptr < CollocationGroup_Impl > CollocationGroup;

  // Forward decl.
  class Visitor;

  /**
   * @class CollocationGroup_Impl
   *
   * Implementation for the CollocationGroup model element.
   */
  class PICML_Export CollocationGroup_Impl :
    public virtual ::GAME::Mga::Set_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::set_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaSet interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static CollocationGroup _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    CollocationGroup_Impl (void);

    // Initializing constructor.
    CollocationGroup_Impl (IMgaSet * ptr);

    // Destructor.
    virtual ~CollocationGroup_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlan parent_DeploymentPlan (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src InstanceMapping connection.
    size_t src_of_InstanceMapping (std::vector <InstanceMapping> & items) const;
    bool has_src_of_InstanceMapping (void) const;
    InstanceMapping src_of_InstanceMapping (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst CollocationGroupProperty connection.
    size_t dst_of_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const;
    GAME::Mga::Collection_T <CollocationGroupProperty> dst_of_CollocationGroupProperty (void) const;
    ///@}

    /**
     * @name Set Member Getters
     */
    ///@{

    ::GAME::Mga::Collection_T <CollocationGroupMember> members_CollocationGroupMember (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CollocationGroup.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUP
