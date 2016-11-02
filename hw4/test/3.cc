#include <iostream>
#include "json.hh"

// Use the original 2.cc file to test item 3

int main ( int argc, char * argv[] ) {

  Hash h;
  Number n(1);

  h.set("first", n);
  h.set("second", h);

  std::cout << h.stringify() << std::endl;
  std::cout << h.get("first")->stringify() << std::endl;
  std::cout << h.get("second")->stringify() << std::endl;

  // Test the copy constructor for Hash
  std::cout << h.get("second")->get("first")->stringify() << std::endl;

  // Update number n to 2
  n.set(2);

  // Update key first to a new number
  h.set("first", n);

  // Print out hash again 
  // The changes should be in key first only because of copy constructor
  std::cout << h.stringify() << std::endl;
  std::cout << h.get("first")->stringify() << std::endl;
  std::cout << h.get("second")->stringify() << std::endl;

  return 0;

}
