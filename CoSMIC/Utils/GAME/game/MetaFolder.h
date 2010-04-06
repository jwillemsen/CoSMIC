// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaFolder.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METAFOLDER_H_
#define _GME_METAFOLDER_H_

#include "MetaFCO.h"
#include "Collection_T.h"

namespace GME
{
namespace Meta
{
/**
 * @class Folder
 *
 * Wrapper class for the IMgaMetaFolder interface.
 */
class GME_Export Folder : public Base
{
public:
  /// Type definition of the underlying interface.
  typedef IMgaMetaFolder interface_type;

  /// Default constructor.
  Folder (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        The source object.
   */
  Folder (IMgaMetaFolder * meta);

  /**
   * Copy constructor.
   *
   * @param[in]     meta        The meta folder.
   */
  Folder (const Folder & meta);

  /// Destructor.
  virtual ~Folder (void);

  /**
   * Attach to an existing meta folder.
   *
   * @param[in]     meta        The existing meta folder.
   */
  void attach (IMgaMetaFolder * meta);

  /**
   * Get all the subfolders defined by this folder.
   *
   * @param[out]      metafolder      Collection of meta folders
   * @return          Number of folders in \a metafolders.
   */
  size_t children (std::vector <GME::Meta::Folder> & folders) const;

  /**
   * Get all the subfolders defined by this folder.
   *
   * @param[out]      metafolder      Collection of meta folders
   * @return          Number of folders in \a metafolders.
   */
  size_t children (std::vector <GME::Meta::FCO> & fcos) const;

  FCO child (const std::string & name) const;

  Folder folder (const std::string & name) const;

  /**
   * Convert the object to an implementation pointer.
   *
   * @return          Pointer to the implementation.
   */
  operator IMgaMetaFolder * (void) const;

  /**
   * Get a pointer to the implementation.
   *
   * @return          Pointer to the implementation.
   */
  IMgaMetaFolder * impl (void) const;

  /**
   * Get the meta FCO for the specified name.
   *
   * @param[in]       name        Name of the FCO.
   * @param[in]       in_scope    Scope of the FCO.
   * @return          Meta FCO object.
   */
  GME::Meta::FCO fco (const std::string & name, bool in_scope = true);

private:
  /// Cached pointer to the metafolder.
  mutable CComPtr <IMgaMetaFolder> metafolder_;
};
}
}

#if defined (__GME_INLINE__)
#include "MetaFolder.inl"
#endif

#endif  // !defined _GME_METAFOLDER_H_
