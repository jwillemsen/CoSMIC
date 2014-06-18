// $Id$

#include "StdAfx.h"
#include "iCCM.h"

#if !defined (__GAME_INLINE__)
#include "iCCM.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainQos/DomainQosFolder.h"
#include "DQML/iCCM/TopicQos/TopicQosFolder.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string iCCM_Impl::metaname ("iCCM");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  iCCM iCCM_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <iCCM> (parent, iCCM_Impl::metaname);
  }

  //
  // accept
  //
  void iCCM_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_iCCM (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder iCCM_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_DomainQosFolders
  //
  size_t iCCM_Impl::get_DomainQosFolders (std::vector <DomainQosFolder> & items) const
  {
    return this->folders (items);
  }

  //
  // get_TopicQosFolders
  //
  size_t iCCM_Impl::get_TopicQosFolders (std::vector <TopicQosFolder> & items) const
  {
    return this->folders (items);
  }
}

