#include "parser.hh"

Parser::Parser ( std::string str ) : tok(str) {
}

Object * Parser::array ( void ) {

  Array * a = new Array();

  tok.eat_punctuation('[');
  int i = 0;

  while ( !tok.current().matches(']') ) {
    a->set(i++,object());
    if ( tok.current().matches(',')) {
      tok.eat_punctuation(',');
      if ( tok.current().matches(']') ) {
        throw ParserException("Unexpected end of array");
      }
    }
  }

  tok.eat_punctuation(']');

  return a;

}

Object * Parser::hash ( void ) {

  Hash * h = new Hash();

  tok.eat_punctuation('{');

  while ( !tok.current().matches('}') ) {

    if ( tok.current().is_string() ) {

      std::string key = tok.current().string_val();
      tok.eat();
      tok.eat_punctuation(':');
      h->set(key,object());

      if ( tok.current().matches(',')) {
        tok.eat_punctuation(',');
        if ( tok.current().matches('}') ) {
          throw ParserException("Unexpected end of hash");
        }
      }

    } else {

      throw ParserException("Expected string");

    }

  }

  tok.eat_punctuation('}');

  return h;

}

Object * Parser::number ( void ) {
  //Number * n = new Number(tok.current().number_val());
  //tok.eat();
  Number * n = new Number( expression() );
  return n;
}

Object * Parser::exponents ( void ) {
  Number * n = new Number(tok.current().number_val(), tok.current().exponents_val());
  tok.eat();
  return n;
}

Object * Parser::null ( void ) {
  tok.eat();
  return new Null;
}

Object * Parser::boolean ( void ) {
  Boolean * b = new Boolean(tok.current().bool_val());
  tok.eat();
  return b;
}

Object * Parser::string ( void ) {
  String * s = new String(tok.current().string_val());
  tok.eat();
  return s;
}

Object * Parser::object ( void ) {

  if ( tok.current().matches('{') ) {
    return hash();
  } else if ( tok.current().matches('[') ) {
    return array();
  } else if ( tok.current().matches('(') ) {
    return number();
  } else if ( tok.current().matches('+') ) {
    return number();
  } else if ( tok.current().matches('-') ) {
    return number();
  } else if ( tok.current().is_number() ) {
    return number();
  } else if ( tok.current().is_exponents() ) {
    return exponents();
  } else if ( tok.current().is_null() ) {
    return null();
  } else if ( tok.current().is_bool() ) {
    return boolean();
  } else if ( tok.current().is_string() ) {
    return string();
  } else {
    std::string s("Unexpected token ");
    s += tok.current().to_s();
    throw ParserException(s.c_str());
  }

}

double Parser::factor() {
  if ( tok.current().is_number() ) {
      double num = tok.current().number_val();
      tok.eat();
      return num;
  } else if ( tok.current().matches('(') ) {
      tok.eat_punctuation('(');
      double num = expression();
      tok.eat_punctuation(')');
      return num;
  } else {
      throw ParserException("factor: syntax error");
      //nextsym();
  }
}

double Parser::expression() {

  double num;

  if ( tok.current().matches('+') ){
    tok.eat_punctuation('+');
    num = term();
  }else if ( tok.current().matches('-') ){
    tok.eat_punctuation('-');
    num = (-1) * term();
  }else{
    num = term();
  }

  while ( tok.current().matches('+') || tok.current().matches('-') ) {
    if ( tok.current().matches('+') ){
      tok.eat_punctuation('+');
      num = num + term();
    }

    if ( tok.current().matches('-') ){
      tok.eat_punctuation('-');
      num = num - term();
    }
  }

  return num;
}

double Parser::term() {

  double num = factor();

  while ( tok.current().matches('*') || tok.current().matches('/') ) {
    if ( tok.current().matches('*') ){
      tok.eat_punctuation('*');
      num = num * term();
    }

    if ( tok.current().matches('/') ){
      tok.eat_punctuation('/');
      num = num / term();
    }
  }

  return num;
}
