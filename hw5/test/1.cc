#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  //Tokenizer tok("{ \"first\": [ true, \"a\", \"b\", \"c\" ], \"second\": 1.234 }");

  Tokenizer tok("{ \"a\": [0,1E3,2.1e3,4.678E-3,4.78e-3,5.9e+18], \"b\": { \"c\": 0 } }");

  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  return 0;

}
