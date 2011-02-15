// $Id$

#include "Collection_T.h"

namespace GAME
{
namespace Mga
{

namespace assert
{
/**
 * @struct element_not_containable_in_model
 *
 * Assertion that determines if an implementation is containable in
 * a model. This will prevent clients from requesting children of type
 * Folder from a model.
 */
template <typename T>
struct element_not_containable_in_folder;

template < >
struct element_not_containable_in_folder <object_tag_t>
{
  static const bool result_type = false;
};

template < >
struct element_not_containable_in_folder <folder_tag_t>
{
  static const bool result_type = false;
};

template < >
struct element_not_containable_in_folder <fco_tag_t>
{
  static const bool result_type = false;
};

template < >
struct element_not_containable_in_folder <atom_tag_t>
{
  static const bool result_type = false;
};

template < >
struct element_not_containable_in_folder <model_tag_t>
{
  static const bool result_type = false;
};

}

//
// children
//
template <typename T>
size_t Folder_Impl::children (std::vector <T> & children) const
{
  typedef typename T::impl_type impl_type;
  assert::element_not_containable_in_folder <impl_type::type_tag>::result_type;

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
template <typename T>
size_t Folder_Impl::
children (const std::string & type, std::vector <T> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

}
}
