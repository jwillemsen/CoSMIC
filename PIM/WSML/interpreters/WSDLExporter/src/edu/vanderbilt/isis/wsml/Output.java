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
 * Domain specific class of <code>Output</code>.
 */
public class Output extends MgaObject
{
	// meta information
	public static final String META_TYPE = "Output";
	public static final String META_TYPE_NS = "";
	private static UdmPseudoObject metaClass;

	/**
	 * Constructor.
	 * @param  upo The object that helps the initialization of the instance
	 * @param  metaDiagram The diagram of the data network
	 * @throws  UdmException If any Udm related exception occured
	 */
	protected Output(UdmPseudoObject upo, Diagram metaDiagram)
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
	 * @return  An instance of the class <code>Output</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static Output create(SolicitResponseOperation parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Output(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/**
	 * Creates an instance of the class in the container specified by the parameter.
	 * @param  parent The parent container
	 * @return  An instance of the class <code>Output</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static Output create(NotificationOperation parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Output(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/**
	 * Creates an instance of the class in the container specified by the parameter.
	 * @param  parent The parent container
	 * @return  An instance of the class <code>Output</code>
	 * @throws  UdmException If any Udm related exception occured
	 */
	public static Output create(RequestResponseOperation parent)
		throws UdmException
	{
		Diagram metaDiagram = parent.getDiagram();
		return new Output(parent.createObject(META_TYPE, META_TYPE_NS), metaDiagram);
	}

	/* Accessing children */

	/**
	 * Returns all the children of type <code>Documentation<code> of this container.
	 * @return  The children in an array
	 * @throws  UdmException If any Udm related exception occured
	 */
	public Documentation[] getDocumentationChildren()
		throws UdmException
	{
		UdmPseudoObjectContainer container = getChildren(null, Documentation.META_TYPE, Documentation.META_TYPE_NS);
		Documentation[] res = new Documentation[container.getLength()];
		for (int i=0; i < container.getLength(); i++)
		{
			res[i] = (Documentation)Utils.wrapWithSubclass(container.getAt(i), metaDiagram);
		}
		return res;
	}

	/* Attribute setters, getters */

	/* Associations */

	/*
	 * Asoociation with role name <code>referedbyOutputRef</code>.
	 */

	/**
	 * Sets the other end of the association with role name <code>referedbyOutputRef</code>.
	 * @param a The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */
	public void setreferedbyOutputRef(OutputRef a)
		throws UdmException
	{
		setAssociation("referedbyOutputRef", a, UdmHelper.TARGET_FROM_PEER);
	}

	/**
	 * Returns the other end of the association with role name <code>referedbyOutputRef</code>.
	 * @return The other end of the association
	 * @throws  UdmException If any Udm related exception occured
	 */
	public OutputRef getreferedbyOutputRef()
		throws UdmException
	{
		UdmPseudoObject result = getSingleAssociatedObject("referedbyOutputRef", UdmHelper.TARGET_FROM_PEER);
		return (result == null) ? null : new OutputRef(result, getDiagram());
	}

	/*
	 * Asoociation with role name <code>dstOutputMessage</code>.
	 */

	/**
	 * Sets the other ends of the association with role name <code>dstOutputMessage</code>.
	 * @param a The other ends of the association
	 * @throws  UdmException If any Udm related exception occured
	 */
	public void setdstOutputMessage(OutputMessage[] a)
		throws UdmException
	{
		setAssociation("dstOutputMessage", new UdmPseudoObjectContainer(a), UdmHelper.CLASS_FROM_TARGET);
	}

	/**
	 * Returns the other ends of the association with role name <code>dstOutputMessage</code>.
	 * @return The other ends of the association
	 * @throws  UdmException If any Udm related exception occured
	 */
	public OutputMessage[] getdstOutputMessage()
		throws UdmException
	{
		UdmPseudoObjectContainer objs = getAssociation("dstOutputMessage", UdmHelper.CLASS_FROM_TARGET);
		return (OutputMessage[]) Utils.wrapWithSubclass(objs, OutputMessage.class, getDiagram());
	}

}
