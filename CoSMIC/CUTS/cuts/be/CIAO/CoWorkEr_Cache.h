// -*- C++ -*-

//=============================================================================
/**
 * @file      CoWorkEr_Cache.h
 *
 * $Id: CoWorkEr_Cache.h,v 1.1.2.1 2006/06/07 03:41:20 hillj Exp $
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COWORKER_CACHE_
#define _CUTS_COWORKER_CACHE_

#include "PICML/PICML.h"
#include "UDM_CIAO_Export.h"

//=============================================================================
/**
 * @class CUTS_CoWorkEr_Cache
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_CoWorkEr_Cache
{
public:
  /// Get the singleton instance.
  static CUTS_CoWorkEr_Cache * instance (void);

  /// Close the object and release all resources.
  void close (void);

  /**
   * Determine if a component is a CoWorkEr. In order for a component
   * to be considered a CoWorkEr, it must contain a receptecle named
   * \a cuts_testing_service of type \a Testing_Service. If the component
   * is a CoWorkEr, it is added to an internal cache for quick lookup
   * in the future.
   *
   * @param[in]     component       The target component.
   * @retval        true            The component is a CoWorkEr.
   * @retval        false           The component is not a CoWorkEr.
   */
  bool is_coworker (const PICML::Component & component);

private:
  /// Constructor.
  CUTS_CoWorkEr_Cache (void);

  /// Destructor.
  ~CUTS_CoWorkEr_Cache (void);

  /// Singleton instance.
  static CUTS_CoWorkEr_Cache * instance_;
};
#endif  // !defined _CUTS_COWORKER_CACHE_