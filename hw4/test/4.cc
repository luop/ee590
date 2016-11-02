#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Hash h;
  Number n(1);
  String s("Test");
  Boolean b(true);

  // Test item 4
  
  // Set key "first" to be number n
  h.set("first", n);
  std::cout << h.stringify() << std::endl;

  // Set key "first" to be string s
  // n should be replaced by s
  h.set("first", s);
  std::cout << h.stringify() << std::endl;

  // Set key "first" to be boolean b
  // s should be replaced by b
  h.set("first", b);
  std::cout << h.stringify() << std::endl;

  return 0;

}
