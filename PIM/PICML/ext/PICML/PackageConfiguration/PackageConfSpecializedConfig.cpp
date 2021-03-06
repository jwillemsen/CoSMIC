#include "StdAfx.h"
#include "PackageConfSpecializedConfig.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfSpecializedConfig.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfSpecializedConfig_Impl::metaname ("PackageConfSpecializedConfig");

  //
  // is_abstract
  //
  const bool PackageConfSpecializedConfig_Impl::is_abstract = false;

  //
  // _create (const PackageConfigurationContainer_in, PackageConfiguration_in src, PackageConfigurationReference_in dst)
  //
  PackageConfSpecializedConfig PackageConfSpecializedConfig_Impl::_create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, PackageConfigurationReference_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageConfSpecializedConfig_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageConfSpecializedConfig_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfSpecializedConfig (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfSpecializedConfig_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfSpecializedConfig_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // PackageConfigurationReference
  //
  PackageConfigurationReference PackageConfSpecializedConfig_Impl::dst_PackageConfigurationReference (void) const
  {
    return PackageConfigurationReference::_narrow (this->dst ());
  }
}

