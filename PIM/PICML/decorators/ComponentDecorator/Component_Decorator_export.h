
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl COMPONENT_DECORATOR
// ------------------------------
#ifndef COMPONENT_DECORATOR_EXPORT_H
#define COMPONENT_DECORATOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (COMPONENT_DECORATOR_HAS_DLL)
#  define COMPONENT_DECORATOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && COMPONENT_DECORATOR_HAS_DLL */

#if !defined (COMPONENT_DECORATOR_HAS_DLL)
#  define COMPONENT_DECORATOR_HAS_DLL 1
#endif /* ! COMPONENT_DECORATOR_HAS_DLL */

#if defined (COMPONENT_DECORATOR_HAS_DLL) && (COMPONENT_DECORATOR_HAS_DLL == 1)
#  if defined (COMPONENT_DECORATOR_BUILD_DLL)
#    define COMPONENT_DECORATOR_Export ACE_Proper_Export_Flag
#    define COMPONENT_DECORATOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define COMPONENT_DECORATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* COMPONENT_DECORATOR_BUILD_DLL */
#    define COMPONENT_DECORATOR_Export ACE_Proper_Import_Flag
#    define COMPONENT_DECORATOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define COMPONENT_DECORATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* COMPONENT_DECORATOR_BUILD_DLL */
#else /* COMPONENT_DECORATOR_HAS_DLL == 1 */
#  define COMPONENT_DECORATOR_Export
#  define COMPONENT_DECORATOR_SINGLETON_DECLARATION(T)
#  define COMPONENT_DECORATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* COMPONENT_DECORATOR_HAS_DLL == 1 */

// Set COMPONENT_DECORATOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (COMPONENT_DECORATOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define COMPONENT_DECORATOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define COMPONENT_DECORATOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !COMPONENT_DECORATOR_NTRACE */

#if (COMPONENT_DECORATOR_NTRACE == 1)
#  define COMPONENT_DECORATOR_TRACE(X)
#else /* (COMPONENT_DECORATOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define COMPONENT_DECORATOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (COMPONENT_DECORATOR_NTRACE == 1) */

#endif /* COMPONENT_DECORATOR_EXPORT_H */

// End of auto generated file.
