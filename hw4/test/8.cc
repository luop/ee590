#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  // Test item 8
  
  // Construct example JSON
  Hash h1;
  Hash h2;
  Hash h3;
  Hash h4;

  Array a1;
  Array a2;

  String s("is fun");
  Boolean b(true);
  Number n(0);

  Null * nu = new Null();

  h1.set("ee590", s);

  s.set("is");
  a1.set(0, s);

  s.set("arcane");
  h2.set("adjective", s);

  a1.set(1, h2);
  h1.set("C++", a1);

  s.set("hipsters");
  h3.set("used by", s);
  h3.set("poetic", b);
  h1.set("Ruby", h3);

  s.set("JavaHomeworkAssignmentTestCodeLibraryAssessorFuncTest");
  a2.set(0, s);
  a2.set(1, n);
  a2.set(2, (*nu));
  s.set("zero");
  a2.set(3, s);
  a2.set(4, h4);
  h1.set("Java", a2);

  s.set("Resistance is futile");
  h1.set("Javascript", s);

  // Print out the example JSON
  std::cout << h1.stringify() << std::endl;

  std::cout << std::boolalpha;

  // Verify each object is configured properly
  // Print out true it is correctly configured
  std::string test;
  test = h1.get("ee590")->stringify();
  std::cout << std::endl << (test == "\"is fun\"") << std::endl;

  test = h1.get("C++")->get(0)->stringify();
  std::cout << std::endl << (test == "\"is\"") << std::endl;

  test = h1.get("C++")->get(1)->get("adjective")->stringify();
  std::cout << std::endl << (test == "\"arcane\"") << std::endl;

  test = h1.get("Ruby")->get("used by")->stringify();
  std::cout << std::endl << (test == "\"hipsters\"") << std::endl;

  test = h1.get("Ruby")->get("poetic")->stringify();
  std::cout << std::endl << (test == "true") << std::endl;

  test = h1.get("Java")->get(0)->stringify();
  std::cout << std::endl << (test == "\"JavaHomeworkAssignmentTestCodeLibraryAssessorFuncTest\"") << std::endl;

  test = h1.get("Java")->get(1)->stringify();
  std::cout << std::endl << (std::stoi( test ) == 0) << std::endl;

  test = h1.get("Java")->get(2)->stringify();
  std::cout << std::endl << (test == "null") << std::endl;

  test = h1.get("Java")->get(3)->stringify();
  std::cout << std::endl << (test == "\"zero\"") << std::endl;

  test = h1.get("Java")->get(4)->stringify();
  std::cout << std::endl << (test == "{}") << std::endl;

  test = h1.get("Javascript")->stringify();
  std::cout << std::endl << (test == "\"Resistance is futile\"") << std::endl;

  return 0;

}
