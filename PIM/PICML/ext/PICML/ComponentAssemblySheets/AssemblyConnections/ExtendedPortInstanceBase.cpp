#include "StdAfx.h"
#include "ExtendedPortInstanceBase.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPortInstanceBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortInstanceBase_Impl::metaname ("ExtendedPortInstanceBase");

  //
  // is_abstract
  //
  const bool ExtendedPortInstanceBase_Impl::is_abstract = true;

  //
  // src_of_ExtendedDelegate
  //
  size_t ExtendedPortInstanceBase_Impl::src_of_ExtendedDelegate (std::vector <ExtendedDelegate> & items) const
  {
    return this->in_connections <ExtendedDelegate> (items);
  }

  //
  // has_src_of_ExtendedDelegate
  //
  bool ExtendedPortInstanceBase_Impl::has_src_of_ExtendedDelegate (void) const
  {
    return this->in_connections <ExtendedDelegate> ("src").count () == 1;
  }

  //
  // src_of_ExtendedDelegate
  //
  ExtendedDelegate ExtendedPortInstanceBase_Impl::src_of_ExtendedDelegate (void) const
  {
    return this->in_connections <ExtendedDelegate> ("src").first ();
  }
}

