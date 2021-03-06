// -*- C++ -*-

//============================================================================
/**
 * @file    Impl_Factory.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_IMPL_FACTORY_H_
#define _DQML_IMPL_FACTORY_H_

#include "game/mga/Impl_Factory.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

#include "DQML_export.h"

namespace DQML
{
  class DQML_Export Impl_Factory : public ::GAME::Mga::Impl_Factory_Base
  {
    public:
    /// Default constructor.
    Impl_Factory (void);

    /// Destructor.
    virtual ~Impl_Factory (void);

    /// Allocate the implementation for this object.
    virtual ::GAME::Mga::Object_Impl * allocate (IMgaObject * ptr);

    private:
    /// Map of factory methods for this paradigm.
    ACE_Hash_Map_Manager <ACE_CString, FACTORY_METHOD, ACE_Null_Mutex> map_;
  };
}

#endif
