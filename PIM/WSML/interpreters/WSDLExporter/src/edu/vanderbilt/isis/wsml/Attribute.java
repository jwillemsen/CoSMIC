/* Generated on Tue Jul 17 20:35:06 2007 */

/* This is a generalt file, do not modify its content.
 * Copyright (c) Vanderbilt University, 2000-2005
 * ALL RIGHTS RESERVED
 * Vanderbilt University disclaims all warranties with regard to this
 * software, including all implied warranties of merchantability and
 * fitness.  In no event shall Vanderbilt University be liable for any
 * special, indirect or consequential damages or any damages whatsoever
 * resulting from loss of use, data or profits, whether in an action of
 * contract, negligence or other tortious action, arising out of or in
 * connection with the use or performance of this software.	
 */

package edu.vanderbilt.isis.wsml;

import edu.vanderbilt.isis.udm.*;

/**
 * Domain specific class of <code>Attribute</code>.
 */
public class Attribute extends MgaObject
{
	// meta information
	public static final String META_TYPE = "Attribute";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */
	protected Attribute(UdmPseudoObject upo, Diagram metaDiagram)
		throws UdmException
	{
		super(upo, metaDiagram);
	}

	/**
	 * Returns the meta class.
	 * @return  The meta class
	 */
	UdmPseudoObject getMetaClass()
	{
		return metaClass;
	}

	/* Construction */

	/**
	 * Creates an instance of the class in the container specified by the parameter.
	 * @param  parent The parent container
	 * @return  An instance of the class <code>Attribute</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static Attribute create(Definitions parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Attribute(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/**
	 * Creates an instance of the class in the container specified by the parameter.
	 * @param  parent The parent container
	 * @return  An instance of the class <code>Attribute</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static Attribute create(Schema parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Attribute(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/**
	 * Creates an instance of the class in the container specified by the parameter.
	 * @param  parent The parent container
	 * @return  An instance of the class <code>Attribute</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static Attribute create(Element parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Attribute(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/* Attribute setters, getters */

	/**
	 * Attribute for <code>Value</code>.
	 */
	public static final String Value = "Value";

	/**
	 * Sets the value of the attribute <code>Value</code> to a value specified by the parameter.
	 * @param _v The new value of the attribute
	 * @throws  UdmException If any Udm related exception occured
	 */
	public void setValue(String _v)
		throws UdmException
	{
		setStringVal(Value, _v);
	}

	/**
	 * Returns the value of the attribute <code>Value</code>.
	 * @return  The value
	 * @throws  UdmException If any Udm related exception occured
	 */
	public String getValue()
		throws UdmException
	{
		return getStringVal(Value);
	}

	/* Associations */

}
