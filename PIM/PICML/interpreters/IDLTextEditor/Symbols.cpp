#include "StdAfx.h"
#include "Symbols.h"

#include "game/mga/FCO.h"
#include "game/mga/MetaBase.h"
#include <stack>

//
// fq_name
//
fq_name::fq_name (void)
{

}

//
// fq_name
//
fq_name::~fq_name (void)
{

}

//
// generate
//
int fq_name::generate (const GAME::Mga::FCO_in fco, ACE_CString & symbol)
{
  // Keep pushing the names of the parent onto the stack until
  // we reach the File.
  std::stack <GAME::Mga::Object> scope;
  GAME::Mga::Object parent = fco->parent ();

  while (parent->meta ()->name () == "Package")
  {
    scope.push (parent);
    parent = parent->parent ();
  }

  // Use the stack to generate the fully qualified name of the
  // symbol for this object.
  symbol = "::";

  while (!scope.empty ())
  {
    // Write the name of the current level.
    symbol += scope.top ()->name ().c_str ();
    symbol += "::";

    // Remove the level of the scope.
    scope.pop ();
  }

  // Append the name of the object.
  symbol += fco->name ().c_str ();

  return 0;
}
