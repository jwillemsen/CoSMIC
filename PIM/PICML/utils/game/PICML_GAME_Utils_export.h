
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl PICML_GAME_UTILS
// ------------------------------
#ifndef PICML_GAME_UTILS_EXPORT_H
#define PICML_GAME_UTILS_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (PICML_GAME_UTILS_HAS_DLL)
#  define PICML_GAME_UTILS_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && PICML_GAME_UTILS_HAS_DLL */

#if !defined (PICML_GAME_UTILS_HAS_DLL)
#  define PICML_GAME_UTILS_HAS_DLL 1
#endif /* ! PICML_GAME_UTILS_HAS_DLL */

#if defined (PICML_GAME_UTILS_HAS_DLL) && (PICML_GAME_UTILS_HAS_DLL == 1)
#  if defined (PICML_GAME_UTILS_BUILD_DLL)
#    define PICML_GAME_UTILS_Export ACE_Proper_Export_Flag
#    define PICML_GAME_UTILS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define PICML_GAME_UTILS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* PICML_GAME_UTILS_BUILD_DLL */
#    define PICML_GAME_UTILS_Export ACE_Proper_Import_Flag
#    define PICML_GAME_UTILS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define PICML_GAME_UTILS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* PICML_GAME_UTILS_BUILD_DLL */
#else /* PICML_GAME_UTILS_HAS_DLL == 1 */
#  define PICML_GAME_UTILS_Export
#  define PICML_GAME_UTILS_SINGLETON_DECLARATION(T)
#  define PICML_GAME_UTILS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* PICML_GAME_UTILS_HAS_DLL == 1 */

// Set PICML_GAME_UTILS_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (PICML_GAME_UTILS_NTRACE)
#  if (ACE_NTRACE == 1)
#    define PICML_GAME_UTILS_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define PICML_GAME_UTILS_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !PICML_GAME_UTILS_NTRACE */

#if (PICML_GAME_UTILS_NTRACE == 1)
#  define PICML_GAME_UTILS_TRACE(X)
#else /* (PICML_GAME_UTILS_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define PICML_GAME_UTILS_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (PICML_GAME_UTILS_NTRACE == 1) */

#endif /* PICML_GAME_UTILS_EXPORT_H */

// End of auto generated file.
