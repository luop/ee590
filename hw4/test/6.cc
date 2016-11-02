#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  // Test item 6
   
  // Creat an object String
  String s("Test1");
  Array array;

  // Print out String
  std::cout << s.stringify() << std::endl;

  // Put the String into an array
  array.set(0,s);

  // Update the String with new std::string
  s.set("Test2");

  // Put the updated String to the same array
  array.set(1,s);

  // Print out String and see if it gets changed
  std::cout << s.stringify() << std::endl;

  // Print out array to see if it has "Test1" and "Test2"
  std::cout << array.stringify() << std::endl;

  return 0;

}
