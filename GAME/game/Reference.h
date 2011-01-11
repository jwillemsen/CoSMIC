// -*- C++ -*-

//=============================================================================
/**
 * @file      Reference_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_REFERENCE_H_
#define _GME_REFERENCE_H_

#include "FCO.h"
#include "MetaReference.h"

namespace GAME
{
/**
 * @class Reference_Impl
 *
 * Wrapper class for the IMgaReference interface.
 */
class GAME_Export Reference_Impl : public FCO_Impl
{
public:
  /// Type definition of the COM interface.
  typedef IMgaReference interface_type;

  /**
   * Create a new atom element.
   *
   * @param[in]       role          The role of the new object, i.e.,
   *                                its meta name.
   * @param[in]       parent        The parent model.
   * @return          The newly created atom.
   */
  static Reference _create (const Model_in parent, const std::string & type);
  static Reference _create (const Model_in parent, const Meta::Role_in type);

  /// Default constructor.
  Reference_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       ref         The source reference interface.
   */
  Reference_Impl (IMgaReference * ref);

  /// Destructor.
  virtual ~Reference_Impl (void);

  /**
   * Get the FCO to which this reference refers to.
   *
   * @return          The FCO this reference refers to.
   */
  FCO refers_to (void) const;

  /**
   * Set the FCO to which this reference refers to.
   *
   * @param[in]       fco          The FCO this reference refers to.
   */
  void refers_to (const FCO_in fco);

  /// Get the meta information for this object.
  virtual Meta::Reference meta (void) const;

  /// Helper method to get the correct implementation.
  IMgaReference * impl (void) const;

  virtual void accept (Visitor * v);

private:
  /// Pointer to the underlying COM interface.
  mutable ATL::CComPtr <IMgaReference> ref_;
};

}

#if defined (__GAME_INLINE__)
#include "Reference.inl"
#endif

#endif  // !defined _GME_REFERENCE_H_
