// $Id$

namespace GAME
{
namespace utils
{
//
// Project_Settings
//
GAME_INLINE
Project_Settings::Project_Settings (::GAME::Project & proj)
: project_ (proj),
  default_cache_loc_ ("__OutputDir__/")
{

}

//
// ~Project_Settings
//
GAME_INLINE
Project_Settings::~Project_Settings (void)
{

}

//
// global_default_output_directory
//
GAME_INLINE
std::string Project_Settings::
global_default_output_directory (void) const
{
  return this->default_output_directory ("");
}

//
// global_default_output_directory
//
GAME_INLINE
void Project_Settings::
global_default_output_directory (const std::string & dir)
{
  this->default_output_directory ("", dir);
}
}
}
