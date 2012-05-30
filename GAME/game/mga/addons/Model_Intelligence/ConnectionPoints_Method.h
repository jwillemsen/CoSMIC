// -*- C++ -*-

//=============================================================================
/**
 * @file          ConnectionPoints_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONNECTIONPOINTS_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_CONNECTIONPOINTS_METHOD_H_

#include "Method.h"

/**
 * @class ConnectionPoints_Method
 *
 * Class derived from Method. This class deals
 * with finding the role name of the object
 */
class ConnectionPoints_Method : public Method
{
public:
  /// Default constructor.
  ConnectionPoints_Method (void);

  // Constructor
  ConnectionPoints_Method (std::string &role);

	/// Destructor.
	~ConnectionPoints_Method (void);

  /**
   * evaluate method for evaluating the name method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Collection Value object
   */
  Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the name method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        Value from previous method
   * @return        Object        Collection Value object
   */
	Value * evaluate (Ocl_Context &res, Value *caller);

  /**
   * Determines if the object is for filtration or not.
   *
   * @return        bool          true if the object is for filtration
   *                              false if the object is not for filtration
   */
  bool is_filter (void);

private:
  std::string role_;
  int flag;
};

#endif //_GAME_MODEL_INTELLIGENCE_CONNECTIONPOINTS_METHOD_CALL_H_