// -*- C++ -*-

//=============================================================================
/**
 * @file          Parts_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_PARTS_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_PARTS_METHOD_H_

#include "Method.h"

/**
 * @class Parts_Method
 *
 * Class derived from Method. This class deals
 * with all the parts that a particular metarole/metatype
 * has i.e. with the childrens present in the model
 */
class Parts_Method : public Method
{
public:
  /// Default constructor.
	Parts_Method (std::string &role);

	/// Destructor.
	~Parts_Method (void);

  /**
   * evaluate method for evaluating the parts method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Collection Value object
   */
  Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the parts method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        Value from previous method
   * @return        Object        Collection Value object
   */
	Value * evaluate (Ocl_Context &res, Value *caller);  

private:
  std::string role_;
};

#endif //_GAME_MODEL_INTELLIGENCE_PARTS_METHOD_CALL_H_