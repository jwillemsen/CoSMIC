// $Id$

#include "StdAfx.h"
#include "Scope_Display_Strategy.h"

#if !defined (__GAME_INLINE__)
#include "Scope_Display_Strategy.inl"
#endif

#include "game/Object.h"
#include <stack>

namespace PICML
{
namespace MI
{

//
// get_display_name
//
bool Scope_Display_Strategy::
get_display_name (const GAME::Object & obj, std::string & display_name)
{
  // Get the parent of the object current object.
  std::stack <GAME::Object> scope;
  GAME::Object parent = obj.parent ();

  // Keep getting the parent until we have found the File element.
  while (parent.meta () != "File")
  {
    scope.push (parent);
    parent = parent.parent ();
  }

  // Write the name of the file for the element. This will help deal
  // with duplicate names that appear in different file, which is
  // allowed.
  display_name = parent.name () + "/";

  while (!scope.empty ())
  {
    display_name += scope.top ().name () + "::";
    scope.pop ();
  }

  // Last, append the name of the object.
  display_name += obj.name ();

  return true;
}

}
}
