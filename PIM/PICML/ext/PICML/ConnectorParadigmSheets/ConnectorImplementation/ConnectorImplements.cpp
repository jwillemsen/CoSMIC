// $Id$

#include "StdAfx.h"
#include "ConnectorImplements.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorImplements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplements_Impl::metaname ("ConnectorImplements");

  //
  // _create (const ConnectorImplementationContainer_in)
  //
  ConnectorImplements ConnectorImplements_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ConnectorImplements > (parent, ConnectorImplements_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorImplements_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorImplements (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ConnectorImplementationContainer
  //
  ConnectorImplementationContainer ConnectorImplements_Impl::parent_ConnectorImplementationContainer (void)
  {
    return ConnectorImplementationContainer::_narrow (this->parent ());
  }

  //
  // ConnectorImplementation
  //
  ConnectorImplementation ConnectorImplements_Impl::src_ConnectorImplementation (void) const
  {
    return ConnectorImplementation::_narrow (this->src ());
  }

  //
  // ConnectorType
  //
  ConnectorType ConnectorImplements_Impl::dst_ConnectorType (void) const
  {
    return ConnectorType::_narrow (this->dst ());
  }
}
