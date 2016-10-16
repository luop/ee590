#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  // Constructor Tests

  // Test 1:
  // Check 3/4 is positive with numerator equals to 3, denominator equals to 4
  std::cout << std::endl;

  fraction A(4, 6);

  fraction B = A.ReduceToLowest ();
  ASSERT ( B.numer() == 2 && B.denom() == 3 && B.posi() );
  //cout << A;

  fraction C = A + B;
  ASSERT ( C.numer() == 4 && C.denom() == 3 && C.posi() );
  //cout << B;

  fraction D = C - A;
  ASSERT ( D.numer() == 2 && D.denom() == 3 && D.posi() );

  fraction E = A * B;
  //cout << E;
  ASSERT ( E.numer() == 4 && E.denom() == 9 && E.posi() );

  fraction F = E / B;
  //cout << F;
  ASSERT ( F.numer() == 2 && F.denom() == 3 && F.posi() );

  fraction G(-1, 2);
  fraction H = G + B;
  ASSERT ( H.numer() == 1 && H.denom() == 6 && H.posi() );

  fraction I = B + G;
  ASSERT ( I.numer() == 1 && I.denom() == 6 && I.posi() );

  fraction J = G - B;
  ASSERT ( J.numer() == 7 && J.denom() == 6 && !J.posi() );

  fraction K = B - G;
  ASSERT ( K.numer() == 7 && K.denom() == 6 && K.posi() );

  fraction L = G * B;
  ASSERT ( L.numer() == 1 && L.denom() == 3 && !L.posi() );

  fraction M = G / B;
  ASSERT ( M.numer() == 3 && M.denom() == 4 && !M.posi() );

  fraction N = -B;
  fraction O = G + N;
  ASSERT ( O.numer() == 7 && O.denom() == 6 && !O.posi() );

  fraction P = G - N;
  ASSERT ( P.numer() == 1 && P.denom() == 6 && P.posi() );

  fraction Q = N - G;
  ASSERT ( Q.numer() == 1 && Q.denom() == 6 && !Q.posi() );

  fraction R = G * N;
  ASSERT ( R.numer() == 1 && R.denom() == 3 && R.posi() );

  fraction S = G / N;
  ASSERT ( S.numer() == 3 && S.denom() == 4 && S.posi() );

  SUCCEED;

}
