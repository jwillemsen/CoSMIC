#include "StdAfx.h"
#include "IDL_Generator_File.h"

#include "File_Processor.h"
#include "IDL_Generator_Visitor.h"
#include "IDL_File_Generator.h"
#include "IDL_File_Dependency_Processor.h"
#include "IDLStream.h"

#include "boost/lambda/bind.hpp"
#include <algorithm>

struct include_t
{
  include_t (IDLStream & idl)
    : idl_ (idl)
  {

  }

  void operator () (PICML::FileRef_in ref) const
  {
    PICML::File file = ref->refers_to ();
    const std::string name = file->name ();

    this->idl_ << "#include \"" << name << ".idl\"" << nl;
  }

private:
  IDLStream & idl_;
};

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
bool IDL_Generator_File::generate (PICML::File_in file)
{
  // Construct the hash definition for this file.
  std::string hashdef = "_" + std::string (file->name ()) + "_IDL_";
  std::transform (hashdef.begin (),
                  hashdef.end (),
                  hashdef.begin (),
                  &::toupper);

  this->idl_
    << "#ifndef " << hashdef << nl
    << "#define " << hashdef << nl
    << nl;

  for (auto include : file->get_FileRefs ())
    include_t (this->idl_)(include);

  // Preprocess the file. This will genenerate the necessary
  // forward declarations for any object at the top of the
  // target output file.
  IDL_File_Dependency_Processor depends_graph;
  IDL_File_Processor idl_proc (depends_graph, this->idl_);
  file->accept (&idl_proc);

  // Visit the file and generate its contents.
  IDL_File_Generator generator (depends_graph, this->idl_);
  file->accept (&generator);

  this->idl_
    << nl
    << "#endif    // !defined " << hashdef << nl
    << nl;

  return true;
}
