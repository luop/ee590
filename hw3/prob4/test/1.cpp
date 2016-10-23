#include "test.h"
#include "DFT.h"

int main ( int argc, char * argv[] ) {

  matrix<ComplexNum> Q(4,1);
  ComplexNum Q1(1, 0);
  ComplexNum Q2(2, 0);
  ComplexNum Q3(3, 0);
  ComplexNum Q4(4, 0);

  Q.set(0,0,Q1); Q.set(1,0,Q2);
  Q.set(2,0,Q3); Q.set(3,0,Q4);

  matrix<ComplexNum> P(4,1);
  ComplexNum P1(10, 0);
  ComplexNum P2(-2, 2);
  ComplexNum P3(-2, 0);
  ComplexNum P4(-2, -2);

  P.set(0,0,P1); P.set(1,0,P2);
  P.set(2,0,P3); P.set(3,0,P4);

  // Test cout operator
  std::cout << "The matrix Q is:" << std::endl;
  std::cout << Q << std::endl;

  std::cout << "The matrix P is:" << std::endl;
  std::cout << P << std::endl;



  DFT test(4);
  std::cout << (*test.getDFTMatrix()) << std::endl;
  matrix<ComplexNum> N = (*test.getUnitary());
  std::cout << N << std::endl;
  std::cout << N.power(4) << std::endl;
  std::cout << (*test.getInvDFT()) << std::endl;




  std::cout << test.getDFTSeq(Q) << std::endl;
  std::cout << test.getInvDFTSeq(P) << std::endl;

}
