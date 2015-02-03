// $Id$

#include "StdAfx.h"
#include "ExceptionType.h"

#if !defined (__GAME_INLINE__)
#include "ExceptionType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/GetException.h"
#include "PICML/OperationTypes/ExceptionRef.h"
#include "PICML/InheritableTypes/SetException.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExceptionType_Impl::metaname ("ExceptionType");

  //
  // is_abstract
  //
  const bool ExceptionType_Impl::is_abstract (1);
}

