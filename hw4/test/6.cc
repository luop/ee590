#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  String s("Test1");
  Array array;

  array.set(0,s);
  s.set("Test2");
  array.set(1,s);
  array.set(3,array);

  std::cout << s.stringify() << std::endl;
  std::cout << array.stringify() << std::endl;
  std::cout << array.get(3)->stringify() << std::endl;

  return 0;

}
