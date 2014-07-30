// $Id$

#include "StdAfx.h"
#include "Node.h"

#if !defined (__GAME_INLINE__)
#include "Node.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Shares.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/TargetElements/Resource.h"
#include "PICML/Domain/Domain.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Node_Impl::metaname ("Node");

  //
  // _create (const Domain_in)
  //
  Node Node_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < Node > (parent, Node_Impl::metaname);
  }

  //
  // accept
  //
  void Node_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Node (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Domain
  //
  Domain Node_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // src_Shares
  //
  size_t Node_Impl::src_Shares (std::vector <Shares> & items) const
  {
    return this->in_connections <Shares> (items);
  }

  //
  // src_InterconnectConnection
  //
  size_t Node_Impl::src_InterconnectConnection (std::vector <InterconnectConnection> & items) const
  {
    return this->in_connections <InterconnectConnection> (items);
  }

  //
  // get_Resources
  //
  size_t Node_Impl::get_Resources (std::vector <Resource> & items) const
  {
    return this->children (items);
  }

  //
  // get_Resources
  //
  ::GAME::Mga::Collection_T <Resource> Node_Impl::get_Resources (void) const
  {
    return this->children <Resource> ();
  }
}
