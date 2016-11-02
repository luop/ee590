#include <iostream>
#include <stdexcept>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Number number(1.0);
  Array array;

  array.set(0,number);
  number.set(2.0);
  array.set(1,number);

  // Test item 2
  
  try {
     // negative index should return index out of bound exception
     array.get(-1);
  } catch ( json_exception &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
     // array.get(3) is null. It should return index out of bound exception
     array.get(3);
  } catch ( json_exception &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
     // index is greater than max. It should return index out of bound exception
     array.get(10);;
  } catch ( json_exception &e ) {
    std::cerr << e.what() << std::endl;
  }

  Hash h;
  Number n(1);

  h.set("first", n);

  try {
     // The key does not exist. It should return index out of bound exception
     h.get("second");
  } catch ( json_exception &e ) {
    std::cerr << e.what() << std::endl;
  }

  return 0;

}
