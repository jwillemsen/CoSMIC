// -*- C++ -*-

//============================================================================
/**
 * @file    WhileState.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_WHILESTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_WHILESTATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WhileState_Impl;
  typedef WhileState_Impl * WhileState_in;
  typedef ::GAME::Mga::Smart_Ptr < WhileState_Impl > WhileState;

  // Forward decl.
  class Visitor;

  /**
   * @class WhileState_Impl
   *
   * Implementation for the WhileState model element.
   */
  class PICML_Export WhileState_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual LoopState_Impl
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

    /**
     * @name Factory Methods
     */
    ///@{
    static WhileState _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    WhileState_Impl (void);

    // Initializing constructor.
    WhileState_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~WhileState_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WhileState.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_WHILESTATE
