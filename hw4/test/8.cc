#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

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

  std::cout << h1.stringify() << std::endl;

  return 0;

}
