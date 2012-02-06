// $Id$

#if !defined (__GAME_INLINE__)
#include "Decorator_T.inl"
#endif

#include "game/mga/Exception.h"
#include "game/mga/Transaction.h"

#include <gdiplus.h>

namespace GAME
{
namespace Mga
{

//
// Initialize
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
Initialize (IMgaProject *project, IMgaMetaPart *part, IMgaFCO * fco)
{
  try
  {
    return this->InitializeEx (project, part, fco, 0, 0);
  }
  catch (...)
  {

  }

  return S_OK;
}

//
// InitializeEx
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
InitializeEx (IMgaProject* project,
              IMgaMetaPart* pPart,
              IMgaFCO* pFCO,
              IMgaCommonDecoratorEvents* sink,
              ULONGLONG window)
{
  try
  {
    // Reset the state variables.
    this->is_loc_set_ = false;
    this->is_init_ = false;

    int retval;
    GAME::Mga::Project proj (project);
    GAME::Mga::Meta::Part part (pPart);

    if (0 != pFCO)
    {
      // Initialize the decorator for the model view.
      GAME::Mga::FCO fco (pFCO);
      retval = this->impl_ptr_->initialize (proj, part, fco, sink, window);
    }
    else
    {
      // Initialize the decorator for the browser view.
      retval = this->impl_ptr_->initialize (proj, part, sink, window);
    }

    if (0 == retval)
      this->is_init_ = true;
  }
  catch (...)
  {

  }

  return S_OK;
}

//
// Destroy
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::Destroy (void)
{
  try
  {
    if (!this->is_init_)
      return E_DECORATOR_UNINITIALIZED;

    this->is_init_ = false;
    this->is_loc_set_ = false;

    this->impl_.destroy ();
    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// SetParam
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::SetParam (BSTR name, VARIANT value)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return E_DECORATOR_UNKNOWN_PARAMETER;
}

//
// GetParam
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetParam (BSTR name, VARIANT* value)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return E_DECORATOR_UNKNOWN_PARAMETER;
}

//
// GetLocation
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
GetLocation (long *sx, long *sy, long *ex, long *ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    const GAME::Mga::Rect & location = this->impl_.get_location ();
    *sx = location.x_;
    *sy = location.y_;
    *ex = location.cx_;
    *ey = location.cy_;

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// GetPortLocation
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
GetPortLocation (IMgaFCO *pFCO, long *sx, long *sy, long *ex, long *ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    port_map_t::iterator iter = this->ports_.find (pFCO);

    if (iter != this->ports_.end ())
    {
      *sx = iter->second.x_;
      *sy = iter->second.y_;
      *ex = iter->second.cx_;
      *ey = iter->second.cy_;
    }
    else
    {
      // Since there is no guarantee that this method is called within
      // a transactions, we are going to wrap the object in an implementation.
      GAME::Mga::FCO fco (pFCO);
      int retval = this->impl_.get_port_location (fco,
                                                  *sx,
                                                  *sy,
                                                  *ex,
                                                  *ey);

      if (0 != retval)
        return E_DECORATOR_PORTNOTFOUND;

      // Get the object's current location.
      const GAME::Mga::Rect & loc = this->impl_.get_location ();

      // Convert the locations into relative locations.
      *sx -= loc.x_;
      *sy -= loc.y_;
      *ex -= loc.x_;
      *ey -= loc.y_;

      // Save the port's location for later.
      this->ports_[pFCO] = GAME::Mga::Rect (*sx, *sy, *ex, *ey);
    }

    return S_OK;
  }
  catch (...)
  {

  }

  return E_DECORATOR_PORTNOTFOUND;
}

//
// GetPorts
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetPorts (IMgaFCOs **portFCOs)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  try
  {
    // First, let's get the ports for the FCO
    ATL::CComPtr <IMgaFCOs> temp;
    VERIFY_HRESULT (temp.CoCreateInstance (L"Mga.MgaFCOs"));

    std::vector <FCO> ports;
    if (0 != this->impl_.get_ports (ports))
      return S_FALSE;

    std::vector <FCO>::const_iterator
      iter = ports.begin (), iter_end = ports.end ();

    for (; iter != iter_end; ++ iter)
    {
      try
      {
        VERIFY_HRESULT (temp->Append ((*iter)->impl ()));
      }
      catch (const GAME::Mga::Failed_Result & )
      {

      }
    }

    // Return the collection to the client.
    *portFCOs = temp.Detach ();

    // Clear the cached ports.
    if (!this->ports_.empty ())
      this->ports_.clear ();

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// MouseMoved
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMoved (ULONG flags,
            LONG px,
            LONG py,
            ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  CDC context;

  try
  {
    HDC hdc = reinterpret_cast <HDC> (transformHDC);
    context.Attach (hdc);

    int retval = this->impl_.mouse_moved (flags, GAME::Mga::Point (px, py), context);

    // Make sure we release the context.
    context.Detach ();
    return retval;
  }
  catch (...)
  {
    context.Detach ();
  }

  return S_FALSE;
}

//
// MouseLeftButtonDown
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseLeftButtonDown (ULONG flags,
                     LONG px,
                     LONG py,
                     ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_left_button_down (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseLeftButtonUp
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseLeftButtonUp (ULONG flags,
                   LONG px,
                   LONG py,
                   ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_left_button_up (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseLeftButtonDoubleClick
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseLeftButtonDoubleClick (ULONG flags,
                            LONG px,
                            LONG py,
                            ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_left_button_double_click (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseRightButtonDown
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseRightButtonDown (ULONGLONG hCtxMenu,
                      ULONG flags,
                      LONG px,
                      LONG py,
                      ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HMENU menu = reinterpret_cast <HMENU> (hCtxMenu);
  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  CMenu context_menu;

  context.Attach (hdc);
  context_menu.Attach (menu);

  int retval = this->impl_.mouse_right_button_down (context_menu,
                                                    flags,
                                                    GAME::Mga::Point (px, py),
                                                    context);

  // Make sure we release the context.
  context.Detach ();
  context_menu.Detach ();

  return retval;
}

//
// MouseRightButtonUp
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseRightButtonUp (ULONG flags,
                    LONG px,
                    LONG py,
                    ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_right_button_up (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseRightButtonDoubleClick
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseRightButtonDoubleClick (ULONG flags,
                             LONG px,
                             LONG py,
                             ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_right_button_double_click (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseMiddleButtonDown
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMiddleButtonDown (ULONG flags,
                       LONG px,
                       LONG py,
                       ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_middle_button_down (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseMiddleButtonUp
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMiddleButtonUp (ULONG flags,
                     LONG px,
                     LONG py,
                     ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_middle_button_up (flags, GAME::Mga::Point (px, py), context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseMiddleButtonDoubleClick
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseMiddleButtonDoubleClick (ULONG flags,
                              LONG px,
                              LONG py,
                              ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_middle_button_double_click (flags,
                                                             GAME::Mga::Point (px, py),
                                                             context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MouseWheelTurned
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MouseWheelTurned (ULONG flags,
                  LONG distance,
                  LONG px,
                  LONG py,
                  ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.mouse_wheel_turned (flags,
                                               distance,
                                               GAME::Mga::Point (px, py),
                                               context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// DragEnter
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
DragEnter (ULONG* effect,
           ULONGLONG pCOleDataObject,
           ULONG keystate,
           LONG px,
           LONG py,
           ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  COleDataObject * data_object = reinterpret_cast <COleDataObject *> (pCOleDataObject);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drag_enter (*effect,
                                       *data_object,
                                       keystate,
                                       GAME::Mga::Point (px, py),
                                       context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// DragOver
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
DragOver (ULONG* effect,
          ULONGLONG pCOleDataObject,
          ULONG keystate,
          LONG px,
          LONG py,
          ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  COleDataObject * data_object = reinterpret_cast <COleDataObject *> (pCOleDataObject);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drag_over (*effect,
                                      *data_object,
                                      keystate,
                                      GAME::Mga::Point (px, py),
                                      context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// Drop
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
Drop (ULONGLONG pCOleDataObject,
      ULONG drop_effect,
      LONG px,
      LONG py,
      ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);
  COleDataObject * data_object = reinterpret_cast <COleDataObject *> (pCOleDataObject);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drop (*data_object,
                                 drop_effect,
                                 GAME::Mga::Point (px, py),
                                 context);

  context.Detach ();

  return retval;
}

//
// DropFile
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
DropFile (ULONGLONG drop_info,
          LONG px,
          LONG py,
          ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.drop_file (drop_info,
                                      GAME::Mga::Point (px, py),
                                      context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

//
// MenuItemSelected
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::
MenuItemSelected (ULONG menuItemId,
                  ULONG flags,
                  LONG px,
                  LONG py,
                  ULONGLONG transformHDC)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  HDC hdc = reinterpret_cast <HDC> (transformHDC);

  CDC context;
  context.Attach (hdc);

  int retval = this->impl_.menu_item_selected (menuItemId,
                                               flags,
                                               GAME::Mga::Point (px, py),
                                               context);

  // Make sure we release the context.
  context.Detach ();

  return retval;
}

}
}
