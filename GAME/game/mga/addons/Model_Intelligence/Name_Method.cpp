// $Id$

#include "StdAfx.h"

#include "Name_Method.h"
#include "String_Value.h"
#include "Object_Value.h"

//
// Constructor
//
Name_Method::Name_Method (void)
{
}

//
// Destructor
//
Name_Method::~Name_Method (void)
{
}

//
// evaluate
//
Value * Name_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
	std::string name = caller->name ();
	return new String_Value (name);
}

//
// evaluate
//
Value * Name_Method::evaluate (Ocl_Context &res, Value *caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);
	std::string name = "";

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();
		name = obj->name ();
	}

	return new String_Value (name);
}