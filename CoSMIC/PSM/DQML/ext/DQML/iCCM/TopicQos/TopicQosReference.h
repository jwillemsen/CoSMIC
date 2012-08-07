// -*- C++ -*-

//============================================================================
/**
 * @file    TopicQosReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_TOPICQOS_TOPICQOSREFERENCE_H_
#define _DQML_ICCM_TOPICQOS_TOPICQOSREFERENCE_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Reference.h"

namespace DQML
{
  // Forward decl. and type definitions
  class TopicQosReference_Impl;
  typedef TopicQosReference_Impl * TopicQosReference_in;
  typedef ::GAME::Mga::Smart_Ptr < TopicQosReference_Impl > TopicQosReference;

  // Forward decl.
  class Visitor;

  /**
   * @class TopicQosReference_Impl
   *
   * Implementation for the TopicQosReference model element.
   */
  class DQML_Export TopicQosReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static TopicQosReference _create (const DataWriterQos_in parent);
    static TopicQosReference _create (const DataReaderQos_in parent);
    ///@}

    // Default constructor.
    TopicQosReference_Impl (void);

    // Initializing constructor.
    TopicQosReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~TopicQosReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Refers To Methods
     */
    ///@{
    bool TopicQos_is_nil (void) const;
    TopicQos get_TopicQos (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopicQosReference.inl"
#endif

#endif  // !defined _DQML_ICCM_TOPICQOS_TOPICQOSREFERENCE