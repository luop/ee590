#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdexcept>
#include "json.hh"

class ParserException : public std::runtime_error {
public:
  ParserException(const char msg[]) : std::runtime_error(msg) {}
};

class Parser {

public:

  Parser ( std::string str );

  Object * object ( void );
  Object * array ( void );
  Object * number ( void );
  Object * exponents ( void );
  Object * hash ( void );
  Object * null ( void );
  Object * boolean ( void );
  Object * string ( void );

private:

  Tokenizer tok;
  Number * factor();
  Number * expression();
  Number * term(bool unary_minus);

};

#endif
