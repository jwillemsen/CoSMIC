// -*- C++ -*-

//============================================================================
/**
 * @file    OperationRef.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_OPERATIONREF_H_
#define _PICML_COMPONENTBENCHMARK_OPERATIONREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OperationRef_Impl;
  typedef OperationRef_Impl * OperationRef_in;
  typedef ::GAME::Mga::Smart_Ptr < OperationRef_Impl > OperationRef;

  // Forward decl.
  class Visitor;

  /**
   * @class OperationRef_Impl
   *
   * Implementation for the OperationRef model element.
   */
  class PICML_Export OperationRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static OperationRef _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    OperationRef_Impl (void);

    // Initializing constructor.
    OperationRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~OperationRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src WorkLoadOperationConnection connection.
    size_t src_of_WorkLoadOperationConnection (std::vector <WorkLoadOperationConnection> & items) const;
    bool has_src_of_WorkLoadOperationConnection (void) const;
    WorkLoadOperationConnection src_of_WorkLoadOperationConnection (void) const;

    /// Get the src ComponentOperation connection.
    size_t src_of_ComponentOperation (std::vector <ComponentOperation> & items) const;
    bool has_src_of_ComponentOperation (void) const;
    ComponentOperation src_of_ComponentOperation (void) const;

    /// Get the src MetricConnection connection.
    size_t src_of_MetricConnection (std::vector <MetricConnection> & items) const;
    bool has_src_of_MetricConnection (void) const;
    MetricConnection src_of_MetricConnection (void) const;

    /// Get the src TimerConnection connection.
    size_t src_of_TimerConnection (std::vector <TimerConnection> & items) const;
    bool has_src_of_TimerConnection (void) const;
    TimerConnection src_of_TimerConnection (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool OperationBase_is_nil (void) const;
    OperationBase refers_to_OperationBase (void) const;
    void refers_to_OperationBase (OperationBase_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OperationRef.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_OPERATIONREF
