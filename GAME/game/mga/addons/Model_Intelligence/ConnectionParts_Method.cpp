// $Id:  $

#include "StdAfx.h"

#include "ConnectionParts_Method.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Connection.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"

//
// Constructor
//
ConnectionParts_Method::ConnectionParts_Method (std::string &role)
: role_ (role)
{
}

//
// Destructor
//
ConnectionParts_Method::~ConnectionParts_Method (void)
{
}

//
// evaluate
//
Value * ConnectionParts_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
	GAME::Mga::Model mod = GAME::Mga::Model::_narrow (caller);

  std::vector<GAME::Mga::Connection> parts;
	GAME::Mga::Meta::Role target_metarole = mod->meta ()->role (this->role_);

	// Setting the target metarole in the model intelligence context
	res.target_metaroles.push_back (target_metarole);
  
  GAME::Mga::Meta::FCO temp = target_metarole->kind ();

  if (temp->type() == OBJTYPE_CONNECTION)
    mod->children (temp->name(), parts);

  return new Collection_Value_T<GAME::Mga::Connection> (parts);

}

//
// evaluate
//
Value * ConnectionParts_Method::evaluate (Ocl_Context &res, Value *caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();

		GAME::Mga::Model mod = GAME::Mga::Model::_narrow (obj);

    std::vector<GAME::Mga::Connection> parts;
		GAME::Mga::Meta::Role target_metarole = mod->meta ()->role (this->role_);

		// Setting the target metarole in the model intelligence context
		res.target_metaroles.push_back (target_metarole);
	  
		GAME::Mga::Meta::FCO temp = target_metarole->kind ();

    if (temp->type() == OBJTYPE_CONNECTION)
      mod->children (temp->name(), parts);

    return new Collection_Value_T<GAME::Mga::Connection> (parts);
	}
	else
	{
    std::vector<GAME::Mga::Connection> parts;
    return new Collection_Value_T<GAME::Mga::Connection> (parts);
	}
}

//
// is_filter
//
bool ConnectionParts_Method::is_filter (void)
{
  return false;
}