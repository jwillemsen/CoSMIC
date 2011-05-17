// -*- C++ -*-

//============================================================================
/**
 * @file    ApplicationTask.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_APPLICATIONTASK_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_INPUTHOOKS_APPLICATIONTASK_H_

#include "game/mga/Atom.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ApplicationTask_Impl;
  typedef ApplicationTask_Impl * ApplicationTask_in;
  typedef ::GAME::Mga::Smart_Ptr <ApplicationTask_Impl> ApplicationTask;

  // Forward decl.
  class Visitor;

  class PICML_Export ApplicationTask_Impl :
    public virtual SingleInputBase_Impl,
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ApplicationTask_Impl (void);

    /// Initializing constructor
    ApplicationTask_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ApplicationTask_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

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