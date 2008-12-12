// $Id$

#include "Project_Settings.h"

#if !defined (__GME_INLINE__)
#include "Project_Settings.inl"
#endif

#include "game/Exception.h"
#include <algorithm>
#include <sstream>

//
// default_output_directory
//
std::string GME::Utils::Project_Settings::
default_output_directory (const std::string & uid) const
{
  // Get the root folder for the project.
  GME::Folder root = this->project_.root_folder ();

  // Construct the registry path for the directory.
  std::string path (this->default_cache_loc_);
  path.append (uid);

  // Normalize the registry path.
  std::replace (path.begin (),
                path.end (),
                ' ',
                '_');

  // Store the output directory inside the model.
  return root.registry_value (path);
}

//
// default_output_directory
//
void GME::Utils::Project_Settings::
default_output_directory (const std::string & uid, const std::string & dir)
{
  // Get the root folder for the project.
  GME::Folder root = this->project_.root_folder ();

  // Construct the registry path for the directory.
  std::string path (this->default_cache_loc_);
  path.append (uid);

  // Normalize the registry path.
  std::replace (path.begin (),
                path.end (),
                ' ',
                '_');

  // Store the output directory inside the model.
  root.registry_value (path, dir);
}