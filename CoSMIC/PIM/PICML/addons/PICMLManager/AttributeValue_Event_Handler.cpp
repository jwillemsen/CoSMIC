// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "AttributeValue_Event_Handler.h"

#include "game/GAME.h"
#include "boost/bind.hpp"
#include <set>

namespace PICML
{
namespace MI
{

//
// AttributeValue_Event_Handler
//
AttributeValue_Event_Handler::AttributeValue_Event_Handler (void)
: Event_Handler_Base (OBJEVENT_CREATED)
{

}

//
// ~AttributeValue_Event_Handler
//
AttributeValue_Event_Handler::~AttributeValue_Event_Handler (void)
{

}

//
// handle_object_created
//
int AttributeValue_Event_Handler::
handle_object_created (GAME::Object obj)
{
  // Extract the connection from the object and get its endpoints.
  GAME::Connection attr_value = GAME::Connection::_narrow (obj);
  GAME::FCO dst = attr_value[std::string ("dst")].target ();
  GAME::FCO src = attr_value[std::string ("src")].target ();
  GAME::Reference attr_inst = GAME::Reference::_narrow (src);

  // Set the name of the Property. We want to ensure the name to
  // the prop matches the name of the attribute.
  if (dst.name () != attr_inst.name ())
    dst.name (attr_inst.name ());

  // Get the target attribute so we know what we are working with.
  GAME::FCO fco = attr_inst.refers_to ();

  if (fco.is_nil ())
    return 0;

  GAME::Model attr = GAME::Model::_narrow (fco);

  // Let's get the data type of the attribute. Since there is only
  // 1 attribute member, we can just get the front element in the
  // container.
  std::vector <GAME::Reference> attr_members;
  GAME::FCO member_type;

  if (1 == attr.children ("AttributeMember", attr_members))
    member_type = attr_members.front ().refers_to ();

  if (member_type.is_nil ())
    return 0;

  if (dst.meta () == "SimpleProperty")
  {
    GAME::Reference simple = GAME::Reference::_narrow (dst);
    simple.refers_to (member_type);
  }
  else
  {
    GAME::Model complex = GAME::Model::_narrow (dst);
    this->set_property_type (complex, member_type);
  }

  return 0;
}

}
}