// -*- C++ -*-

//=============================================================================
/**
 * @file      Image_Manager_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_GRAPHICS_IMAGE_MANAGER_T_H_
#define _GME_GRAPHICS_IMAGE_MANAGER_T_H_

#include <map>
#include <gdiplus.h>

namespace GAME
{
namespace graphics
{
/**
 * @class Image_Manager
 */
template <typename T>
class Image_Manager_T
{
public:
  /// Default constructor.
  Image_Manager_T (void);

  /// Destructor.
  ~Image_Manager_T (void);

  bool associate_image (const T & key,  const std::string & filename);

  bool get_image (const std::string & filename, Gdiplus::Image * & image) const;

  bool get_image (const T & key, Gdiplus::Image * & image) const;

private:
  std::map <std::string, Gdiplus::Image *> images_;

  std::map <T, Gdiplus::Image *> assoc_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Image_Manager_T.inl"
#endif

#include "Image_Manager_T.cpp"

#endif  // !defined _GME_GRAPHICS_IMAGE_RESOLVER_H_