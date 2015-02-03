// $Id$

#include "StdAfx.h"
#include "MirrorPortInstanceBase.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPortInstanceBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortInstanceBase_Impl::metaname ("MirrorPortInstanceBase");

  //
  // is_abstract
  //
  const bool MirrorPortInstanceBase_Impl::is_abstract (1);

  //
  // src_of_MirrorDelegate
  //
  size_t MirrorPortInstanceBase_Impl::src_of_MirrorDelegate (std::vector <MirrorDelegate> & items) const
  {
    return this->in_connections <MirrorDelegate> (items);
  }

  //
  // src_of_MirrorDelegate
  //
  GAME::Mga::Collection_T <MirrorDelegate> MirrorPortInstanceBase_Impl::src_of_MirrorDelegate (void) const
  {
    return this->in_connections <MirrorDelegate> ("src");
  }
}

