/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001-2002 The Apache Software Foundation.  All rights
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
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log$
 * Revision 1.1  2004/03/22 23:43:27  kitty
 * Initial revision
 *
 * Revision 1.21  2004/01/29 11:52:31  cargilld
 * Code cleanup changes to get rid of various compiler diagnostic messages.
 *
 * Revision 1.20  2004/01/13 16:17:09  knoaman
 * Fo sanity, use class name to qualify method
 *
 * Revision 1.19  2004/01/09 22:41:58  knoaman
 * Use a global static mutex for locking when creating local static mutexes instead of compareAndSwap
 *
 * Revision 1.18  2003/12/17 00:18:40  cargilld
 * Update to memory management so that the static memory manager (one used to call Initialize) is only for static data.
 *
 * Revision 1.17  2003/12/11 19:26:27  knoaman
 * Store non schema attributes from parent in XSAnnotation
 *
 * Revision 1.16  2003/11/12 20:35:31  peiyongz
 * Stateless Grammar: ValidationContext
 *
 * Revision 1.15  2003/10/20 15:57:22  knoaman
 * Fix multithreading problem.
 *
 * Revision 1.14  2003/10/01 16:32:41  neilg
 * improve handling of out of memory conditions, bug #23415.  Thanks to David Cargill.
 *
 * Revision 1.13  2003/05/15 18:57:27  knoaman
 * Partial implementation of the configurable memory manager.
 *
 * Revision 1.12  2003/01/17 15:35:57  knoaman
 * Fix for attribute checking of schema declarations.
 *
 * Revision 1.11  2003/01/15 18:33:11  knoaman
 * Make sure that the namespace of schema declarations is the schema namespace.
 *
 * Revision 1.10  2002/12/10 16:58:22  knoaman
 * Schema Errata E1-16.
 *
 * Revision 1.9  2002/11/04 14:49:41  tng
 * C++ Namespace Support.
 *
 * Revision 1.8  2002/09/27 13:22:52  tng
 * [Bug 13073] GeneralAttributeCheck.cpp : compilation fails with Sun C++ 4.2 on Solaris2.7 system.
 *
 * Revision 1.7  2002/09/26 21:08:14  tng
 * [Bug12849] comparison is always false warning.  Patch from Gareth Reakes
 *
 * Revision 1.6  2002/09/24 20:18:14  tng
 * Performance: use XMLString::equals instead of XMLString::compareString
 * and check for null string directly isntead of calling XMLString::stringLen
 *
 * Revision 1.5  2002/05/27 19:54:33  knoaman
 * Performance: use pre-built element-attribute map table.
 *
 * Revision 1.4  2002/05/21 19:30:10  tng
 * DOM Reorganization: modify to use the new DOM interface.
 *
 * Revision 1.3  2002/03/21 15:34:40  knoaman
 * Add support for reporting line/column numbers of schema errors.
 *
 * Revision 1.2  2002/02/06 22:21:49  knoaman
 * Use IDOM for schema processing.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:45  peiyongz
 * sane_include
 *
 * Revision 1.16  2002/01/02 19:50:34  knoaman
 * Fix for error message when checking for attributes with a namespace prefix.
 *
 * Revision 1.15  2001/12/13 18:08:39  knoaman
 * Fix for bug 5410.
 *
 * Revision 1.14  2001/11/19 18:26:31  knoaman
 * no message
 *
 * Revision 1.13  2001/11/19 17:37:55  knoaman
 * Use the instance of ID datatye validator directly.
 *
 * Revision 1.12  2001/11/16 15:03:37  knoaman
 * Design change: GeneralAttributeCheck is not longer a singleton class.
 *
 * Revision 1.11  2001/11/02 14:13:45  knoaman
 * Add support for identity constraints.
 *
 * Revision 1.10  2001/10/25 15:07:46  tng
 * Thread safe the static instance.
 *
 * Revision 1.9  2001/10/23 23:14:55  peiyongz
 * [Bug#880] patch to PlatformUtils:init()/term() and related. from Mark Weaver
 *
 * Revision 1.8  2001/10/16 17:01:58  knoaman
 * Extra constraint checking.
 *
 * Revision 1.7  2001/10/15 19:29:26  knoaman
 * Add support for <notation> declaration.
 *
 * Revision 1.6  2001/09/18 14:41:56  knoaman
 * Add support for <annotation>.
 *
 * Revision 1.5  2001/08/27 20:14:42  knoaman
 * Validate attributes in <all>, <redefine>, <group> and <attributeGroup> declarations.
 * Misc. fixes.
 *
 * Revision 1.4  2001/06/06 13:09:02  knoaman
 * Use BooleanDatatypeValidator to validate values.
 *
 * Revision 1.3  2001/05/18 20:05:30  knoaman
 * Modified wording of error messages.
 *
 * Revision 1.2  2001/05/17 18:11:15  knoaman
 * More constraint and attribute checking.
 *
 * Revision 1.1  2001/05/15 21:59:31  knoaman
 * TraverseSchema: add attribute checking + some fixes + more error messages.
 * More attribute cheking to come.
 *
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/validators/schema/GeneralAttributeCheck.hpp>
#include <xercesc/validators/schema/SchemaSymbols.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/Janitor.hpp>
#include <xercesc/dom/DOMNamedNodeMap.hpp>
#include <xercesc/framework/XMLErrorCodes.hpp>
#include <xercesc/validators/schema/TraverseSchema.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLRegisterCleanup.hpp>
#include <xercesc/validators/datatype/DatatypeValidatorFactory.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  Local const data
// ---------------------------------------------------------------------------
const XMLCh fgValueZero[] =
{
    chDigit_0, chNull
};

const XMLCh fgValueOne[] =
{
    chDigit_1, chNull
};

const XMLCh fgUnbounded[] =
{
    chLatin_u, chLatin_n, chLatin_b, chLatin_o, chLatin_u, chLatin_n, chLatin_d,
    chLatin_e, chLatin_d, chNull
};

const XMLCh fgLocal[] =
{
    chLatin_l, chLatin_o, chLatin_c, chLatin_a, chLatin_l, chNull
};

const XMLCh fgGlobal[] =
{
    chLatin_g, chLatin_l, chLatin_o, chLatin_b, chLatin_a, chLatin_l, chNull
};


// ---------------------------------------------------------------------------
//  Static local data
// ---------------------------------------------------------------------------
static bool sGeneralAttCheckMutexRegistered = false;
static XMLMutex* sGeneralAttCheckMutex = 0;
static XMLRegisterCleanup sGeneralAttCheckCleanup;


// ---------------------------------------------------------------------------
//  Static member data initialization
// ---------------------------------------------------------------------------
ValueHashTableOf<unsigned short>* GeneralAttributeCheck::fAttMap = 0;
ValueHashTableOf<unsigned short>* GeneralAttributeCheck::fFacetsMap = 0;
DatatypeValidator*                GeneralAttributeCheck::fNonNegIntDV = 0;
DatatypeValidator*                GeneralAttributeCheck::fBooleanDV = 0;
DatatypeValidator*                GeneralAttributeCheck::fAnyURIDV = 0;


// ---------------------------------------------------------------------------
//  GeneralAttributeCheck: Constructors and Destructor
// ---------------------------------------------------------------------------
GeneralAttributeCheck::GeneralAttributeCheck(MemoryManager* const manager)
    : fMemoryManager(manager)
    , fValidationContext(0)
    , fIDValidator(manager)
{
    mapElements();
}

GeneralAttributeCheck::~GeneralAttributeCheck()
{
}


// ---------------------------------------------------------------------------
//  GeneralAttributeCheck: Setup methods
// ---------------------------------------------------------------------------
void GeneralAttributeCheck::setUpValidators() {

    DatatypeValidatorFactory dvFactory(fMemoryManager);

    dvFactory.expandRegistryToFullSchemaSet();
    fNonNegIntDV = dvFactory.getDatatypeValidator(SchemaSymbols::fgDT_NONNEGATIVEINTEGER);
    fBooleanDV = dvFactory.getDatatypeValidator(SchemaSymbols::fgDT_BOOLEAN);
    fAnyURIDV = dvFactory.getDatatypeValidator(SchemaSymbols::fgDT_ANYURI);

    // TO DO - add remaining valdiators
}

void GeneralAttributeCheck::mapElements()
{
    if (!sGeneralAttCheckMutexRegistered)
    {
        if (!sGeneralAttCheckMutex)
        {
            XMLMutexLock lock(XMLPlatformUtils::fgAtomicMutex);

            if (!sGeneralAttCheckMutex)
                sGeneralAttCheckMutex = new XMLMutex;
        }

        // Use a faux scope to synchronize while we do this
        {
            XMLMutexLock lock(sGeneralAttCheckMutex);

            // If we got here first, then register it and set the registered flag
            if (!sGeneralAttCheckMutexRegistered)
            {
                // initialize
                setUpValidators();
                mapAttributes();

                // register for cleanup at Termination.
                sGeneralAttCheckCleanup.registerCleanup(GeneralAttributeCheck::reinitGeneralAttCheck);
                sGeneralAttCheckMutexRegistered = true;
            }
        }
    }
}

void GeneralAttributeCheck::mapAttributes() {

    fAttMap = new ValueHashTableOf<unsigned short>(A_Count);

    fAttMap->put((void*)SchemaSymbols::fgATT_ABSTRACT, A_Abstract);
    fAttMap->put((void*)SchemaSymbols::fgATT_ATTRIBUTEFORMDEFAULT, A_AttributeFormDefault);
    fAttMap->put((void*)SchemaSymbols::fgATT_BASE, A_Base);
    fAttMap->put((void*)SchemaSymbols::fgATT_BLOCK, A_Block);
    fAttMap->put((void*)SchemaSymbols::fgATT_BLOCKDEFAULT, A_BlockDefault);
    fAttMap->put((void*)SchemaSymbols::fgATT_DEFAULT, A_Default);
    fAttMap->put((void*)SchemaSymbols::fgATT_ELEMENTFORMDEFAULT, A_ElementFormDefault);
    fAttMap->put((void*)SchemaSymbols::fgATT_FINAL, A_Final);
    fAttMap->put((void*)SchemaSymbols::fgATT_FINALDEFAULT, A_FinalDefault);
    fAttMap->put((void*)SchemaSymbols::fgATT_FIXED, A_Fixed);
    fAttMap->put((void*)SchemaSymbols::fgATT_FORM, A_Form);
    fAttMap->put((void*)SchemaSymbols::fgATT_ID, A_ID);
    fAttMap->put((void*)SchemaSymbols::fgATT_ITEMTYPE, A_ItemType);
    fAttMap->put((void*)SchemaSymbols::fgATT_MAXOCCURS, A_MaxOccurs);
    fAttMap->put((void*)SchemaSymbols::fgATT_MEMBERTYPES, A_MemberTypes);
    fAttMap->put((void*)SchemaSymbols::fgATT_MINOCCURS, A_MinOccurs);
    fAttMap->put((void*)SchemaSymbols::fgATT_MIXED, A_Mixed);
    fAttMap->put((void*)SchemaSymbols::fgATT_NAME, A_Name);
    fAttMap->put((void*)SchemaSymbols::fgATT_NAMESPACE, A_Namespace);
    fAttMap->put((void*)SchemaSymbols::fgATT_NILLABLE, A_Nillable);
    fAttMap->put((void*)SchemaSymbols::fgATT_PROCESSCONTENTS, A_ProcessContents);
    fAttMap->put((void*)SchemaSymbols::fgATT_PUBLIC, A_Public);
    fAttMap->put((void*)SchemaSymbols::fgATT_REF, A_Ref);
    fAttMap->put((void*)SchemaSymbols::fgATT_REFER, A_Refer);
    fAttMap->put((void*)SchemaSymbols::fgATT_SCHEMALOCATION, A_SchemaLocation);
    fAttMap->put((void*)SchemaSymbols::fgATT_SOURCE, A_Source);
    fAttMap->put((void*)SchemaSymbols::fgATT_SUBSTITUTIONGROUP, A_SubstitutionGroup);
    fAttMap->put((void*)SchemaSymbols::fgATT_SYSTEM, A_System);
    fAttMap->put((void*)SchemaSymbols::fgATT_TARGETNAMESPACE, A_TargetNamespace);
    fAttMap->put((void*)SchemaSymbols::fgATT_TYPE, A_Type);
    fAttMap->put((void*)SchemaSymbols::fgATT_USE, A_Use);
    fAttMap->put((void*)SchemaSymbols::fgATT_VALUE, A_Value);
    fAttMap->put((void*)SchemaSymbols::fgATT_VERSION, A_Version);
    fAttMap->put((void*)SchemaSymbols::fgATT_XPATH, A_XPath);

    fFacetsMap = new ValueHashTableOf<unsigned short>(13);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_MINEXCLUSIVE, E_MinExclusive);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_MININCLUSIVE, E_MinInclusive);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_MAXEXCLUSIVE, E_MaxExclusive);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_MAXINCLUSIVE, E_MaxInclusive);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_TOTALDIGITS, E_TotalDigits);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_FRACTIONDIGITS, E_FractionDigits);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_LENGTH, E_Length);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_MINLENGTH, E_MinLength);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_MAXLENGTH, E_MaxLength);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_ENUMERATION, E_Enumeration);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_WHITESPACE, E_WhiteSpace);
    fFacetsMap->put((void*) SchemaSymbols::fgELT_PATTERN, E_Pattern);
}


// -----------------------------------------------------------------------
//  Notification that lazy data has been deleted
// -----------------------------------------------------------------------
void
GeneralAttributeCheck::reinitGeneralAttCheck() {

    delete sGeneralAttCheckMutex;
    sGeneralAttCheckMutex = 0;
    sGeneralAttCheckMutexRegistered = false;

    delete fAttMap;
    delete fFacetsMap;
	
    fAttMap = fFacetsMap = 0;
    fNonNegIntDV = fBooleanDV = fAnyURIDV = 0;
}

// ---------------------------------------------------------------------------
//  GeneralAttributeCheck: Validation methods
// ---------------------------------------------------------------------------
void
GeneralAttributeCheck::checkAttributes(const DOMElement* const elem,
                                       const unsigned short elemContext,
                                       TraverseSchema* const schema,
                                       const bool isTopLevel,
                                       ValueVectorOf<DOMNode*>* const nonXSAttList)
{
    if (nonXSAttList)
        nonXSAttList->removeAllElements();

    if (elem == 0 || !fAttMap || elemContext>=E_Count)
        return;

    const XMLCh* elemName = elem->getLocalName();
    if (!XMLString::equals(SchemaSymbols::fgURI_SCHEMAFORSCHEMA, elem->getNamespaceURI())) {
        schema->reportSchemaError
        (
            elem
            , XMLUni::fgXMLErrDomain
            , XMLErrs::ELTSchemaNS
            , elemName
        );
    }

    const XMLCh*     contextStr = (isTopLevel) ? fgGlobal : fgLocal;
    DOMNamedNodeMap* eltAttrs = elem->getAttributes();
    int              attrCount = eltAttrs->getLength();
    XMLByte          attList[A_Count];

    memset(attList, 0, sizeof(attList));

    for (int i = 0; i < attrCount; i++) {

        DOMNode*     attribute = eltAttrs->item(i);
        const XMLCh* attName = attribute->getNodeName();

        // skip namespace declarations
        if (XMLString::equals(attName, XMLUni::fgXMLNSString)
            || XMLString::startsWith(attName, XMLUni::fgXMLNSColonString))
            continue;

        // Bypass attributes that start with xml
        // add this to the list of "non-schema" attributes
        if ((*attName == chLatin_X || *attName == chLatin_x)
           && (*(attName+1) == chLatin_M || *(attName+1) == chLatin_m)
           && (*(attName+2) == chLatin_L || *(attName+2) == chLatin_l)) {

           if (nonXSAttList)
                nonXSAttList->addElement(attribute);

            continue;
        }

        // for attributes with namespace prefix
        const XMLCh* attrURI = attribute->getNamespaceURI();

        if (attrURI != 0 && *attrURI) {

            // attributes with schema namespace are not allowed
            // and not allowed on "documentation" and "appInfo"
            if (XMLString::equals(attrURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA) ||
                XMLString::equals(elemName, SchemaSymbols::fgELT_APPINFO) ||
                XMLString::equals(elemName, SchemaSymbols::fgELT_DOCUMENTATION)) {

                schema->reportSchemaError(elem, XMLUni::fgXMLErrDomain,
                    XMLErrs::AttributeDisallowed, attName, contextStr, elemName);
            }
            else if (nonXSAttList)
            {
                nonXSAttList->addElement(attribute);
            }

            continue;
        }

        int attNameId = A_Invalid;
        attName = attribute->getLocalName();

        try {
            attNameId= fAttMap->get(attName, fMemoryManager);
        }
        catch(const OutOfMemoryException&)
        {
            throw;
        }
        catch(...) {

            schema->reportSchemaError(elem, XMLUni::fgXMLErrDomain,
                XMLErrs::AttributeDisallowed, attName, contextStr, elemName);
            continue;
        }

        if (fgElemAttTable[elemContext][attNameId] & Att_Mask) {

            attList[attNameId] = 1;
            validate
            (
                elem
                , attName
                , attribute->getNodeValue()
                , fgElemAttTable[elemContext][attNameId] & DV_Mask
                , schema
            );
        }
        else {
            schema->reportSchemaError(elem, XMLUni::fgXMLErrDomain,
                XMLErrs::AttributeDisallowed, attName, contextStr, elemName);
        }
    }

    // ------------------------------------------------------------------
    // Check for required attributes
    // ------------------------------------------------------------------
    for (unsigned int j=0; j < A_Count; j++) {

        if ((fgElemAttTable[elemContext][j] & Att_Required) && attList[j] == 0) {
            schema->reportSchemaError(elem, XMLUni::fgXMLErrDomain, XMLErrs::AttributeRequired,
                                      fAttNames[j], contextStr, elemName);
        }
    }
}


void GeneralAttributeCheck::validate(const DOMElement* const elem,
                                     const XMLCh* const attName,
                                     const XMLCh* const attValue,
                                     const short dvIndex,
                                     TraverseSchema* const schema)
{
    bool isInvalid = false;
    DatatypeValidator* dv = 0;

    switch (dvIndex) {
    case DV_Form:
        if (!XMLString::equals(attValue, SchemaSymbols::fgATTVAL_QUALIFIED)
            && !XMLString::equals(attValue, SchemaSymbols::fgATTVAL_UNQUALIFIED)) {
            isInvalid = true;
        }
        break;
    case DV_MaxOccurs:
            // maxOccurs = (nonNegativeInteger | unbounded)
        if (!XMLString::equals(attValue, fgUnbounded)) {
            dv = fNonNegIntDV;
        }
        break;
    case DV_MaxOccurs1:
        if (!XMLString::equals(attValue, fgValueOne)) {
            isInvalid = true;
        }
        break;
    case DV_MinOccurs1:
        if (!XMLString::equals(attValue, fgValueZero)
            && !XMLString::equals(attValue, fgValueOne)) {
            isInvalid = true;
        }
        break;
    case DV_ProcessContents:
        if (!XMLString::equals(attValue, SchemaSymbols::fgATTVAL_SKIP)
            && !XMLString::equals(attValue, SchemaSymbols::fgATTVAL_LAX)
            && !XMLString::equals(attValue, SchemaSymbols::fgATTVAL_STRICT)) {
            isInvalid = true;
        }
        break;
    case DV_Use:
        if (!XMLString::equals(attValue, SchemaSymbols::fgATTVAL_OPTIONAL)
            && !XMLString::equals(attValue, SchemaSymbols::fgATTVAL_PROHIBITED)
            && !XMLString::equals(attValue, SchemaSymbols::fgATTVAL_REQUIRED)) {
            isInvalid = true;
        }
        break;
    case DV_WhiteSpace:
        if (!XMLString::equals(attValue, SchemaSymbols::fgWS_PRESERVE)
            && !XMLString::equals(attValue, SchemaSymbols::fgWS_REPLACE)
            && !XMLString::equals(attValue, SchemaSymbols::fgWS_COLLAPSE)) {
            isInvalid = true;
        }
        break;
    case DV_Boolean:
        dv = fBooleanDV;
        break;
    case DV_NonNegInt:
        dv = fNonNegIntDV;
        break;
    case DV_AnyURI:
        dv = fAnyURIDV;
        break;
    case DV_ID:
        if (fValidationContext)
        {
            dv = &fIDValidator;
        }
        break;
    }

    if (dv) {
        try {
            dv->validate(attValue, fValidationContext, fMemoryManager);
        }
        catch(const XMLException& excep) {
            schema->reportSchemaError(elem, XMLUni::fgXMLErrDomain, XMLErrs::DisplayErrorMessage, excep.getMessage());
        }
        catch(const OutOfMemoryException&)
        {
            throw;
        }
        catch(...) {
            isInvalid = true;
        }
    }

    if (isInvalid) {
        schema->reportSchemaError(elem, XMLUni::fgXMLErrDomain, XMLErrs::InvalidAttValue,
                                  attValue, attName);
    }
}


// ---------------------------------------------------------------------------
//  Conditional methods for building the table
// ---------------------------------------------------------------------------

//
//  This code will set up the character flags table. Its defined out since
//  this table is now written out and hard coded (at the bottom of this
//  file) into the code itself. This code is retained in case there is
//  any need to recreate it later.
//

#if defined(NEED_TO_GEN_ELEM_ATT_MAP_TABLE)

#include <stdio.h>

void GeneralAttributeCheck::initCharFlagTable()
{
    unsigned short attList[E_Count][A_Count];

    for (unsigned int i=0; i < E_Count; i++) {
        for (unsigned int j=0; j < A_Count; j++) {
            attList[i][j] = 0;
        }
    }

    //
    //  Write it out to a temp file to be read back into this source later.
    //
    FILE* outFl = fopen("ea_table.out", "wt+");
    fprintf(outFl, "unsigned short GeneralAttributeCheck::fgElemAttTable[E_Count][A_Count] =\n{\n    {");

    //"all"
    attList[E_All][A_ID] = Att_Optional | DV_ID;
    attList[E_All][A_MaxOccurs] = Att_Optional | DV_MaxOccurs1;
    attList[E_All][A_MinOccurs] = Att_Optional | DV_MinOccurs1;

    // "annotation"
    attList[E_Annotation][A_ID] = Att_Optional | DV_ID;

    // "any"
    attList[E_Any][A_ID] = Att_Optional | DV_ID;
    attList[E_Any][A_MaxOccurs] = Att_Optional | DV_MaxOccurs;
    attList[E_Any][A_MinOccurs] = Att_Optional | DV_NonNegInt;
    attList[E_Any][A_Namespace] = Att_Optional;
    attList[E_Any][A_ProcessContents] = Att_Optional | DV_ProcessContents;

    // "anyAttribute"
    attList[E_AnyAttribute][A_ID] = Att_Optional | DV_ID;
    attList[E_AnyAttribute][A_Namespace] = Att_Optional;
    attList[E_AnyAttribute][A_ProcessContents] = Att_Optional | DV_ProcessContents;

    // "appinfo"
    attList[E_Appinfo][A_Source]= Att_Optional | DV_AnyURI;

    // attribute - global"
    attList[E_AttributeGlobal][A_Default] = Att_Optional;
    attList[E_AttributeGlobal][A_Fixed] = Att_Optional;
    attList[E_AttributeGlobal][A_ID] = Att_Optional | DV_ID;
    attList[E_AttributeGlobal][A_Name] = Att_Required;
    attList[E_AttributeGlobal][A_Type] = Att_Optional;

    // "attribute - local"
    attList[E_AttributeLocal][A_Default] = Att_Optional;
    attList[E_AttributeLocal][A_Fixed] = Att_Optional;
    attList[E_AttributeLocal][A_Form]= Att_Optional | DV_Form;
    attList[E_AttributeLocal][A_ID] = Att_Optional | DV_ID;
    attList[E_AttributeLocal][A_Name] = Att_Required;
    attList[E_AttributeLocal][A_Type] = Att_Optional;
    attList[E_AttributeLocal][A_Use] = Att_Optional | DV_Use;

    // "attribute - ref"
    attList[E_AttributeRef][A_Default] = Att_Optional;
    attList[E_AttributeRef][A_Fixed] = Att_Optional;
    attList[E_AttributeRef][A_ID] = Att_Optional | DV_ID;
    attList[E_AttributeRef][A_Ref]= Att_Required;
    attList[E_AttributeRef][A_Use] = Att_Optional | DV_Use;

    // "attributeGroup - global"
    attList[E_AttributeGroupGlobal][A_ID] = Att_Optional | DV_ID;
    attList[E_AttributeGroupGlobal][A_Name] = Att_Required;

    // "attributeGroup - ref"
    attList[E_AttributeGroupRef][A_ID] = Att_Optional | DV_ID;
    attList[E_AttributeGroupRef][A_Ref]= Att_Required;

    // "choice"
    attList[E_Choice][A_ID] = Att_Optional | DV_ID;
    attList[E_Choice][A_MaxOccurs] = Att_Optional | DV_MaxOccurs;
    attList[E_Choice][A_MinOccurs] = Att_Optional | DV_NonNegInt;

    // "complexContent"
    attList[E_ComplexContent][A_ID] = Att_Optional | DV_ID;
    attList[E_ComplexContent][A_Mixed] = Att_Optional | DV_Boolean;

    // "complexType - global"
    attList[E_ComplexTypeGlobal][A_Abstract] = Att_Optional | DV_Boolean;
    attList[E_ComplexTypeGlobal][A_Block] = Att_Optional;
    attList[E_ComplexTypeGlobal][A_Final] = Att_Optional;
    attList[E_ComplexTypeGlobal][A_ID] = Att_Optional | DV_ID;
    attList[E_ComplexTypeGlobal][A_Mixed] = Att_Optional | DV_Boolean;
    attList[E_ComplexTypeGlobal][A_Name] = Att_Required;

    // "complexType - local"
    attList[E_ComplexTypeLocal][A_ID] = Att_Optional | DV_ID;
    attList[E_ComplexTypeLocal][A_Mixed] = Att_Optional | DV_Boolean;

    // "documentation"
    attList[E_Documentation][A_Source] = Att_Optional | DV_AnyURI;

    // "element - global"
    attList[E_ElementGlobal][A_Abstract] = Att_Optional | DV_Boolean;
    attList[E_ElementGlobal][A_Block] = Att_Optional;
    attList[E_ElementGlobal][A_Default] = Att_Optional;
    attList[E_ElementGlobal][A_Final] = Att_Optional;
    attList[E_ElementGlobal][A_Fixed] = Att_Optional;
    attList[E_ElementGlobal][A_ID] = Att_Optional | DV_ID;
    attList[E_ElementGlobal][A_Name] = Att_Required;
    attList[E_ElementGlobal][A_Nillable] = Att_Optional | DV_Boolean;
    attList[E_ElementGlobal][A_SubstitutionGroup] = Att_Optional;
    attList[E_ElementGlobal][A_Type] = Att_Optional;

    // "element - local"
    attList[E_ElementLocal][A_Block]= Att_Optional;
    attList[E_ElementLocal][A_Default] = Att_Optional;
    attList[E_ElementLocal][A_Fixed] = Att_Optional;
    attList[E_ElementLocal][A_Form] = Att_Optional | DV_Form;
    attList[E_ElementLocal][A_ID] = Att_Optional | DV_ID;
    attList[E_ElementLocal][A_MaxOccurs] = Att_Optional | DV_MaxOccurs;
    attList[E_ElementLocal][A_MinOccurs] = Att_Optional | DV_NonNegInt;
    attList[E_ElementLocal][A_Name] = Att_Required;
    attList[E_ElementLocal][A_Nillable] = Att_Optional | DV_Boolean;
    attList[E_ElementLocal][A_Type] = Att_Optional;

    //"element - ref"
    attList[E_ElementRef][A_ID] = Att_Optional | DV_ID;
    attList[E_ElementRef][A_MaxOccurs] = Att_Optional | DV_MaxOccurs;
    attList[E_ElementRef][A_MinOccurs] = Att_Optional | DV_NonNegInt;
    attList[E_ElementRef][A_Ref] = Att_Required;

    // "enumeration"
    attList[E_Enumeration][A_ID] = Att_Optional | DV_ID;
    attList[E_Enumeration][A_Value] = Att_Optional;

    // "extension"
    attList[E_Extension][A_Base] = Att_Required;
    attList[E_Extension][A_ID] = Att_Optional | DV_ID;

    //"field"
    attList[E_Field][A_ID] = Att_Optional | DV_ID;
    attList[E_Field][A_XPath] = Att_Required;

    // "fractionDigits"
    attList[E_FractionDigits][A_ID] = Att_Optional | DV_ID;
    attList[E_FractionDigits][A_Value] = Att_Optional | DV_NonNegInt;
    attList[E_FractionDigits][A_Fixed] = Att_Optional | DV_Boolean;

    // "group - global"
    attList[E_GroupGlobal][A_ID] = Att_Optional | DV_ID;
    attList[E_GroupGlobal][A_Name] = Att_Required;

    // "group - ref"
    attList[E_GroupRef][A_ID] = Att_Optional | DV_ID;
    attList[E_GroupRef][A_MaxOccurs] = Att_Optional | DV_MaxOccurs;
    attList[E_GroupRef][A_MinOccurs] = Att_Optional | DV_NonNegInt;
    attList[E_GroupRef][A_Ref] = Att_Required;

    // "import"
    attList[E_Import][A_ID] = Att_Optional | DV_ID;
    attList[E_Import][A_Namespace] = Att_Optional;
    attList[E_Import][A_SchemaLocation] = Att_Optional;

    // "include"
    attList[E_Include][A_ID] = Att_Optional | DV_ID;
    attList[E_Include][A_SchemaLocation] = Att_Required;

    // "key"
    attList[E_Key][A_ID] = Att_Optional | DV_ID;
    attList[E_Key][A_Name] = Att_Required;

    // "keyref"
    attList[E_KeyRef][A_ID] = Att_Optional | DV_ID;
    attList[E_KeyRef][A_Name] = Att_Required;
    attList[E_KeyRef][A_Refer] = Att_Required;

    // "length"
    attList[E_Length][A_ID] = Att_Optional | DV_ID;
    attList[E_Length][A_Value] = Att_Optional | DV_NonNegInt;
    attList[E_Length][A_Fixed] = Att_Optional | DV_Boolean;

    // "list"
    attList[E_List][A_ID] = Att_Optional | DV_ID;
    attList[E_List][A_ItemType] = Att_Optional;

    // "maxExclusive"
    attList[E_MaxExclusive][A_ID] = Att_Optional | DV_ID;
    attList[E_MaxExclusive][A_Value] = Att_Optional;
    attList[E_MaxExclusive][A_Fixed] = Att_Optional | DV_Boolean;

    // "maxInclusive"
    attList[E_MaxInclusive][A_ID] = Att_Optional | DV_ID;
    attList[E_MaxInclusive][A_Value] = Att_Optional;
    attList[E_MaxInclusive][A_Fixed] = Att_Optional | DV_Boolean;

    // "maxLength"
    attList[E_MaxLength][A_ID] = Att_Optional | DV_ID;
    attList[E_MaxLength][A_Value] = Att_Optional | DV_NonNegInt;
    attList[E_MaxLength][A_Fixed] = Att_Optional | DV_Boolean;

    // "minExclusive"
    attList[E_MinExclusive][A_ID] = Att_Optional | DV_ID;
    attList[E_MinExclusive][A_Value] = Att_Optional;
    attList[E_MinExclusive][A_Fixed] = Att_Optional | DV_Boolean;

    // "minInclusive"
    attList[E_MinInclusive][A_ID] = Att_Optional | DV_ID;
    attList[E_MinInclusive][A_Value] = Att_Optional;
    attList[E_MinInclusive][A_Fixed] = Att_Optional | DV_Boolean;

    // "minLength"
    attList[E_MinLength][A_ID] = Att_Optional | DV_ID;
    attList[E_MinLength][A_Value] = Att_Optional | DV_NonNegInt;
    attList[E_MinLength][A_Fixed] = Att_Optional | DV_Boolean;

    // "notation"
    attList[E_Notation][A_ID] = Att_Optional | DV_ID;
    attList[E_Notation][A_Name] = Att_Required;
    attList[E_Notation][A_Public] = Att_Optional;
    attList[E_Notation][A_System] = Att_Optional | DV_AnyURI;

    // "pattern"
    attList[E_Pattern][A_ID] = Att_Optional;
    attList[E_Pattern][A_Value] = Att_Optional;

    // "redefine"
    attList[E_Redefine][A_ID] = Att_Optional | DV_ID;
    attList[E_Redefine][A_SchemaLocation] = Att_Required;

    // "restriction"
    attList[E_Restriction][A_Base] = Att_Optional;
    attList[E_Restriction][A_ID] = Att_Optional | DV_ID;

    // "schema"
    attList[E_Schema][A_AttributeFormDefault] = Att_Optional | DV_Form;
    attList[E_Schema][A_BlockDefault] = Att_Optional;
    attList[E_Schema][A_ElementFormDefault] = Att_Optional | DV_Form;
    attList[E_Schema][A_FinalDefault] = Att_Optional;
    attList[E_Schema][A_ID] = Att_Optional | DV_ID;
    attList[E_Schema][A_TargetNamespace] = Att_Optional;
    attList[E_Schema][A_Version] = Att_Optional;

    // "selector"
    attList[E_Selector][A_ID] = Att_Optional | DV_ID;
    attList[E_Selector][A_XPath] = Att_Required;

    // "sequence"
    attList[E_Sequence][A_ID] = Att_Optional | DV_ID;
    attList[E_Sequence][A_MaxOccurs] = Att_Optional | DV_MaxOccurs;
    attList[E_Sequence][A_MinOccurs] = Att_Optional | DV_NonNegInt;

    // "simpleContent"
    attList[E_SimpleContent][A_ID] = Att_Optional | DV_ID;

    // "simpleType - global"
    attList[E_SimpleTypeGlobal][A_Final] = Att_Optional;
    attList[E_SimpleTypeGlobal][A_ID] = Att_Optional | DV_ID;
    attList[E_SimpleTypeGlobal][A_Name] = Att_Required;

    // "simpleType - local"
    attList[E_SimpleTypeLocal][A_Final] = Att_Optional;
    attList[E_SimpleTypeLocal][A_ID] = Att_Optional | DV_ID;

    // "totalDigits"
    attList[E_TotalDigits][A_ID] = Att_Optional | DV_ID;
    attList[E_TotalDigits][A_Value] = Att_Optional | DV_NonNegInt;
    attList[E_TotalDigits][A_Fixed] = Att_Optional | DV_Boolean;

    // "union"
    attList[E_Union][A_ID] = Att_Optional | DV_ID;
    attList[E_Union][A_MemberTypes] = Att_Optional;

    // "unique"
    attList[E_Unique][A_ID] = Att_Optional | DV_ID;
    attList[E_Unique][A_Name] = Att_Required;

    // "whitespace"
    attList[E_WhiteSpace][A_ID] = Att_Optional | DV_ID;
    attList[E_WhiteSpace][A_Value] = Att_Optional | DV_WhiteSpace;
    attList[E_WhiteSpace][A_Fixed] = Att_Optional | DV_Boolean;

    for (unsigned int j=0; j < E_Count; j++) {

        for (unsigned int index = 0; index < A_Count-1; index++)
        {
            fprintf(outFl, " %d,", attList[j][index]);
        }

        fprintf(outFl, " %d", attList[j][A_Count - 1]);

        if (j + 1 == E_Count)
            fprintf(outFl, "}\n};");
        else
            fprintf(outFl, "},\n    {");
    }

    fclose(outFl);
}

#endif


unsigned short GeneralAttributeCheck::fgElemAttTable[GeneralAttributeCheck::E_Count][GeneralAttributeCheck::A_Count] =
{
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 258, 0, 514, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 130, 0, 10, 0, 0, 2, 0, 1026, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 2, 0, 1026, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 66, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2050, 0, 0, 0},
  { 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2050, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 130, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 18, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 34, 0, 0, 0, 0, 18, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0},
  { 18, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 34, 0, 0, 0, 0, 0, 1, 0, 18, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0},
  { 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 66, 34, 0, 130, 0, 10, 0, 1, 0, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 130, 0, 10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 130, 0, 10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 66, 0, 0, 2, 0, 66, 0, 2, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 130, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 0, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4098, 0, 0}
};

const XMLCh* GeneralAttributeCheck::fAttNames[A_Count] =
{
    SchemaSymbols::fgATT_ABSTRACT,
    SchemaSymbols::fgATT_ATTRIBUTEFORMDEFAULT,
    SchemaSymbols::fgATT_BASE,
    SchemaSymbols::fgATT_BLOCK,
    SchemaSymbols::fgATT_BLOCKDEFAULT,
    SchemaSymbols::fgATT_DEFAULT,
    SchemaSymbols::fgATT_ELEMENTFORMDEFAULT,
    SchemaSymbols::fgATT_FINAL,
    SchemaSymbols::fgATT_FINALDEFAULT,
    SchemaSymbols::fgATT_FIXED,
    SchemaSymbols::fgATT_FORM,
    SchemaSymbols::fgATT_ID,
    SchemaSymbols::fgATT_ITEMTYPE,
    SchemaSymbols::fgATT_MAXOCCURS,
    SchemaSymbols::fgATT_MEMBERTYPES,
    SchemaSymbols::fgATT_MINOCCURS,
    SchemaSymbols::fgATT_MIXED,
    SchemaSymbols::fgATT_NAME,
    SchemaSymbols::fgATT_NAMESPACE,
    SchemaSymbols::fgATT_NILLABLE,
    SchemaSymbols::fgATT_PROCESSCONTENTS,
    SchemaSymbols::fgATT_PUBLIC,
    SchemaSymbols::fgATT_REF,
    SchemaSymbols::fgATT_REFER,
    SchemaSymbols::fgATT_SCHEMALOCATION,
    SchemaSymbols::fgATT_SOURCE,
    SchemaSymbols::fgATT_SUBSTITUTIONGROUP,
    SchemaSymbols::fgATT_SYSTEM,
    SchemaSymbols::fgATT_TARGETNAMESPACE,
    SchemaSymbols::fgATT_TYPE,
    SchemaSymbols::fgATT_USE,
    SchemaSymbols::fgATT_VALUE,
    SchemaSymbols::fgATT_VERSION,
    SchemaSymbols::fgATT_XPATH,
};

XERCES_CPP_NAMESPACE_END

/**
  * End of file GeneralAttributeCheck.cpp
  */


