// -*- C++ -*-

//=============================================================================
/**
 * @file      Time_Measurement_Test.h
 *
 * $Id: Time_Measurement_Test.h,v 1.1.2.1 2006/05/21 16:13:53 hillj Exp $
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TIME_MEASUREMENT_TEST_H_
#define _CUTS_TIME_MEASUREMENT_TEST_H_

#include "Test.h"
#include "Unit_Test.h"
#include "Test_Macros.h"

CUTS_TEST_DECLARE (CUTS_Time_Measurement_Test);

CUTS_UNIT_TEST_DECLARE (Time_Measurement_Constructor);
CUTS_UNIT_TEST_DECLARE (Time_Measurement_Add_Time);
CUTS_UNIT_TEST_DECLARE (Time_Measurement_Reset);

#endif  // !defined _CUTS_TIME_MEASUREMENT_TEST_H_