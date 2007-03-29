// -*- C++ -*-
// $Id:$
#include "common.h"

namespace CQML
  {
    using xercesc::DOMImplementationRegistry;
    using xercesc::DOMImplementationLS;
    using xercesc::DOMException;
    using xercesc::XMLUni;
    using xercesc::XMLException;
    using xercesc::DOMText;

    std::ofstream outfile ("C:\\Documents and Settings\\Aky\\Desktop\\security_debug.txt");   


    void DOMBuilder::push()
    {
      this->curr_stack_.push (this->curr_);
    }

    DOMBuilder::DOMBuilder (const std::string& outputPath)
      : impl_ (0), doc_ (0), root_ (0), curr_ (0), serializer_ (0), 
        target_ (0), outputPath_ (outputPath)
      {        
        this->init(); 
      }

    void DOMBuilder::pop()
    {
      if (!this->curr_stack_.empty())
        {
          this->curr_ = this->curr_stack_.top();
          this->curr_stack_.pop();
        }
      else
        {
          throw(std::exception());
        }
    }

    DOMDocument *DOMBuilder::doc ()
      {
        return this->doc_;
      }
    
    DOMElement *DOMBuilder::curr ()
      {
        return this->curr_;
      }

    void DOMBuilder::curr (DOMElement *elem)
      {
        this->curr_ = elem;
      }
   
    DOMBuilder::~DOMBuilder ()  
      {
        if (this->doc_)
          this->doc_->release();
        delete this->target_;
      }

    void DOMBuilder::init()
    {
      this->impl_ = DOMImplementationRegistry::getDOMImplementation(XStr("LS"));
      this->serializer_ = ((DOMImplementationLS*)impl_)->createDOMWriter();

      // Set features if the serializer supports the feature/mode
      if (this->serializer_->canSetFeature
          (XMLUni::fgDOMWRTDiscardDefaultContent, true))
        this->serializer_->setFeature (XMLUni::fgDOMWRTDiscardDefaultContent,
                                       true);

      if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTFormatPrettyPrint,
                                            true))
        this->serializer_->setFeature (XMLUni::fgDOMWRTFormatPrettyPrint, true);

      if (this->serializer_->canSetFeature (XMLUni::fgDOMWRTBOM, false))
        this->serializer_->setFeature (XMLUni::fgDOMWRTBOM, false);
    }

    void DOMBuilder::initTarget (const std::string& fileName)
    {
      if (this->target_)
        delete this->target_;
      this->target_ = new LocalFileFormatTarget (fileName.c_str());
    }

    void DOMBuilder::initDocument (const std::string& rootName)
    {
      if (this->doc_)
        this->doc_->release();
      // Create the document
      this->doc_ =
        this->impl_->createDocument (XStr ("http://www.dre.vanderbilt.edu/RTSchedulabilityRequirements"),
                                     XStr (rootName.c_str()),
                                     0);
    }

    void DOMBuilder::initRootAttributes()
    {
      this->doc_->setEncoding (XStr("UTF-8"));
      this->doc_->setVersion (XStr("1.0"));
      this->doc_->setStandalone (false);
      this->root_ = this->doc_->getDocumentElement();
      this->root_->setAttributeNS (XStr ("http://www.w3.org/2000/xmlns/"),
                                   XStr ("xmlns:xsi"),
                                   XStr ("http://www.w3.org/2001/XMLSchema-instance"));
      this->root_->setAttribute (XStr ("xsi:schemaLocation"),
                                 XStr ("http://www.dre.vanderbilt.edu/RTSchedulabilityRequirements RTSchedulabilityRequirements.xsd"));
      std::string id = std::string ("_") + Utils::CreateUuid();
      this->root_->setAttribute (XStr("id"), XStr (id));
      this->curr_ = this->root_;
    }

    void DOMBuilder::dumpDocument()
    {
      this->serializer_->writeNode (this->target_, *this->doc_);
    }

    Auto_DOM::Auto_DOM (DOMBuilder& b, std::string tag)
      : dom_builder_(&b)
      {
        DOMElement *e = dom_builder_->doc()->createElement(XStr (tag));
        dom_builder_->curr()->appendChild (e);
        dom_builder_->push();
        dom_builder_->curr(e);
      }

    Auto_DOM::Auto_DOM (DOMBuilder& b, DOMElement *e)
      : dom_builder_(&b)
      {
        dom_builder_->curr()->appendChild (e);
        dom_builder_->push();
        dom_builder_->curr(e);
      }
    
    Auto_DOM::~Auto_DOM ()
      {
        dom_builder_->pop ();
      }

    DOMElement* Auto_DOM::curr ()
      {
        return dom_builder_->curr();
      }
  }