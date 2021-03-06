// -*- C++ -*-

//============================================================================
/**
 * @file    CallAction.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_CALLACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_CALLACTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CallAction_Impl;
  typedef CallAction_Impl * CallAction_in;
  typedef ::GAME::Mga::Smart_Ptr < CallAction_Impl > CallAction;

  // Forward decl.
  class Visitor;

  /**
   * @class CallAction_Impl
   *
   * Implementation for the CallAction model element.
   */
  class PICML_Export CallAction_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ActionBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static CallAction _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    CallAction_Impl (void);

    // Initializing constructor.
    CallAction_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~CallAction_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_TargetRequiredRequestPort (void) const;
    TargetRequiredRequestPort get_TargetRequiredRequestPort (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CallAction.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_CALLACTION
