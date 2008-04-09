//###############################################################################################################################################
//
//  Meta and Builder Object Network V2.0 for GME
//  BON2Component.cpp
//
//###############################################################################################################################################

/*
  Copyright (c) Vanderbilt University, 2000-2004
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

#include "BON2Component.h"
#include "IDMLBonExtension.h"
#include "DependencyVisitor.h"
#include "IDLEmitVisitor.h"
#include "Utils/Utils.h"

#include <fstream>
#include <direct.h>

namespace BON
{

using namespace IDML;

//###############################################################################################################################################
//
//   C L A S S : BON::Component
//
//###############################################################################################################################################

Component::Component()
  : m_bIsInteractive( false )
{
}

Component::~Component()
{
  if ( m_project ) {
    m_project->finalizeObjects();
    finalize( m_project );
    m_project = NULL;
  }
}

// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{
  // ======================
  // Insert application specific code here
}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
  // ======================
  // Insert application specific code here
}

// ====================================================
// This is the obsolete component interface
// This present implementation either tries to call InvokeEx, or does nothing except of a notification

void Component::invoke( Project& project, const std::set<FCO>& setModels, long lParam )
{
  #ifdef SUPPORT_OLD_INVOKE
    Object focus;
    invokeEx( project, focus, setModels, lParam );
  #else
    if ( m_bIsInteractive )
      AfxMessageBox("This BON2 Component does not support the obsolete invoke mechanism!");
  #endif
}

// ====================================================
// This is the main component method for Interpereters and Plugins.
// May also be used in case of invokeable Add-Ons

void Component::invokeEx( Project& project,
                          FCO& currentFCO,
                          const std::set<FCO>& setSelectedFCOs,
                          long lParam )
{
  project->setNmsp("PICML");

  std::string outputPath;
  std::string message = "Please specify the output directory";

  // If there is no output path specified
  if (!Utils::getPath (message, outputPath))
    return;

  std::set<Object> selected = project->findByKind ("File");

  for (std::set<Object>::const_iterator it = selected.begin ();
       it != selected.end ();
       ++it)
    {
      File root (*it);

      if (!root)
        {
          AfxMessageBox ("Interpretation must start from a File model!");
          continue;
        }
        
      if (root->isInLibrary ())
        {
          continue;
        }

      DependencyVisitor root_visitor;
      root_visitor.visitOrderableImpl (root);

      // Preserves any directory structure that may have existed
      // with IDL files imported into the model.
      
      std::string filepath = root->getpath ();
      std::string dirpath = outputPath
                            + (filepath == "" ? "" : "\\" + filepath);
                            
      // We don't care about the return value. Since we are passing
      // an absolute path, it will always get created unless it
      // already exists. Either way the stream gets a valid file path.
      (void) ::_mkdir (dirpath.c_str ());
      
      std::string raw_filename = root->getName ();
      std::string fullpath = dirpath
                             + "\\"
                             + raw_filename
                             + ".idl";

      std::ofstream strm (fullpath.c_str ());

      IDLEmitVisitor emit_visitor (strm);
      emit_visitor.visitOrderableImpl (root);
    }

  AfxMessageBox ("IDL generation completed.",
                 MB_OK | MB_ICONINFORMATION);
}

// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
  {
    if ( m_bIsInteractive )
      AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
  }

// ====================================================
// Implement application specific parameter-mechanism in these functions

Util::Variant Component::getParameter( const std::string& strName )
{
  // ======================
  // Insert application specific code here

  return Util::Variant();
}

void Component::setParameter( const std::string& strName, const Util::Variant& varValue )
{
  // ======================
  // Insert application specific code here
}

#ifdef GME_ADDON

// ====================================================
// If the component is an Add-On, then this method is called for every Global Event

void Component::globalEventPerformed( globalevent_enum event )
{
  // ======================
  // Insert application specific code here
}

// ====================================================
// If the component is an Add-On, then this method is called for every Object Event

void Component::objectEventPerformed( Object& object, unsigned long event, VARIANT v )
{
  // ======================
  // Insert application specific code here
}

#endif // GME_ADDON

}; // namespace BON
