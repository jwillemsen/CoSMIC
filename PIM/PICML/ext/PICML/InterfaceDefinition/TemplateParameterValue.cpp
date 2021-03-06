#include "StdAfx.h"
#include "TemplateParameterValue.h"

#if !defined (__GAME_INLINE__)
#include "TemplateParameterValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/TemplateParameterValueType.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TemplateParameterReference.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/PredefinedTypes/IntegerType.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "PICML/PredefinedTypes/LongDoubleNumber.h"
#include "PICML/PredefinedTypes/DoubleNumber.h"
#include "PICML/PredefinedTypes/FloatNumber.h"
#include "PICML/PredefinedTypes/TypeKind.h"
#include "PICML/PredefinedTypes/TypeEncoding.h"
#include "PICML/PredefinedTypes/GenericValue.h"
#include "PICML/PredefinedTypes/GenericValueObject.h"
#include "PICML/PredefinedTypes/GenericObject.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Collection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TemplateParameterValue_Impl::metaname ("TemplateParameterValue");

  //
  // is_abstract
  //
  const bool TemplateParameterValue_Impl::is_abstract = false;

  //
  // _create (const TemplatePackageInstance_in)
  //
  TemplateParameterValue TemplateParameterValue_Impl::_create (const TemplatePackageInstance_in parent)
  {
    return ::GAME::Mga::create < TemplateParameterValue > (parent, TemplateParameterValue_Impl::metaname);
  }

  //
  // accept
  //
  void TemplateParameterValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TemplateParameterValue (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TemplatePackageInstance
  //
  TemplatePackageInstance TemplateParameterValue_Impl::parent_TemplatePackageInstance (void)
  {
    return TemplatePackageInstance::_narrow (this->parent ());
  }

  //
  // TemplateParameterValueType_is_nil
  //
  bool TemplateParameterValue_Impl::TemplateParameterValueType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_TemplateParameterValueType
  //
  void TemplateParameterValue_Impl::refers_to_TemplateParameterValueType (TemplateParameterValueType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_TemplateParameterValueType
  //
  TemplateParameterValueType TemplateParameterValue_Impl::refers_to_TemplateParameterValueType (void) const
  {
    return TemplateParameterValueType::_narrow (this->refers_to ());
  }
}

