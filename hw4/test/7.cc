#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {


  // Test item 7
   
  // Create Boolean object equals to true
  Boolean b(true);

  // Print out Boolean
  std::cout << b.stringify() << std::endl;

  Array array;

  array.set(0,b);

  // Change Boolean object to false
  b.set(false);
  array.set(1,b);

  // Print out Boolean again and see it gets changed
  std::cout << b.stringify() << std::endl;

  // Print out array and see it has true and false
  std::cout << array.stringify() << std::endl;

  return 0;

}
