// $Id$

#include "StdAfx.h"
#include "PICML_Manager_Addon.h"
#include "game/be/ComponentEx_T.h"

DECLARE_GAME_COMPONENT_EX (PICML_Manager_Impl, PICMLManager_Addon);

//
// PICML_Manager_Impl
//
PICML_Manager_Impl::PICML_Manager_Impl (void)
{

}

//
// ~PICML_Manager_Impl
//
PICML_Manager_Impl::~PICML_Manager_Impl (void)
{

}

//
// setImplementationFolder
//
STDMETHODIMP PICML_Manager_Impl::setImplementationFolder (BSTR folder)
{
  CW2A temp (folder);
  this->impl_.set_implementation_folder (temp.m_psz);

  return S_OK;
}

//
// setArtifactFolder
//
STDMETHODIMP PICML_Manager_Impl::setArtifactFolder (BSTR folder)
{
  CW2A temp (folder);
  this->impl_.set_artifact_folder (temp.m_psz);

  return S_OK;
}

STDMETHODIMP PICML_Manager_Impl::resetConfiguration (void)
{
  this->impl_.reset_configuration ();
  return S_OK;
}