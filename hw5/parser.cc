#include <math.h>
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
      bool is_int = tok.current().is_int();
      tok.eat();
      Number * n = new Number( num, exponents, is_int );
      return n;
  } else if ( tok.current().matches('(') ) {
      tok.eat_punctuation('(');
      Number * o = expression();
      double num = o->get_val();
      double exponents = o->get_exp();
      bool is_int = o->is_int();
      delete o;
      tok.eat_punctuation(')');
      Number * n = new Number( num, exponents, is_int );
      return n;
  } else {
      throw ParserException("factor: syntax error");
  }
}

Number * Parser::expression() {

  double num;
  double exponents;
  bool num_is_int;

  bool unary_minus = false;

  Number * o;

  if ( tok.current().matches('+') ){
    tok.eat_punctuation('+');
    o = term(unary_minus);
    num = o->get_val();
    exponents = o->get_exp();
    num_is_int = o->is_int();
    delete o;
  }else if ( tok.current().matches('-') ){
    tok.eat_punctuation('-');
    unary_minus = true;
    o = term(unary_minus);
    num = o->get_val();
    exponents = o->get_exp();
    num_is_int = o->is_int();
    unary_minus = false;
    delete o;
  }else{
    o = term(unary_minus);
    num = o->get_val();
    exponents = o->get_exp();
    num_is_int = o->is_int();
    delete o;
  }

  while ( tok.current().matches('+') || tok.current().matches('-') ) {
    if ( tok.current().matches('+') ){
      tok.eat_punctuation('+');
      o = term(unary_minus);
      double t = o->get_val();
      double e = o->get_exp();
      bool integer = o->is_int();
      delete o;
      if ( e < exponents ){
        num = num + t / pow(10.0, (exponents - e));
        num_is_int = false;
      }else if ( e > exponents ){
        num = num/pow(10.0, (e - exponents)) + t;
        exponents = e;
        num_is_int = false;
      }else{
        num = num + t;
        num_is_int = integer;
      }
    }

    if ( tok.current().matches('-') ){
      tok.eat_punctuation('-');
      o = term(unary_minus);
      double t = o->get_val();
      double e = o->get_exp();
      bool integer = o->is_int();
      delete o;
      if ( e < exponents ){
        num = num - t / pow(10.0, (exponents - e));
        num_is_int = false;
      }else if ( e > exponents ){
        num = num/pow(10.0, (e - exponents)) - t;
        exponents = e;
        num_is_int = false;
      }else{
        num = num - t;
        num_is_int = integer;
      }
    }
  }

  Number * n = new Number( num, exponents, num_is_int );
  return n;
}

Number * Parser::term(bool unary_minus) {

  Number * o = factor();
  double num = o->get_val();
  double exponents = o->get_exp();
  bool num_is_int = o->is_int();
  delete o;

  if (unary_minus){
    num = (-1) * num;
  }

  while ( tok.current().matches('*') || tok.current().matches('/') || tok.current().matches('%') ) {
    if ( tok.current().matches('*') ){
      tok.eat_punctuation('*');
      o = factor();
      num = num * (o->get_val());
      exponents = exponents + (o->get_exp());
      num_is_int = o->is_int();
      delete o;
    }

    if ( tok.current().matches('/') ){
      tok.eat_punctuation('/');
      o = factor();
      double t = o->get_val();
      double e = o->get_exp();
      bool integer = o->is_int();
      delete o;
      if ( t != 0 ){
        if ( integer && num_is_int ){
          num = (int) num / (int) t;
        }else{
          num = num / t;
          num_is_int = false;
        }
        exponents = exponents - e;
      }else{
        throw ParserException("invalid operands to divide by 0");
      }
    }

    if ( tok.current().matches('%') && num_is_int ){
      tok.eat_punctuation('%');
      o = factor();
      double t = (o->get_val()) * pow(10, (o->get_exp()));
      bool integer = o->is_int();
      num = num * pow(10, exponents);
      delete o;
      if ( integer && t != 0){
        num = ( (int) num ) %  ( (int) t );
        if (num < 0){
          num = ((int) (t - std::abs ( (int) num ))) % ( (int) t );
        }
        exponents = 0;
      }else{
        throw ParserException("invalid operands to binary 'operator%'");
      }
    }

    if ( tok.current().matches('%') && !(num_is_int) ){
      throw ParserException("invalid operands to binary 'operator%'");
    }
  }

  Number * n = new Number( num, exponents, num_is_int );
  return n;
}
