// $Id$

#include "StdAfx.h"
#include "IDL_Generator_File.h"

#include "File_Processor.h"
#include "IDL_Generator_Visitor.h"
#include "IDL_File_Generator.h"
#include "IDL_File_Dependency_Processor.h"
#include "IDLStream.h"

//
// IDL_Generator_File
//
IDL_Generator_File::IDL_Generator_File (std::ostream & out)
: idl_ (out)
{

}

//
// ~IDL_Generator_File
//
IDL_Generator_File::~IDL_Generator_File (void)
{

}

//
// generate
//
bool IDL_Generator_File::generate (const PICML::File & file)
{
  // Construct the hash definition for this file.
  std::string hashdef = "_" + std::string (file.name ()) + "_IDL_";
  std::transform (hashdef.begin (),
                  hashdef.end (),
                  hashdef.begin (),
                  &::toupper);

  this->idl_
    << "#ifndef " << hashdef << nl
    << "#define " << hashdef << nl
    << nl;

  // Preprocess the file. This will genenerate the necessary
  // forward declarations for any object at the top of the
  // target output file.
  IDL_File_Dependency_Processor depends_graph;
  IDL_File_Processor idl_proc (depends_graph, this->idl_);
  PICML::File (file).Accept (idl_proc);

  // Visit the file and generate its contents.
  IDL_File_Generator generator (depends_graph, this->idl_);
  PICML::File (file).Accept (generator);

  this->idl_
    << nl
    << "#endif    // !defined " << hashdef << nl
    << nl;

  return true;
}
