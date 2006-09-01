// $Id: XercesString.h 571 2005-11-23 18:00:18Z kitty $

#ifndef _XERCESSTRING_H
#define _XERCESSTRING_H


#include <iosfwd>
#include <string>
#include <xercesc/util/XMLString.hpp>
#include "Utils/Utils_Export.h"

// Utility class that provides a std::string like facade to XMLString.
// Doesn't implement all of the methods of std::string.

namespace Utils
{

  class Utils_Export XStr
  {
  public:
    XStr() : _wstr(0L) { };

    XStr (const char* str);

    XStr (std::string& str);

    XStr (XMLCh* wstr);

    XStr (const XMLCh* wstr);

    XStr (const XStr& copy);

    XStr& operator= (const XStr& rhs);

    ~XStr();

    const XMLCh* begin() const;

    const XMLCh* end() const;

    bool append(const XMLCh* tail);

    bool erase(const XMLCh* head, const XMLCh* tail);

    int size() const;

    XMLCh operator [] (const int i);

    const XMLCh operator [] (const int i) const;

    operator const XMLCh* () const;

	  char* c_str() const;

    bool operator== (const XMLCh* wstr) const;


  private:

    XMLCh* _wstr; // Internal representation
  };

  Utils_Export bool operator== (const XStr& lhs, const XStr& rhs);
  Utils_Export bool operator!= (const XStr& lhs, const XStr& rhs);

  Utils_Export std::ostream& operator<< (std::ostream& o, XStr const& str);

}

#endif /* _XERCESSTRING_H */