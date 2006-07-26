package edu.vanderbilt.isis.meta;



public class WSML_xsd_1 {
	private static String str = new String();

	public static String getString()
	{
		if (str.length() == 0)
		{
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"FaultType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"referedbyFaultRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"dstFaultMessage\" type=\"xsd:IDREF\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"OutputRefType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstBodyBinding\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"dstHeaderBinding\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"NotificationOperationType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"FaultMessage\" type=\"FaultMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"InputMessage\" type=\"InputMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"MessageRef\" type=\"MessageRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Output\" type=\"OutputType\"/>\n";
			str +="			<xsd:element name=\"OutputMessage\" type=\"OutputMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"referedbyOperationRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"FaultRefType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstSOAPFaultExtension\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"InputMessageType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstInputMessage_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcInputMessage_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"FaultMessageType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"srcFaultMessage_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"dstFaultMessage_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"OneWayOperationType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"FaultMessage\" type=\"FaultMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Input\" type=\"InputType\"/>\n";
			str +="			<xsd:element name=\"InputMessage\" type=\"InputMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"MessageRef\" type=\"MessageRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"OutputMessage\" type=\"OutputMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"referedbyOperationRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"MessageRefType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"srcHeaderMessage\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"srcFaultMessage\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcOutputMessage\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"srcInputMessage\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"OutputType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"referedbyOutputRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"dstOutputMessage\" type=\"xsd:IDREF\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"InputType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"referedbyInputRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"dstInputMessage\" type=\"xsd:IDREF\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"MessagesType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Message\" type=\"MessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"DefinitionsType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Attribute\" type=\"AttributeType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Binding\" type=\"BindingType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"BindingPortType\" type=\"BindingPortTypeType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"Import\" type=\"ImportType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Messages\" type=\"MessagesType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"PortType\" type=\"PortTypeType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Service\" type=\"ServiceType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Types\" type=\"TypesType\" minOccurs=\"0\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"targetNamespace\" type=\"xsd:string\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"TypesType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"Schema\" type=\"SchemaType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"MessageType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Part\" type=\"PartType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"referedbyMessageRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"PortTypeType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"NotificationOperation\" type=\"NotificationOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"OneWayOperation\" type=\"OneWayOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"RequestResponseOperation\" type=\"RequestResponseOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SolicitResponseOperation\" type=\"SolicitResponseOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"srcBindingPortType\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"PartType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"referedbyPartRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"BindingType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"BindingOperation\" type=\"BindingOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"BindsOperation\" type=\"BindsOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"OperationRef\" type=\"OperationRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPBinding\" type=\"SOAPBindingType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstBindingPortType\" type=\"xsd:IDREF\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"referedbyBindingRef\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"DocumentationType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Element\" type=\"ElementType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"Mixed\" type=\"xsd:boolean\" default=\"false\"/>\n";
			str +="		<xsd:attribute name=\"DocText\" type=\"xsd:string\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"BindingPortTypeType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstBindingPortType_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcBindingPortType_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"PortType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"SOAPAddress\" type=\"SOAPAddressType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstPortBinding\" type=\"xsd:IDREF\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"ServiceType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"BindingRef\" type=\"BindingRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Port\" type=\"PortType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"PortBinding\" type=\"PortBindingType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"PortBindingType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstPortBinding_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcPortBinding_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"BindingOperationType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"BodyBinding\" type=\"BodyBindingType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"BodyParts\" type=\"BodyPartsType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"FaultRef\" type=\"FaultRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"HeaderBinding\" type=\"HeaderBindingType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"HeaderMessage\" type=\"HeaderMessageType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"HeaderPart\" type=\"HeaderPartType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"InputRef\" type=\"InputRefType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"MessageRef\" type=\"MessageRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"OutputRef\" type=\"OutputRefType\" minOccurs=\"0\"/>\n";
			str +="			<xsd:element name=\"PartRef\" type=\"PartRefType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPBody\" type=\"SOAPBodyType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPFault\" type=\"SOAPFaultType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPFaultExtension\" type=\"SOAPFaultExtensionType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPHeader\" type=\"SOAPHeaderType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPHeaderFault\" type=\"SOAPHeaderFaultType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SOAPOperation\" type=\"SOAPOperationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstBindsOperation\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"PartRefType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"srcHeaderPart\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"srcBodyParts\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"OperationRefType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcBindsOperation\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"ImportType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Definitions\" type=\"DefinitionsType\"/>\n";
			str +="			<xsd:element name=\"Documentation\" type=\"DocumentationType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"namespace\" type=\"xsd:string\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"location\" type=\"xsd:string\" use=\"required\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"BindingRefType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"ref\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcPortBinding\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"BindsOperationType\">\n";
			str +="		<xsd:attribute name=\"position\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"dstBindsOperation_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"srcBindsOperation_end_\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +="	<xsd:complexType name=\"RootFolderType\">\n";
			str +="		<xsd:sequence>\n";
			str +="			<xsd:element name=\"Definitions\" type=\"DefinitionsType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"RootFolder\" type=\"RootFolderType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"Schema\" type=\"SchemaType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="			<xsd:element name=\"SchemaBuiltins\" type=\"SchemaBuiltinsType\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>\n";
			str +="		</xsd:sequence>\n";
			str +="		<xsd:attribute name=\"name\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_id\" type=\"xsd:ID\"/>\n";
			str +="		<xsd:attribute name=\"_archetype\" type=\"xsd:IDREF\"/>\n";
			str +="		<xsd:attribute name=\"_derived\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_instances\" type=\"xsd:IDREFS\"/>\n";
			str +="		<xsd:attribute name=\"_desynched_atts\" type=\"xsd:string\"/>\n";
			str +="		<xsd:attribute name=\"_real_archetype\" type=\"xsd:boolean\"/>\n";
			str +="		<xsd:attribute name=\"_subtype\" type=\"xsd:boolean\"/>\n";
			str +="	</xsd:complexType>\n";
			str +="\n";
			str +=" <xsd:element name=\"RootFolder\" type=\"RootFolderType\"/>\n";
			str +="\n";
			str +="</xsd:schema>\n";
			str +="\n";
		}
		return str;
	}
}
