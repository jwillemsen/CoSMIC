// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // Folder_Model_T
  //
  template <typename T, typename BASE>
  GME_INLINE
  Folder_Model_T <T, BASE>::Folder_Model_T (void)

  {

  }

  //
  // Folder_Model_T
  //
  template <typename T, typename BASE>
  GME_INLINE
  Folder_Model_T <T, BASE>::Folder_Model_T (T * type)
  : BASE (type)
  {

  }

  //
  // Folder_Model_T
  //
  template <typename T, typename BASE>
  GME_INLINE
  Folder_Model_T <T, BASE>::
  Folder_Model_T (const Folder_Model_T & type)
  : BASE (type)
  {

  }

  //
  // Folder_Model_T
  //
  template <typename T, typename BASE>
  GME_INLINE
  Folder_Model_T <T, BASE>::~Folder_Model_T (void)
  {

  }

  //
  // fcos
  //
  template <typename T, typename BASE>
  GME_INLINE
  size_t Folder_Model_T <T, BASE>::
  fcos (const std::string & type,
        GME::Collection_T <FCO> & fcos) const
  {
    return this->get_children (type, fcos);
  }

  //
  // models
  //
  template <typename T, typename BASE>
  GME_INLINE
  size_t Folder_Model_T <T, BASE>::
  models (const std::string & type,
          GME::Collection_T <Model> & models) const
  {
    return this->get_children (type, models);
  }

  //
  // atoms
  //
  template <typename T, typename BASE>
  GME_INLINE
  size_t Folder_Model_T <T, BASE>::
  atoms (const std::string & type,
         GME::Collection_T <Atom> & atoms) const
  {
    return this->get_children (type, atoms);
  }

  //
  // sets
  //
  template <typename T, typename BASE>
  GME_INLINE
  size_t Folder_Model_T <T, BASE>::
  sets (const std::string & type,
        GME::Collection_T <Set> & sets) const
  {
    return this->get_children (type, sets);
  }

  //
  // references
  //
  template <typename T, typename BASE>
  GME_INLINE
  size_t Folder_Model_T <T, BASE>::
  references (const std::string & type,
              GME::Collection_T <Reference> & refs) const
  {
    return this->get_children (type, refs);
  }

  //
  // attach
  //
  template <typename T, typename BASE>
  GME_INLINE
  void Folder_Model_T <T, BASE>::attach (T * type)
  {
    BASE::attach (type);
  }
}