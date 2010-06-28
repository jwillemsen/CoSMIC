// -*- C++ -*-

//=============================================================================
/**
 *  @file       Selection_List_Dialog.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_SELECTION_LIST_DIALOG_H_
#define _GAME_SELECTION_LIST_DIALOG_H_

#include <vector>
#include <afxwin.h>

namespace GAME
{
namespace Dialogs
{
/**
 * @class Selection_List_Dialog
 *
 * Simple dialog that shows a list of elements. 
 */
template <typename T>
class Selection_List_Dialog : public CDialog
{
public:
  /// Type definition of the value type.
  typedef T value_type;

  /// Type definition for the list of elements.
  typedef std::vector <T> items_type;

  /**
   * Initializing constructor.
   *
   * @param[in]     items       Initial items for the dialog
   * @param[in]     parent      Parent of the dialog
   */
  Selection_List_Dialog (const items_type & items,  CWnd * parent = 0);

  /// Destructor.
  virtual ~Selection_List_Dialog (void);

  /**
   * Get the selected string from the dialog.
   *
   * @return        The selected string value.
   */
  T selection (void) const;

  void title (const char * str);

protected:
  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  virtual void DoDataExchange (CDataExchange * pDX);

  virtual BOOL OnInitDialog (void);

private:
  /// The selected string from the dialog.
  int index_;

  /// The list control for the dialog.
  CListBox list_;

  /// Collection of strings to display.
  const items_type & items_;

  /// Title of the dialog box.
  std::string title_;
};

}
}

#include "Selection_List_Dialog.cpp"

#endif  // !defined _GAME_SELECTION_LIST_DIALOG_H_