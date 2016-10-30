#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Hash h;
  Number n(1);
  String s("Test");
  Boolean b(true);

  h.set("first", n);
  std::cout << h.stringify() << std::endl;

  h.set("first", s);
  std::cout << h.stringify() << std::endl;

  h.set("first", b);
  std::cout << h.stringify() << std::endl;

  return 0;

}
