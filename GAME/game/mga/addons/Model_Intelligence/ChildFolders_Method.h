// -*- C++ -*-

//=============================================================================
/**
 * @file          ChildFolders_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CHILDFOLDERS_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_CHILDFOLDERS_METHOD_H_

#include "Method.h"

/**
 * @class ChildFolders_Method
 *
 * Class derived from Method. This class deals
 * with returning set of all folders contained by this folder
 */
class ChildFolders_Method : public Method
{
public:
  /// Default constructor.
	ChildFolders_Method (void);

	/// Destructor.
	~ChildFolders_Method (void);

  /**
   * evaluate method for evaluating the child folders method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Collection Value object
   */
  Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the child folders method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        Value from previous method
   * @return        Object        Collection Value object
   */
	Value * evaluate (Ocl_Context &res, Value *caller);  
};

#endif //_GAME_MODEL_INTELLIGENCE_CHILDFOLDERS_METHOD_CALL_H_