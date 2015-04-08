
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl COMPONENTREF_DECORATOR
// ------------------------------
#ifndef COMPONENTREF_DECORATOR_EXPORT_H
#define COMPONENTREF_DECORATOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (COMPONENTREF_DECORATOR_HAS_DLL)
#  define COMPONENTREF_DECORATOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && COMPONENTREF_DECORATOR_HAS_DLL */

#if !defined (COMPONENTREF_DECORATOR_HAS_DLL)
#  define COMPONENTREF_DECORATOR_HAS_DLL 1
#endif /* ! COMPONENTREF_DECORATOR_HAS_DLL */

#if defined (COMPONENTREF_DECORATOR_HAS_DLL) && (COMPONENTREF_DECORATOR_HAS_DLL == 1)
#  if defined (COMPONENTREF_DECORATOR_BUILD_DLL)
#    define COMPONENTREF_DECORATOR_Export ACE_Proper_Export_Flag
#    define COMPONENTREF_DECORATOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define COMPONENTREF_DECORATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* COMPONENTREF_DECORATOR_BUILD_DLL */
#    define COMPONENTREF_DECORATOR_Export ACE_Proper_Import_Flag
#    define COMPONENTREF_DECORATOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define COMPONENTREF_DECORATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* COMPONENTREF_DECORATOR_BUILD_DLL */
#else /* COMPONENTREF_DECORATOR_HAS_DLL == 1 */
#  define COMPONENTREF_DECORATOR_Export
#  define COMPONENTREF_DECORATOR_SINGLETON_DECLARATION(T)
#  define COMPONENTREF_DECORATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* COMPONENTREF_DECORATOR_HAS_DLL == 1 */

// Set COMPONENTREF_DECORATOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (COMPONENTREF_DECORATOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define COMPONENTREF_DECORATOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define COMPONENTREF_DECORATOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !COMPONENTREF_DECORATOR_NTRACE */

#if (COMPONENTREF_DECORATOR_NTRACE == 1)
#  define COMPONENTREF_DECORATOR_TRACE(X)
#else /* (COMPONENTREF_DECORATOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define COMPONENTREF_DECORATOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (COMPONENTREF_DECORATOR_NTRACE == 1) */

#endif /* COMPONENTREF_DECORATOR_EXPORT_H */

// End of auto generated file.
