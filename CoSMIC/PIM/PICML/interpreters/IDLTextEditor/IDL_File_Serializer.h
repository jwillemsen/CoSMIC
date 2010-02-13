// -*- C++ -*-

//=============================================================================
/**
 *  @file         IDL_File_Serializer.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_SERIALIZER_H_
#define _IDL_FILE_SERIALIZER_H_

#include "DSL_Serializer.h"

/**
 * @class IDL_File_Serializer
 *
 * Implementation of the serializer for IDL files.
 */
class IDL_File_Serializer : public DSL_Serializer
{
public:
  /// Default constructor.
  IDL_File_Serializer (void);

  /// Destructor.
  virtual ~IDL_File_Serializer (void);

  virtual int serialize (const ::GME::Object & obj, std::ostream & stream);
};

#endif  // !defined _IDL_FILE_SERIALIZER_H_
