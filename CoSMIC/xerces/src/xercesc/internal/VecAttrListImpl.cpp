/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2002 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log$
 * Revision 1.1  2004/03/22 23:43:25  kitty
 * Initial revision
 *
 * Revision 1.7  2003/12/17 00:18:34  cargilld
 * Update to memory management so that the static memory manager (one used to call Initialize) is only for static data.
 *
 * Revision 1.6  2003/05/15 18:26:29  knoaman
 * Partial implementation of the configurable memory manager.
 *
 * Revision 1.5  2002/11/04 14:58:18  tng
 * C++ Namespace Support.
 *
 * Revision 1.4  2002/09/24 20:02:20  tng
 * Performance: use XMLString::equals instead of XMLString::compareString
 *
 * Revision 1.3  2002/07/05 20:12:35  tng
 * [Bug 9788] VecAttrListImpl::getValue skips prefix if SAX namespace validation is on.
 *
 * Revision 1.2  2002/02/27 16:49:40  tng
 * Fix: AttributeList::getName should attach prefix if present
 *
 * Revision 1.1.1.1  2002/02/01 22:21:58  peiyongz
 * sane_include
 *
 * Revision 1.6  2000/11/02 01:14:07  andyh
 * SAX bug fix:  Attribute lists were throwing exceptions rather than returning
 * null when an attribute could not be found by name.  Fixed by Tinny Ng.
 *
 * Revision 1.5  2000/03/13 20:19:11  rahulj
 * Fixed #54. Changed self-assignment to now use the parameter value.
 * Reported by Helmut Eiken <H.Eiken@cli.de>
 *
 * Revision 1.4  2000/03/02 19:54:29  roddey
 * This checkin includes many changes done while waiting for the
 * 1.1.0 code to be finished. I can't list them all here, but a list is
 * available elsewhere.
 *
 * Revision 1.3  2000/02/06 07:47:53  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.2  1999/12/15 19:49:37  roddey
 * Added second getValue() method which takes a short name for the attribute
 * to get the value for. Just a convenience method.
 *
 * Revision 1.1.1.1  1999/11/09 01:08:19  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:44:44  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/Janitor.hpp>
#include <xercesc/internal/VecAttrListImpl.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  Constructors and Destructor
// ---------------------------------------------------------------------------
VecAttrListImpl::VecAttrListImpl() :

    fAdopt(false)
    , fCount(0)
    , fVector(0)
{
}

VecAttrListImpl::~VecAttrListImpl()
{
    //
    //  Note that some compilers can't deal with the fact that the pointer
    //  is to a const object, so we have to cast off the const'ness here!
    //
    if (fAdopt)
        delete (RefVectorOf<XMLAttr>*)fVector;
}


// ---------------------------------------------------------------------------
//  Implementation of the attribute list interface
// ---------------------------------------------------------------------------
unsigned int VecAttrListImpl::getLength() const
{
    return fCount;
}

const XMLCh* VecAttrListImpl::getName(const unsigned int index) const
{
    if (index >= fCount) {
        return 0;
    }
    return fVector->elementAt(index)->getQName();
}

const XMLCh* VecAttrListImpl::getType(const unsigned int index) const
{
    if (index >= fCount) {
        return 0;
    }
    return XMLAttDef::getAttTypeString(fVector->elementAt(index)->getType(), fVector->getMemoryManager());
}

const XMLCh* VecAttrListImpl::getValue(const unsigned int index) const
{
    if (index >= fCount) {
        return 0;
    }
    return fVector->elementAt(index)->getValue();
}

const XMLCh* VecAttrListImpl::getType(const XMLCh* const name) const
{
    //
    //  Search the vector for the attribute with the given name and return
    //  its type.
    //
    for (unsigned int index = 0; index < fCount; index++)
    {
        const XMLAttr* curElem = fVector->elementAt(index);

        if (XMLString::equals(curElem->getQName(), name))
            return XMLAttDef::getAttTypeString(curElem->getType(), fVector->getMemoryManager());
    }
    return 0;
}

const XMLCh* VecAttrListImpl::getValue(const XMLCh* const name) const
{
    //
    //  Search the vector for the attribute with the given name and return
    //  its type.
    //
    for (unsigned int index = 0; index < fCount; index++)
    {
        const XMLAttr* curElem = fVector->elementAt(index);

        if (XMLString::equals(curElem->getQName(), name))
            return curElem->getValue();
    }
    return 0;
}

const XMLCh* VecAttrListImpl::getValue(const char* const name) const
{
    // Temporarily transcode the name for lookup
    XMLCh* wideName = XMLString::transcode(name, XMLPlatformUtils::fgMemoryManager);
    ArrayJanitor<XMLCh> janName(wideName, XMLPlatformUtils::fgMemoryManager);

    //
    //  Search the vector for the attribute with the given name and return
    //  its type.
    //
    for (unsigned int index = 0; index < fCount; index++)
    {
        const XMLAttr* curElem = fVector->elementAt(index);

        if (XMLString::equals(curElem->getQName(), wideName))
            return curElem->getValue();
    }
    return 0;
}



// ---------------------------------------------------------------------------
//  Setter methods
// ---------------------------------------------------------------------------
void VecAttrListImpl::setVector(const   RefVectorOf<XMLAttr>* const srcVec
                                , const unsigned int                count
                                , const bool                        adopt)
{
    //
    //  Delete the previous vector (if any) if we are adopting. Note that some
    //  compilers can't deal with the fact that the pointer is to a const
    //  object, so we have to cast off the const'ness here!
    //
    if (fAdopt)
        delete (RefVectorOf<XMLAttr>*)fVector;

    fAdopt = adopt;
    fCount = count;
    fVector = srcVec;
}

XERCES_CPP_NAMESPACE_END
