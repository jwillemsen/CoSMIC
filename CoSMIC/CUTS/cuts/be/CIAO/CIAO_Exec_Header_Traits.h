// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Exec_Header_Traits.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_EXEC_HEADER_TRAITS_H_
#define _CUTS_CIAO_EXEC_HEADER_TRAITS_H_

#include "CIAO_Header_Traits.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Exec_Header_Traits
 *
 * CIAO header file generator for the CUTS-PICML backend.
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_CIAO_Exec_Header_Traits :
  public CUTS_CIAO_Header_Traits
{
public:
  /// Type definition of the super class.
  typedef CUTS_CIAO_Header_Traits _super;

  CUTS_CIAO_Exec_Header_Traits (void);

  virtual ~CUTS_CIAO_Exec_Header_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_prologue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_epilogue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_includes (
    const CUTS_String_Set & includes);

  void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  void write_impl_end (
    const PICML::MonolithicImplementation &,
    const PICML::Component & type);

  virtual void write_factory_begin (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_factory_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_environment_begin (
    const PICML::Component & component);

  virtual void write_environment_method_begin (
    const PICML::InputAction & action);

  virtual void write_method_begin (
    const PICML::InEventPort & sink);

  virtual void write_method_end (
    const PICML::InEventPort & sink);

  virtual void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_begin (
    const PICML::Attribute & attr);

  virtual void write_method_end (
    const PICML::Attribute & attr);

  virtual void write_method_begin (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_method_end (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_variables_begin (
    const PICML::Component & component);

  virtual void write_variable (
    const PICML::Variable & variable);

  virtual void write_variable (
    const PICML::PeriodicEvent & periodic);

  virtual void write_variable (
    const PICML::WorkerType & type,
    const PICML::Worker & worker);

  virtual void write_variable (
    const PICML::ReadonlyAttribute & readonly);

protected:
private:
  /// Type definition for pointer-to-methods to environment methods.
  typedef void (CUTS_CIAO_Exec_Header_Traits::
    *Environment_Method) (const PICML::Component &);

  /// Type definition for environment jump table.
  typedef std::map <std::string,
                    Environment_Method> Environment_Table;

  /// Global jump table for the environment writers.
  static Environment_Table env_table_;
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Exec_Header_Traits.inl"
#endif

#endif  // !defined _CUTS_CIAO_EXEC_HEADER_TRAITS_H_