// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_algorithm.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_ALGORITHM_H_
#define _CUTS_BE_ALGORITHM_H_

#include "BE_nil.h"
#include <algorithm>

namespace CUTS_BE
{
  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then...else statements. This
   * template really has no implementation, and only exist because of the
   * specializations.
   */
  //=============================================================================

  template <bool CONDITION, typename TRUE_STMT, typename FALSE_STMT>
  struct if_then_else
  {

  };

  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then...else statements. This
   * is a specialization of the generalized template for when the CONDITION
   * parameter is \a true.
   */
  //=============================================================================

  template <typename TRUE_STMT, typename FALSE_STMT>
  struct if_then_else <true, TRUE_STMT, FALSE_STMT>
  {
    /// The result type for this specialization.
    typedef TRUE_STMT result_type;
  };

  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then...else statements. This
   * is a specialization of the generalized template for when the CONDITION
   * parameter is \a false.
   */
  //=============================================================================

  template <typename TRUE_STMT, typename FALSE_STMT>
  struct if_then_else <false, TRUE_STMT, FALSE_STMT>
  {
    /// The result type for this specialization.
    typedef FALSE_STMT result_type;
  };

  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then statements. This
   * trait utilizes the if_then_else trait for compile-time evaluation.
   */
  //=============================================================================

  template <bool CONDITION, typename TRUE_STMT>
  struct if_then
  {
    /// Result type for this metaprogrammable template.
    typedef typename if_then_else <CONDITION,
                                   TRUE_STMT,
                                   CUTS_BE::NIL>::result_type result_type;
  };

  //=============================================================================
  /**
   * @struct visit_type
   *
   * Trait that determines if a strategy will (or will not) visit an
   * object. The default behavior is to visit all the elements handled
   * by the interpretation-logic. To alter this behavior, this class
   * must be specialized by the \a STRATEGY for each \a TYPE it does
   * not want to visit.
   */
  //=============================================================================

  template <typename STRATEGY, typename TYPE>
  struct visit_type
  {
    /// The result type for the visitation.
    static const bool result_type = true;
  };

/// Helper macro for defining the trait to ingore a single type
/// when parsing the model.
#define CUTS_BE_NO_VISIT(strategy, type) \
  template <typename STRATEGY, typename TYPE> \
  struct visit_type \
  { \
    static const bool result_type = false; \
  }

/// Helper macro for defining the trait to ingore all types
/// when parsing the model.
#define CUTS_BE_NO_VISIT_ALL(strategy) \
  template <typename TYPE> \
  struct visit_type <strategy, TYPE> \
  { \
    static const bool result_type = false; \
  }

  //=============================================================================
  /**
   * @struct iterate_all
   *
   * Implementation of the std::for_each method. This functor conforms it
   * to the function signature expected by the metaprogrammable templates.
   */
  //=============================================================================

  template <typename COLLECTION, typename FUNCTOR>
  struct iterate_all
  {
    /**
     * Execute the functor's logic.
     *
     * @param[in]     coll        The target collection.
     * @param[in]     func        The functor.
     */
    static inline void execute (COLLECTION & coll, FUNCTOR func)
      { std::for_each (coll.begin (), coll.end (), func); }
  };

  //=============================================================================
  /**
   * @struct generate
   *
   * Metaprogrammable template that determines if a \a STRATEGY_GENERATOR
   * should be invoked. If the \a STRATEGY_GENERATOR is not NIL,
   * then it will be invoked. Otherwise, it will be ignored (or suppressed).
   */
  //=============================================================================

  template <typename STRATEGY_GENERATOR>
  inline bool generate (void)
  {
    /// Result type for this metaprogrammable template.
    typedef typename
      CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>::result_type,
                        STRATEGY_GENERATOR>::result_type result_type;

    return result_type::generate ();
  };

  // 1-parameter specialization
  template <typename STRATEGY_GENERATOR,
            typename P1>
  inline bool generate (P1 p1)
  {
    /// Result type for this metaprogrammable template.
    typedef typename
      CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>::result_type,
                        STRATEGY_GENERATOR>::result_type result_type;

    return result_type::generate (p1);
  };

  // 2-parameter specialization
  template <typename STRATEGY_GENERATOR,
            typename P1, typename P2>
  inline bool generate (P1 p1, P2 p2)
  {
    /// Result type for this metaprogrammable template.
    typedef typename
      CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>::result_type,
                        STRATEGY_GENERATOR>::result_type result_type;

    return result_type::generate (p1, p2);
  };

  // 3-parameter specialization
  template <typename STRATEGY_GENERATOR,
            typename P1, typename P2, typename P3>
  inline bool generate (P1 p1, P2 p2, P3 p3)
  {
    /// Result type for this metaprogrammable template.
    typedef typename
      CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>::result_type,
                        STRATEGY_GENERATOR>::result_type result_type;

    return result_type::generate (p1, p2, p3);
  };

  // 4-parameter specialization
  template <typename STRATEGY_GENERATOR,
            typename P1, typename P2, typename P3, typename P4>
  inline bool generate (P1 p1, P2 p2, P3 p3, P4 p4)
  {
    /// Result type for this metaprogrammable template.
    typedef typename
      CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>::result_type,
                        STRATEGY_GENERATOR>::result_type result_type;

    return result_type::generate (p1, p2, p3, p4);
  };

  // 5-parameter specialization
  template <typename STRATEGY_GENERATOR,
            typename P1, typename P2, typename P3, typename P4, typename P5>
  inline bool generate (P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
  {
    /// Result type for this metaprogrammable template.
    typedef typename
      CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>::result_type,
                        STRATEGY_GENERATOR>::result_type result_type;

    return result_type::generate (p1, p2, p3, p4, p5);
  };
}

#endif  // !defined _CUTS_BE_ALGORITHM_H_
