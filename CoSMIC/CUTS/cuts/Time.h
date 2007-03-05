// -*- C++ -*-

//=============================================================================
/**
 * @file    Time.h
 *
 * $Id$
 *
 * This file contains methods for performing commom operations with time
 * in CUTS
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_TIME_H_
#define _CUTS_TIME_H_

#include "cuts/CUTS_export.h"

// Forward decl.
class ACE_Time_Value;

//=============================================================================
/**
 * Get the current time value if the specified format. This call
 * is a static operation. Meaning, the string value return is
 * destroyed the next time a timing method is called.
 */
//=============================================================================

CUTS_Export
const char * CUTS_string_time (const char * format);

//=============================================================================
/**
 * Get the current time value if the specified format. This call
 * is a static operation. Meaning, the string value return is
 * destroyed the next time a timing method is called.
 */
//=============================================================================

CUTS_Export
const char * CUTS_string_time (const ACE_Time_Value & tv,
                               const char * format);

//=============================================================================
/**
 * Get the current time value if the specified format. This call
 * is a static operation. Meaning, the string value return is
 * destroyed the next time a timing method is called.
 */
//=============================================================================

CUTS_Export
const char * CUTS_string_time (time_t t, const char * format);

#endif  // !defined _CUTS_TIME_H_
