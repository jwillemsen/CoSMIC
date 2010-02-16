// $Id$

#include "IDL_File_Parser.hpp"
#include "rules/grammar.hpp"
#include "t3/runtime/Auto_Model.h"

bool
IDL_File_Parser::
parse (std::string::const_iterator begin,
       std::string::const_iterator end,
       ::GME::Object & obj)
{
  using boost::phoenix::ref;
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  T3::Auto_Model auto_model (obj);
  idl_grammar <std::string::const_iterator> grammar;
  bool result = qi::phrase_parse (begin, end, grammar (ref (auto_model)), ascii::space);

  return result && (begin == end);
}