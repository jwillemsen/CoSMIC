// $Id: idl_to_wsdl_visitor.h,v 1.3 2006/02/09 16:51:07 parsons Exp $

/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    IDL_TO_WSDL_BE_DLL
//
// = FILENAME
//    idl_to_wsdl_visitor.h
//
// = DESCRIPTION
//    The WSDL translator visitor base class.
//
// = AUTHOR
//    Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#ifndef IDL_TO_WSDL_VISITOR_H
#define IDL_TO_WSDL_VISITOR_H

#include "ast_visitor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/SString.h"

#include <xercesc/dom/DOM.hpp>

using namespace xercesc;

class idl_to_wsdl_visitor : public ast_visitor
{
  //
  // = TITLE
  //    idl_to_wsdl_visitor.
  //
  // = DESCRIPTION
  //    IDL to WSDL conversion visitor base class.
  //
public:
  idl_to_wsdl_visitor (DOMElement *sub_tree);
  virtual ~idl_to_wsdl_visitor (void);

  virtual int visit_decl (AST_Decl *d);
  virtual int visit_scope (UTL_Scope *node);
  virtual int visit_type (AST_Type *node);
  virtual int visit_predefined_type (AST_PredefinedType *node);
  virtual int visit_module (AST_Module *node);
  virtual int visit_interface (AST_Interface *node);
  virtual int visit_interface_fwd (AST_InterfaceFwd *node);
  virtual int visit_valuebox (AST_ValueBox *node);
  virtual int visit_valuetype (AST_ValueType *node);
  virtual int visit_valuetype_fwd (AST_ValueTypeFwd *node);
  virtual int visit_component (AST_Component *node);
  virtual int visit_component_fwd (AST_ComponentFwd *node);
  virtual int visit_eventtype (AST_EventType *node);
  virtual int visit_eventtype_fwd (AST_EventTypeFwd *node);
  virtual int visit_home (AST_Home *node);
  virtual int visit_factory (AST_Factory *node);
  virtual int visit_structure (AST_Structure *node);
  virtual int visit_structure_fwd (AST_StructureFwd *node);
  virtual int visit_exception (AST_Exception *node);
  virtual int visit_expression (AST_Expression *node);
  virtual int visit_enum (AST_Enum *node);
  virtual int visit_operation (AST_Operation *node);
  virtual int visit_field (AST_Field *node);
  virtual int visit_argument (AST_Argument *node);
  virtual int visit_attribute (AST_Attribute *node);
  virtual int visit_union (AST_Union *node);
  virtual int visit_union_fwd (AST_UnionFwd *node);
  virtual int visit_union_branch (AST_UnionBranch *node);
  virtual int visit_union_label (AST_UnionLabel *node);
  virtual int visit_constant (AST_Constant *node);
  virtual int visit_enum_val (AST_EnumVal *node);
  virtual int visit_array (AST_Array *node);
  virtual int visit_sequence (AST_Sequence *node);
  virtual int visit_string (AST_String *node);
  virtual int visit_typedef (AST_Typedef *node);
  virtual int visit_root (AST_Root *node);
  virtual int visit_native (AST_Native *node);

protected:
  void type_name (ACE_CString &name, AST_Decl *d, bool as_ref = true);
  DOMElement *process_node (AST_Decl *node, const char *tag_name);

protected:
  enum NodeStatus
  {
    NOT_SEEN,
    IN_DOM_TREE,
    FWD_DECL,
    DONE
  };
 
  NodeStatus node_status_;
  DOMElement *sub_tree_;
  DOMDocument *doc_;
};

#endif /* IDL_TO_WSDL_VISITOR_H */
