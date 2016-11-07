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
  Number * n = new Number(tok.current().number_val());
  tok.eat();
  //Number * n = new Number( expression() );
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
    return expression();
  } else if ( tok.current().matches('+') ) {
    return expression();
  } else if ( tok.current().matches('-') ) {
    return expression();
  } else if ( tok.current().is_number() ) {
    return expression();
  } else if ( tok.current().is_exponents() ) {
    return expression();
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

Number * Parser::factor() {
  if ( tok.current().is_number() || tok.current().is_exponents() ) {
      double num = tok.current().number_val();
      double exponents = tok.current().exponents_val();
      tok.eat();
      Number * n = new Number( num, exponents );
      return n;
  } else if ( tok.current().matches('(') ) {
      tok.eat_punctuation('(');
      Number * o = expression();
      double num = o->get_val();
      double exponents = o->get_exp();
      delete o;
      tok.eat_punctuation(')');
      Number * n = new Number( num, exponents );
      return n;
  } else {
      throw ParserException("factor: syntax error");
      //nextsym();
  }
}

Number * Parser::expression() {

  double num;
  double exponents;

  Number * o;

  if ( tok.current().matches('+') ){
    tok.eat_punctuation('+');
    o = term();
    num = o->get_val();
    exponents = o->get_exp();
    delete o;
  }else if ( tok.current().matches('-') ){
    tok.eat_punctuation('-');
    o = term();
    num = (-1) * (o->get_val());
    exponents = o->get_exp();
    delete o;
  }else{
    o = term();
    num = o->get_val();
    exponents = o->get_exp();
    delete o;
  }

  while ( tok.current().matches('+') || tok.current().matches('-') ) {
    if ( tok.current().matches('+') ){
      tok.eat_punctuation('+');
      o = term();
      num = num + (o->get_val());
      exponents = o->get_exp();
      delete o;
    }

    if ( tok.current().matches('-') ){
      tok.eat_punctuation('-');
      o = term();
      num = num - (o->get_val());
      exponents = o->get_exp();
      delete o;
    }
  }

  Number * n = new Number( num, exponents );
  return n;
}

Number * Parser::term() {

  Number * o = factor();
  double num = o->get_val();
  double exponents = o->get_exp();
  delete o;

  while ( tok.current().matches('*') || tok.current().matches('/') || tok.current().matches('%') ) {
    if ( tok.current().matches('*') ){
      tok.eat_punctuation('*');
      o = factor();
      num = num * (o->get_val());
      exponents = o->get_exp();
      delete o;
    }

    if ( tok.current().matches('/') ){
      tok.eat_punctuation('/');
      o = factor();
      double t = o->get_val();
      if ( t != 0 ){
        num = num / t;
      }else{
        throw ParserException("invalid operands to divide by 0");
      }
      exponents = o->get_exp();
      delete o;
    }

    if ( tok.current().matches('%') && (num - (int) num == 0) ){
      tok.eat_punctuation('%');
      o = factor();
      double t = o->get_val();
      exponents = o->get_exp();
      delete o;
      if ( (t - (int) t == 0) && t != 0){
        num = ( (int) num ) %  ( (int) t );
      }else{
        throw ParserException("invalid operands to binary 'operator%'");
      }
    }

    if ( tok.current().matches('%') && (num - (int) num != 0) ){
      throw ParserException("invalid operands to binary 'operator%'");
    }
  }

  Number * n = new Number( num, exponents );
  return n;
}
