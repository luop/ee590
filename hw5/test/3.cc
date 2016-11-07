#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Parser p("[1+1,1+1+1,2+20+200+2000,3-1,4+1-1+2-2,5*2,6/3,7*2/2,8+2*2,9+2/2,(10+2)/2,11-2/2,(12+2)*(12-2),13-(2+1)*3,14+1-2*2+2/2,(15/5)-2,-(16/2)]");

  std::cout << p.object()->stringify() << std::endl;

  Parser m("[1%1,1+1%1,11-2%2,(12+2)%(12-2),13-(2+1)%3,14+1-2*2+2%2,(15%5)-2,-(16%2)]");

  std::cout << m.object()->stringify() << std::endl;

  try {
    Parser q("[(1+1]");
    std::cout << q.object()->stringify() << std::endl;
  } catch ( TokenizerException &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Parser q("[(1+)1]");
    std::cout << q.object()->stringify() << std::endl;
  } catch ( ParserException &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Parser q("[2.3%1]");
    std::cout << q.object()->stringify() << std::endl;
  } catch ( ParserException &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Parser q("[2%3.1]");
    std::cout << q.object()->stringify() << std::endl;
  } catch ( ParserException &e ) {
    std::cerr << e.what() << std::endl;
  }

  try {
    Parser q("[2.3%3.1]");
    std::cout << q.object()->stringify() << std::endl;
  } catch ( ParserException &e ) {
    std::cerr << e.what() << std::endl;
  }
  return 0;

}
