#include <iostream>
#include "json.hh"
#include <sstream>

int main ( int argc, char * argv[] ) {

  //Tokenizer tok("{ \"first\": [ true, \"a\", \"b\", \"c\" ], \"second\": 1.234 }");

  Tokenizer tok("{ \"a\": [0,1E3,2], \"b\": { \"c\": 0 } }");

  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  std::stringstream ss;

  double test = 1000;

  ss << std::scientific << test;
  std::cout << ss.str() << std::endl;

  return 0;

}
