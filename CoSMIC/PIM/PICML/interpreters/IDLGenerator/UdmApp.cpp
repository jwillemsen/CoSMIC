/*
  Copyright (c) Vanderbilt University, 2000-2001
  ALL RIGHTS RESERVED
  Vanderbilt University disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall Vanderbilt University be liable for
  any special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Monday, May 13, 2002 13:45:42

// Tiham�r Levendovszky 05-13-02

#include "stdafx.h"
#pragma warning( disable : 4290 )

#include <windows.h>
#include <shlobj.h>
#include "resource.h"
#include <stdlib.h>
#include <sstream>

#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#include "Utils/Utils.h"
#include "IDL_Generator_Visitor.h"

extern void dummy(void); // Dummy function for UDM meta initialization

// Initialization function. The framework calls it before preparing the
// backend. Initialize here the settings in the config static object.
// Return 0 if successful.
int CUdmApp::Initialize()
{
  return 0;
}
/*
  Remarks to CUdmApp::UdmMain(...):
  0. The p_backend points to an already open backend, and the framework
  closes it automatically. DO NOT OPEN OR CLOSE IT! To commit changes
  use p_backend->CommitEditSequence(). To abort changes use
  p_backend->AbortEditSequence(). To save changes to a different file
  use p_backend->SaveAs() or p_backend->CloseAs().

  1. Focus is the currently open model.

  2. The possible values for param (from GME DecoratorLib.h
  component_startmode_enum):
  GME_MAIN_START    =   0,
  GME_BROWSER_START    =   1,
  GME_CONTEXT_START    =   2,
  GME_EMBEDDED_START    =   3,
  GME_MENU_START    =  16,
  GME_BGCONTEXT_START  =  18,
  GME_ICON_START    =  32,
  METAMODEL_CHECK_SYNTAX  = 101

  3. The framework catches all the exceptions and reports the error in a
  message box, clean up and close the transactions aborting the changes.
  You can override this behavior by catching udm_exception. Use
  udm_exception::what() to form an error message.
*/

/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/

void CUdmApp::
UdmMain (Udm::DataNetwork* p_backend,
         Udm::Object focusObject, 
         set <Udm::Object> selectedObjects, 
         long param) 
{
  try
  {
    // Select the output directory for the files.
    std::string outdir;

    if (!::Utils::getPath ("Select target output directory for IDL files", outdir))
      return;

    // Generate all the IDL files.
    PICML::RootFolder folder = PICML::RootFolder::Cast (p_backend->GetRootObject ());

    IDL_Generator_Visitor visitor (outdir);
    folder.Accept (visitor);

    ::AfxMessageBox ("Successfully generated IDL files");
  }
  catch(udm_exception &e)
  {
    ::AfxMessageBox ("Caught UDM exception: " + CString (e.what ()));
  }
}