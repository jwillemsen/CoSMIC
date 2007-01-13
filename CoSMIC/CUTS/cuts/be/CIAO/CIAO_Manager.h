// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CIAO_MANAGER_H_
#define _CUTS_BE_CIAO_MANAGER_H_

// CIAO headers
#include "CIAO_Exec_Header_Traits.h"
#include "CIAO_Exec_Source_Traits.h"
#include "CIAO_Proxy_Header_Traits.h"
#include "CIAO_Proxy_Source_Traits.h"
#include "CIAO_Project_Generator.h"

// CUTS backend headers
#include "cuts/be/BE_Manager_T.h"
#include "cuts/be/BE_List_T.h"

/// Type definition for the CIAO executor generator.
typedef
  CUTS_BE_List_T <CUTS_CIAO_Exec_Header_Traits,
  CUTS_BE_List_T <CUTS_CIAO_Exec_Source_Traits> >
  CIAO_EXEC_GENERATOR;

/// Type definition for the CIAO proxy generator.
typedef
  CUTS_BE_List_T <CUTS_CIAO_Proxy_Header_Traits,
  CUTS_BE_List_T <CUTS_CIAO_Proxy_Source_Traits> >
  CIAO_PROXY_GENERATOR;

/// Type definition for the CIAO backend manager.
typedef
  CUTS_BE_Manager_T <CUTS_CIAO_Project_Generator,
                     CIAO_EXEC_GENERATOR,
                     CIAO_PROXY_GENERATOR> CIAO_BE_Manager;


#endif  // !defined _CUTS_BE_CIAO_MANAGER_H_