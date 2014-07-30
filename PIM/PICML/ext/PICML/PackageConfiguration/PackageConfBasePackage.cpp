// $Id$

#include "StdAfx.h"
#include "PackageConfBasePackage.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfBasePackage.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfBasePackage_Impl::metaname ("PackageConfBasePackage");

  //
  // _create (const PackageConfigurationContainer_in)
  //
  PackageConfBasePackage PackageConfBasePackage_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfBasePackage > (parent, PackageConfBasePackage_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfBasePackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfBasePackage (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfBasePackage_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfBasePackage_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // ComponentPackage
  //
  ComponentPackage PackageConfBasePackage_Impl::dst_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->dst ());
  }
}
