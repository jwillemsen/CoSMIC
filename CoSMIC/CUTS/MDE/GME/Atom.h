// -*- C++ -*-

//=============================================================================
/**
 * @file      Atom.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_ATOM_H_
#define _GME_ATOM_H_

#include "FCO.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Atom
   *
   * Wrapper class for the IMgaAtom interface.
   */
  //===========================================================================

  class GME_Export Atom : public FCO
  {
  public:
    /// Type definition for the interface.
    typedef IMgaAtom _type;

    /// Default constructor.
    Atom (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       atom        Pointer to the atom.
     */
    Atom (IMgaAtom * atom);

    /**
     * Copy constructor.
     *
     * @param[in]       atom        The source object.
     */
    Atom (const Atom & atom);

    /// Destructor.
    virtual ~Atom (void);

    /**
     * Assignment operator.
     *
     * @param[in]       atom        The source object.
     * @return          Reference to this object.
     */
    const Atom & operator = (const Atom & atom);

    /**
     * Attach to an existing atom.
     *
     * @param[in]       atom        The source interface.
     */
    void attach (IMgaAtom * atom);

  protected:
    /// Helper method to get the correct implementation.
    IMgaAtom * impl (void) const;

    /// The underlying interface pointer.
    mutable CComPtr <IMgaAtom> atom_;
  };
}

#endif