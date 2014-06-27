// -*- C++ -*-

//============================================================================
/**
 * @file    GroupDataQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_GROUPDATAQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_GROUPDATAQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class GroupDataQosPolicy_Impl;
  typedef GroupDataQosPolicy_Impl * GroupDataQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < GroupDataQosPolicy_Impl > GroupDataQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class GroupDataQosPolicy_Impl
   *
   * Implementation for the GroupDataQosPolicy model element.
   */
  class DQML_Export GroupDataQosPolicy_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual QoSPolicy_Impl
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
    static GroupDataQosPolicy _create (const PublisherQos_in parent);
    static GroupDataQosPolicy _create (const SubscriberQos_in parent);
    static GroupDataQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    GroupDataQosPolicy_Impl (void);

    // Initializing constructor.
    GroupDataQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~GroupDataQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PublisherQos parent_PublisherQos (void);
    SubscriberQos parent_SubscriberQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of datavalue
    void datavalue (const std::string & val);

    /// Get the value of datavalue
    std::string datavalue (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst pub_groupdata_Connection connection.
    size_t dst_pub_groupdata_Connection (std::vector <pub_groupdata_Connection> & items) const;

    /// Get the dst sub_groupdata_Connection connection.
    size_t dst_sub_groupdata_Connection (std::vector <sub_groupdata_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "GroupDataQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_GROUPDATAQOSPOLICY