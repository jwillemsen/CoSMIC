// -*- C++ -*-

//=============================================================================
/**
 * @file      Set.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_SET_H_
#define _GME_SET_H_

#include "FCO.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Set
   *
   * Wrapper class for the IMgaSet interface.
   */
  //===========================================================================

  class GME_Export Set : public FCO
  {
  public:
    /// Type definition for the interface pointer.
    typedef IMgaSet _type;

    /**
     * Convert a FCO into an set.
     *
     * @param[in]       fco           The source FCO object.
     * @return          The atom object.
     */
    static Set _narrow (FCO & fco);

    /**
     * Create a new set element.
     *
     * @param[in]       role          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created set.
     */
    static Set _create (const std::string & role, Model & parent);

    /// Default constructor.
    Set (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       set       The source interface.
     */
    Set (IMgaSet * set);

    /**
     * Copy constructor.
     *
     * @param[in]       set       The source set.
     */
    Set (const Set & set);

    /// Destructor.
    virtual ~Set (void);

    /**
     * Attach to an existing set.
     *
     * @param[in]       set       The existing set.
     */
    void attach (IMgaSet * set);

    /**
     * Assignment operator.
     *
     * @param[in]     set         The source set.
     * @return        Reference to this object.
     */
    const Set & operator = (const Set & set);

    /**
     * Insert an FCO into the set.
     *
     * @param[in]     fco       The source FCO object.
     */
    void insert (const FCO & fco);

    /**
     * Remove an FCO from the set.
     *
     * @param[in]     fco       The source FCO object.
     */
    void remove (const FCO & fco);

    /**
     * Determine if the set contains a specific FCO object.
     *
     * @retval        true      The set contains the object.
     * @retval        false     The set does not contain the object.
     */
    bool contains (const FCO & fco);

    /// Clear all the objects from the set.
    void clear (void);

    /**
     * Get all the objects in the set.
     *
     * @param[out]    members       Collection of objects in the set.
     * @return        Number of elements in \a members.
     */
    size_t members (std::vector <FCO> & members) const;

  protected:
    /// Helper method for getting the correct implemenation.
    IMgaSet * impl (void) const;

    /// The underlying COM interface pointer.
    mutable CComPtr <IMgaSet> set_;
  };
}
#endif  // !defined _GME_SET_H_