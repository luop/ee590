#include "test.h"
#include "DFT.h"

bool verifyIMatrix(matrix<ComplexNum> m, double precision){

  int r = m.rows();
  bool equalI = true;

  double mr, mi;

  for (int i = 0; i < r; i ++){
    for (int j =0; j < r; j ++){

      mr = m.get(i, j).realNum();
      mi = m.get(i, j).imagNum();

      if ( i == j){
        equalI = equalI && ( ( mr - precision ) < 1 ) && ( ( ( mr + precision ) > 1 ) );
        equalI = equalI && ( ( mi - precision ) < 0 ) && ( ( ( mi + precision ) > 0 ) );
      }else{
        equalI = equalI && ( ( mr - precision ) < 0 ) && ( ( ( mr + precision ) > 0 ) );
        equalI = equalI && ( ( mi - precision ) < 0 ) && ( ( ( mi + precision ) > 0 ) );
      }

      if (!equalI){
        break;
      }
    }
  }

  return equalI;
}

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;

  matrix<ComplexNum> Q(4,1);
  ComplexNum Q1(1, 0);
  ComplexNum Q2(2, 0);
  ComplexNum Q3(3, 0);
  ComplexNum Q4(4, 0);

  Q.set(0,0,Q1); Q.set(1,0,Q2);
  Q.set(2,0,Q3); Q.set(3,0,Q4);

  DFT test(4);

  matrix<ComplexNum> dft = (*test.getDFTMatrix());
  matrix<ComplexNum> U = (*test.getUnitary());
  matrix<ComplexNum> up4 = U.power(4);
  matrix<ComplexNum> idft = (*test.getInvDFT());

  matrix<ComplexNum> dseq = test.getDFTSeq(Q);
  std::cout << "The DFT of a given input sequence (1, 2, 3, 4):" << std::endl;
  std::cout << dseq << std::endl;

  matrix<ComplexNum> invseq = test.getInvDFTSeq(dseq);
  std::cout << "The invert DFT of a given input sequence:" << std::endl;
  std::cout << invseq << std::endl;

  double precision = 0.0001;

  /*Test 1
    verify DFT matrix * invert of DFT matrix (approximately) equals identity matrix
  */
  ASSERT(verifyIMatrix(dft.mult(idft), precision));

  /*Test 2
    verify raise the unitary matrix to the fourth power
    it is (approximately) equals the identity matrix.
  */
  ASSERT(verifyIMatrix(up4, precision));

  /*Test 2
    dft to random sequence Q to get a sequence dseq
    inverse DFT to dseq to get invseq.
    verify invseq (approximately) equals Q
  */
  ASSERT(( ( invseq.get(0, 0).realNum() - precision ) < 1 ) && ( ( ( invseq.get(0, 0).realNum() + precision ) > 1 ) ));
  ASSERT(( ( invseq.get(0, 0).imagNum() - precision ) < 0 ) && ( ( ( invseq.get(0, 0).imagNum() + precision ) > 0 ) ));

  ASSERT(( ( invseq.get(1, 0).realNum() - precision ) < 2 ) && ( ( ( invseq.get(1, 0).realNum() + precision ) > 2 ) ));
  ASSERT(( ( invseq.get(1, 0).imagNum() - precision ) < 0 ) && ( ( ( invseq.get(1, 0).imagNum() + precision ) > 0 ) ));

  ASSERT(( ( invseq.get(2, 0).realNum() - precision ) < 3 ) && ( ( ( invseq.get(2, 0).realNum() + precision ) > 3 ) ));
  ASSERT(( ( invseq.get(2, 0).imagNum() - precision ) < 0 ) && ( ( ( invseq.get(2, 0).imagNum() + precision ) > 0 ) ));

  ASSERT(( ( invseq.get(3, 0).realNum() - precision ) < 4 ) && ( ( ( invseq.get(3, 0).realNum() + precision ) > 4 ) ));
  ASSERT(( ( invseq.get(3, 0).imagNum() - precision ) < 0 ) && ( ( ( invseq.get(3, 0).imagNum() + precision ) > 0 ) ));

}
