// -*- C++ -*-
// $Id$

namespace GAME
{

//
// Set_Impl
//
GAME_INLINE
Set_Impl::Set_Impl (void)
{

}

//
// Set_Impl
//
GAME_INLINE
Set_Impl::Set_Impl (IMgaSet * set)
: FCO_Impl (set)
{

}

//
// ~Set_Impl
//
GAME_INLINE
Set_Impl::~Set_Impl (void)
{

}

//
// attach
//
GAME_INLINE
void Set_Impl::attach (IMgaSet * set)
{
  FCO_Impl::attach (set);
}


}
