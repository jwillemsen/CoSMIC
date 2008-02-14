// $Id$

#if !defined (__GME_INLINE__)
#include "Collection_T.inl"
#endif

#include "Exception.h"

namespace GME
{
//
// populate
//
template <typename T>
void Collection_T <T>::populate (void)
{
  // Resize the <items_> to the size of the <collection_>.
  long count;
  this->collection_->get_Count (&count);
  this->items_.resize (count);

  if (count > 0)
  {
    // Get the interface to all the members.
    typedef typename collection_traits <
      typename item_traits <T>::collection_type>::
      interface_type interface_type;

    CComPtr <interface_type> * array =
      new CComPtr <interface_type> [count];

    VERIFY_HRESULT (this->collection_->GetAll (count, &(*array)));

    // Store the members in a collection.
    typename T::interface_type * temp = 0;

    for (long i = 0; i < count; i ++)
    {
      array[i].QueryInterface (&temp);
      this->items_[i].attach (temp);

      temp = 0;
    }

    // Release the temp storage.
    delete [] array;
  }
}

}
