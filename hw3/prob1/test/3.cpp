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

  fraction B(2, 3);

  ASSERT ( A == B );

  ASSERT ( ! (A != B) );

  ASSERT ( ! (A < B) );

  ASSERT ( ! (A > B) );

  ASSERT ( A <= B );

  ASSERT ( A >= B );


  fraction C(-4, 6);

  fraction D(2, 3);

  ASSERT ( !(C == D) );

  ASSERT ( C != D );

  ASSERT ( C < D );

  ASSERT ( ! (C > D) );

  ASSERT ( C <= D );

  ASSERT ( ! (C >= D) );

  ASSERT ( !(D == C) );

  ASSERT ( D != C );

  ASSERT ( ! (D < C) );

  ASSERT ( D > C );

  ASSERT ( !(D <= C) );

  ASSERT ( D >= C );


  fraction E(-4, 5);

  fraction F(-2, 3);

  ASSERT ( !(E == F) );

  ASSERT ( E != F );

  ASSERT ( E < D );

  ASSERT ( ! (E > F) );

  ASSERT ( E <= F );

  ASSERT ( ! (E >= F) );

  ASSERT ( ! (F < E) );

  ASSERT ( F > E );

  ASSERT ( !(F <= E) );

  ASSERT ( F >= E );


  ASSERT ( C == F );

  ASSERT ( ! (C != F) );

  ASSERT ( ! (C < F) );

  ASSERT ( ! (C > F) );

  ASSERT ( C <= F );

  ASSERT ( C >= F );

  SUCCEED;

}
