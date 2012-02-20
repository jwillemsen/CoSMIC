// -*- C++ -*-

//==============================================================================
/**
 *  @file        Proxy_Visitor.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_PROXY_VISITOR_H_
#define _GAME_EXTENSION_CLASSES_PROXY_VISITOR_H_

#include "game/mga/Visitor.h"
#include "game/mga/Reference.h"

/**
 * @class Proxy_Visitor
 *
 * Base visitor class for those that plan on visiting proxy elements. This
 * visitor will visit the element referenced by this proxy element.
 */
class Proxy_Visitor : public GAME::Mga::Visitor
{
public:
  /// Default constructor.
  Proxy_Visitor (void);

  /// Destructor.
  virtual ~Proxy_Visitor (void);

  /// Visit the Proxy element.
  virtual void visit_Reference (GAME::Mga::Reference_in item);
};

#if defined (__GAME_INLINE__)
#include "Proxy_Visitor.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _PROXY_VISITOR_H_
