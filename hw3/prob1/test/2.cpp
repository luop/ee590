#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;

  // Operation Tests
  fraction A(4, 6);

  /*Test 1
    Reduce a fraction to lowest terms
    verify numerator is 2, denominator is 3, and it is positive
  */
  fraction B = A.ReduceToLowest ();
  ASSERT ( B.numer() == 2 && B.denom() == 3 && B.posi() );

  /*Test 2
    (4/6) + (2/3) = (4/3)
    verify numerator is 4, denominator is 3, and it is positive
  */
  fraction C = A + B;
  ASSERT ( C.numer() == 4 && C.denom() == 3 && C.posi() );

  /*Test 3
    (4/3) - (2/3) = (2/3)
    verify numerator is 2, denominator is 3, and it is positive
  */
  fraction D = C - A;
  ASSERT ( D.numer() == 2 && D.denom() == 3 && D.posi() );

  /*Test 4
    (4/6) * (2/3) = (4/9)
    verify numerator is 4, denominator is 9, and it is positive
  */
  fraction E = A * B;
  ASSERT ( E.numer() == 4 && E.denom() == 9 && E.posi() );

  /*Test 5
    (4/9) / (2/3) = (2/3)
    verify numerator is 2, denominator is 3, and it is positive
  */
  fraction F = E / B;
  ASSERT ( F.numer() == 2 && F.denom() == 3 && F.posi() );

  fraction G(-1, 2);

  /*Test 6
    -(1/2) + (2/3) = (1/6)
    verify numerator is 1, denominator is 6, and it is positive
  */
  fraction H = G + B;
  ASSERT ( H.numer() == 1 && H.denom() == 6 && H.posi() );

  /*Test 7
    (2/3) + (-(1/2)) = (1/6)
    verify numerator is 1, denominator is 6, and it is positive
  */
  fraction I = B + G;
  ASSERT ( I.numer() == 1 && I.denom() == 6 && I.posi() );

  /*Test 8
    -(1/2) - (2/3) = -(7/6)
    verify numerator is 7, denominator is 6, and it is negative
  */
  fraction J = G - B;
  ASSERT ( J.numer() == 7 && J.denom() == 6 && !J.posi() );

  /*Test 9
    (2/3) - (-(1/2)) = (7/6)
    verify numerator is 7, denominator is 6, and it is positive
  */
  fraction K = B - G;
  ASSERT ( K.numer() == 7 && K.denom() == 6 && K.posi() );

  /*Test 10
    -(1/2) * (2/3) = -(1/3)
    verify numerator is 1, denominator is 3, and it is negative
  */
  fraction L = G * B;
  ASSERT ( L.numer() == 1 && L.denom() == 3 && !L.posi() );

  /*Test 11
    -(1/2) / (2/3) = -(3/4)
    verify numerator is 3, denominator is 4, and it is negative
  */
  fraction M = G / B;
  ASSERT ( M.numer() == 3 && M.denom() == 4 && !M.posi() );

  fraction N = -B;

  /*Test 12
    -(1/2) + (-(2/3)) = -(7/6)
    verify numerator is 7, denominator is 6, and it is negative
  */
  fraction O = G + N;
  ASSERT ( O.numer() == 7 && O.denom() == 6 && !O.posi() );

  /*Test 13
    -(1/2) - (-(2/3)) = (1/6)
    verify numerator is 1, denominator is 6, and it is positive
  */
  fraction P = G - N;
  ASSERT ( P.numer() == 1 && P.denom() == 6 && P.posi() );

  /*Test 14
    -(2/3) - (-(1/2)) = -(1/6)
    verify numerator is 1, denominator is 6, and it is negative
  */
  fraction Q = N - G;
  ASSERT ( Q.numer() == 1 && Q.denom() == 6 && !Q.posi() );

  /*Test 15
    -(1/2) * (-(2/3)) = (1/3)
    verify numerator is 1, denominator is 3, and it is positive
  */
  fraction R = G * N;
  ASSERT ( R.numer() == 1 && R.denom() == 3 && R.posi() );

  /*Test 16
    -(1/2) / (-(2/3)) = (3/4)
    verify numerator is 1, denominator is 3, and it is positive
  */
  fraction S = G / N;
  ASSERT ( S.numer() == 3 && S.denom() == 4 && S.posi() );

  /*Test 17
    create a fraction with numerator equals to 0.
    verify the exception is caught for division of 0 numerator
  */
  try {
     fraction T(0, 3);
     B / T;
     FAIL;
  } catch ( fraction_exception &e ) {
    SUCCEED;
  }

  return 0;
}
