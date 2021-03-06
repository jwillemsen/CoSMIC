#include "StdAfx.h"
#include "PackageConfiguration.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfiguration.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfiguration_Impl::metaname ("PackageConfiguration");

  //
  // is_abstract
  //
  const bool PackageConfiguration_Impl::is_abstract = false;

  //
  // _create (const PackageConfigurationContainer_in)
  //
  PackageConfiguration PackageConfiguration_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create < PackageConfiguration > (parent, PackageConfiguration_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfiguration_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfiguration (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfiguration_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // src_of_PackageConfSpecializedConfig
  //
  size_t PackageConfiguration_Impl::src_of_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const
  {
    return this->in_connections <PackageConfSpecializedConfig> (items);
  }

  //
  // has_src_of_PackageConfSpecializedConfig
  //
  bool PackageConfiguration_Impl::has_src_of_PackageConfSpecializedConfig (void) const
  {
    return this->in_connections <PackageConfSpecializedConfig> ("src").count () == 1;
  }

  //
  // src_of_PackageConfSpecializedConfig
  //
  PackageConfSpecializedConfig PackageConfiguration_Impl::src_of_PackageConfSpecializedConfig (void) const
  {
    return this->in_connections <PackageConfSpecializedConfig> ("src").first ();
  }

  //
  // src_of_PackageConfConfigProperty
  //
  size_t PackageConfiguration_Impl::src_of_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const
  {
    return this->in_connections <PackageConfConfigProperty> (items);
  }

  //
  // has_src_of_PackageConfConfigProperty
  //
  bool PackageConfiguration_Impl::has_src_of_PackageConfConfigProperty (void) const
  {
    return this->in_connections <PackageConfConfigProperty> ("src").count () == 1;
  }

  //
  // src_of_PackageConfConfigProperty
  //
  PackageConfConfigProperty PackageConfiguration_Impl::src_of_PackageConfConfigProperty (void) const
  {
    return this->in_connections <PackageConfConfigProperty> ("src").first ();
  }

  //
  // src_of_PackageConfReference
  //
  size_t PackageConfiguration_Impl::src_of_PackageConfReference (std::vector <PackageConfReference> & items) const
  {
    return this->in_connections <PackageConfReference> (items);
  }

  //
  // has_src_of_PackageConfReference
  //
  bool PackageConfiguration_Impl::has_src_of_PackageConfReference (void) const
  {
    return this->in_connections <PackageConfReference> ("src").count () == 1;
  }

  //
  // src_of_PackageConfReference
  //
  PackageConfReference PackageConfiguration_Impl::src_of_PackageConfReference (void) const
  {
    return this->in_connections <PackageConfReference> ("src").first ();
  }

  //
  // src_of_PackageConfSelectRequirement
  //
  size_t PackageConfiguration_Impl::src_of_PackageConfSelectRequirement (std::vector <PackageConfSelectRequirement> & items) const
  {
    return this->in_connections <PackageConfSelectRequirement> (items);
  }

  //
  // src_of_PackageConfSelectRequirement
  //
  GAME::Mga::Collection_T <PackageConfSelectRequirement> PackageConfiguration_Impl::src_of_PackageConfSelectRequirement (void) const
  {
    return this->in_connections <PackageConfSelectRequirement> ("src");
  }

  //
  // src_of_PackageConfBasePackage
  //
  size_t PackageConfiguration_Impl::src_of_PackageConfBasePackage (std::vector <PackageConfBasePackage> & items) const
  {
    return this->in_connections <PackageConfBasePackage> (items);
  }

  //
  // has_src_of_PackageConfBasePackage
  //
  bool PackageConfiguration_Impl::has_src_of_PackageConfBasePackage (void) const
  {
    return this->in_connections <PackageConfBasePackage> ("src").count () == 1;
  }

  //
  // src_of_PackageConfBasePackage
  //
  PackageConfBasePackage PackageConfiguration_Impl::src_of_PackageConfBasePackage (void) const
  {
    return this->in_connections <PackageConfBasePackage> ("src").first ();
  }
}

