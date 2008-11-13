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

#define PARADIGM_NAMESPACE_FOR_LEESA HFSM
#include "LEESA.h"

#include "HFSM.h"

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
  GME_MAIN_START		=   0,
  GME_BROWSER_START		=   1,
  GME_CONTEXT_START		=   2,
  GME_EMBEDDED_START		=   3,
  GME_MENU_START		=  16,
  GME_BGCONTEXT_START	=  18,
  GME_ICON_START		=  32,
  METAMODEL_CHECK_SYNTAX	= 101

  3. The framework catches all the exceptions and reports the error in a
  message box, clean up and close the transactions aborting the changes.
  You can override this behavior by catching udm_exception. Use
  udm_exception::what() to form an error message.
*/


using namespace HFSM;
class CountVisitor : public HFSM::Visitor 
{
  int count_;
public:
  CountVisitor () : count_(0) {}
  void Visit_Transition(const Transition &t) {
    std::string name = std::string("Transition: ") + std::string(t.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_State(const State &s) {
    std::string name = std::string("State: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
    count_++;
  }
  void Visit_InputSequence(const InputSequence &i) {
    std::string name = std::string("InputSequence: ") + std::string(i.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_Sequence(const Sequence &s) {
    std::string name = std::string("Sequence: ") + std::string(s.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  void Visit_Events(const Events &e) {
    std::string name = std::string("Events: ") + std::string(e.name());
    AfxMessageBox (name.c_str(), MB_OK| MB_ICONINFORMATION);
  }
  int get_count() { return count_; }
};

CountVisitor cv;

void print (State s)
{
  //MgaObject o = s;
  Udm::Object o = s;
  o.Accept(cv);
}

void dispatch (MgaObject mga)
{
  mga.Accept(cv);
}

void recurse (State s) 
{
  using namespace LEESA;
  //BOOST_AUTO(expr, State() >> cv >> State() >> ForEach(State(), recurse));
  //BOOST_AUTO(expr, State() >> State() >> ForEach(State(), recurse) >> cv );
  //BOOST_AUTO(expr, State() >> expr2 >> ForEach(State(), recurse));
  /*BOOST_AUTO(expr, State() >> cv
    >> MembersOf(State(), Transition() >> cv && State() >> ForEach(State(), recurse))
    );*/
  //evaluate(s, expr);
}
/*
template <>
struct LEESA::FullTD_Custom::ChildrenKinds <State>
{
  typedef boost::mpl::vector<Transition> type;
};
template <>
struct LEESA::FullTD_Custom::ChildrenKinds <InputSequence>
{
  typedef boost::mpl::vector<Events, int> type;
  //typedef  LEESA::EmptyMPLVector type;
};
*/

int leesa_example(RootFolder rf)
{
  using namespace LEESA;
  BOOST_AUTO(expr, RootFolder() >> State() 
                    >> Call(State(), State() >> cv)
                    >> Call(State(), State() >> cv));
  //BOOST_AUTO(expr, RootFolder() >> State() >> ForEach(State(), print));
  evaluate(rf, expr);
  //std::set<State> s = rf.children_kind<State>();
  std::set<InputSequence> s = rf.children_kind<InputSequence>();
  
  VisitStrategy<RootFolder> vs(cv);
  FullTDOp<RootFolder, VisitStrategy> a(vs);
  a(rf);

  //MgaObject mga = *(s.begin());
  //s = mga.children<MgaObject>();
  //std::for_each(s.begin(), s.end(), dispatch);
  return cv.get_count();
}



/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/
void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,      // Backend pointer
                                                        // (already open!)
                      Udm::Object focusObject,          // Focus object
                      set<Udm::Object> selectedObjects,	// Selected objects
                      long param)			// Parameters
{
  HFSM::RootFolder rf = HFSM::RootFolder::Cast (p_backend->GetRootObject());
  
  int n = leesa_example(rf);
  std::ostringstream ostr;
  ostr << "UDM_DSL finished: " << n;

  AfxMessageBox (ostr.str().c_str(), MB_OK| MB_ICONINFORMATION);
}
