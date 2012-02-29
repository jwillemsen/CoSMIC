// -*- C++ -*-

//=============================================================================
/**
 *  @file           modelgen.h
 *
 *  $Id$
 *
 *  @author         James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_MODELGEN_H_
#define _GAME_MGA_MODELGEN_H_

#include "game/mga/utils/modelgen.h"

namespace GAME
{
/// Tag definition for the MGA architecture.
struct Mga_t;

/**
 * Specialization of the get_chilren () method for the modelgen
 * framework.
 */
template < >
struct get_children <Mga_t>
{
public:
  template <typename P, typename T, typename META>
  size_t operator () (P parent, const META & metaname, T & element);

private:
  template <bool is_folder, typename P, typename T, typename META>
  struct get_children_impl;

  template <typename P, typename T, typename META>
  struct get_children_impl <true, P, T, META>
  {
    size_t operator () (P parent, const META & metaname, T & element);
  };

  template <typename P, typename T, typename META>
  struct get_children_impl <false, P, T, META>
  {
    size_t operator () (P parent, const META & metaname, T & element);
  };
};

/**
 * Specialization of the create_element functor for the modelgen
 * framework.
 */
template <typename T>
struct create_element <Mga_t, T>
{
  template <typename P, typename META>
  T operator () (P parent, const META & metaname);
};
}

#include "modelgen.cpp"

#endif  // !defined _GAME_MODELGEN_H_
