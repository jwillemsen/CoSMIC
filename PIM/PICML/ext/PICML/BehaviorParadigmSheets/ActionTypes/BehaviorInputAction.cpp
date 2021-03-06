#include "StdAfx.h"
#include "BehaviorInputAction.h"

#if !defined (__GAME_INLINE__)
#include "BehaviorInputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorInputAction_Impl::metaname ("BehaviorInputAction");

  //
  // is_abstract
  //
  const bool BehaviorInputAction_Impl::is_abstract = true;

  //
  // parent_BehaviorModel
  //
  BehaviorModel BehaviorInputAction_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // src_of_InputEffect
  //
  size_t BehaviorInputAction_Impl::src_of_InputEffect (std::vector <InputEffect> & items) const
  {
    return this->in_connections <InputEffect> (items);
  }

  //
  // has_src_of_InputEffect
  //
  bool BehaviorInputAction_Impl::has_src_of_InputEffect (void) const
  {
    return this->in_connections <InputEffect> ("src").count () == 1;
  }

  //
  // src_of_InputEffect
  //
  InputEffect BehaviorInputAction_Impl::src_of_InputEffect (void) const
  {
    return this->in_connections <InputEffect> ("src").first ();
  }

  //
  // dst_of_Finish
  //
  size_t BehaviorInputAction_Impl::dst_of_Finish (std::vector <Finish> & items) const
  {
    return this->in_connections <Finish> (items);
  }

  //
  // has_dst_of_Finish
  //
  bool BehaviorInputAction_Impl::has_dst_of_Finish (void) const
  {
    return this->in_connections <Finish> ("dst").count () == 1;
  }

  //
  // dst_of_Finish
  //
  Finish BehaviorInputAction_Impl::dst_of_Finish (void) const
  {
    return this->in_connections <Finish> ("dst").first ();
  }

  //
  // get_SimplePropertys
  //
  size_t BehaviorInputAction_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> BehaviorInputAction_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t BehaviorInputAction_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> BehaviorInputAction_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }
}

