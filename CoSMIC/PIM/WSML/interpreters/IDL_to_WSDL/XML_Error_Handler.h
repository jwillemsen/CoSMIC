//==============================================================
/**
 *  @file  XML_Error_Handler.h
 *
 *  $Id: XML_Error_Handler.h,v 1.2 2005/12/06 19:22:42 parsons Exp $
 *
 *  @brief Error handler for Xerces
 *
 *  @author Bala Natarajan <bala@dre.vanderbilt.edu>
 */
//================================================================
#ifndef IDL_TO_WSDL_ERROR_HANDLER_H
#define IDL_TO_WSDL_ERROR_HANDLER_H

#include /**/ "ace/pre.h"

#include "IDL_TO_WSDL_BE_Export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include <xercesc/dom/DOMErrorHandler.hpp>

using xercesc::DOMErrorHandler;
using xercesc::DOMError;

/**
  * @class XML_Error_Hander
  *
  * @brief Error handler for XERCES
  *
  */
class IDL_TO_WSDL_BE_Export XML_Error_Handler
  : public DOMErrorHandler
{
public:

  XML_Error_Handler (void);

  ~XML_Error_Handler (void);

  bool handleError (const DOMError& domError);

  void resetErrors (void);

  bool getErrors(void) const;

private :
  // Disallow copying
  XML_Error_Handler (const XML_Error_Handler&);
  XML_Error_Handler& operator= (const XML_Error_Handler&);

  bool errors_;
};

#include /**/ "ace/post.h"

#endif /* IDL_TO_WSDL_ERROR_HANDLER_H*/