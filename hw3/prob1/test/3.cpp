#include "test.h"
#include "fraction.h"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  std::cout << std::endl;

  // Test relations
  fraction A(4, 6);
  fraction B(2, 3);

  /*Test 1
    verify A == B is true
  */
  ASSERT ( A == B );

  /*Test 2
    verify A != B is false
  */
  ASSERT ( ! (A != B) );

  /*Test 3
    verify A < B is false
  */
  ASSERT ( ! (A < B) );

  /*Test 4
    verify A > B is false
  */
  ASSERT ( ! (A > B) );

  /*Test 5
    verify A <= B is true
  */
  ASSERT ( A <= B );

  /*Test 6
    verify A >= B is true
  */
  ASSERT ( A >= B );

  fraction C(-4, 6);
  fraction D(2, 3);

  /*Test 7
    verify C == D is false
  */
  ASSERT ( !(C == D) );

  /*Test 8
    verify C != D is true
  */
  ASSERT ( C != D );

  /*Test 9
    verify C < D is true
  */
  ASSERT ( C < D );

  /*Test 10
    verify C > D is false
  */
  ASSERT ( ! (C > D) );

  /*Test 11
    verify C <= D is true
  */
  ASSERT ( C <= D );

  /*Test 12
    verify C >= D is false
  */
  ASSERT ( ! (C >= D) );

  /*Test 13
    verify D == C is false
  */
  ASSERT ( !(D == C) );

  /*Test 14
    verify D != C is true
  */
  ASSERT ( D != C );

  /*Test 15
    verify D < C is false
  */
  ASSERT ( ! (D < C) );

  /*Test 16
    verify D > C is true
  */
  ASSERT ( D > C );

  /*Test 17
    verify D <= C is false
  */
  ASSERT ( !(D <= C) );

  /*Test 18
    verify D >= C is true
  */
  ASSERT ( D >= C );

  fraction E(-4, 5);
  fraction F(-2, 3);

  /*Test 19
    verify E == F is false
  */
  ASSERT ( !(E == F) );

  /*Test 20
    verify E != F is true
  */
  ASSERT ( E != F );

  /*Test 21
    verify E > F is false
  */
  ASSERT ( ! (E > F) );

  /*Test 22
    verify E <= F is true
  */
  ASSERT ( E <= F );

  /*Test 23
    verify E >= F is false
  */
  ASSERT ( ! (E >= F) );

  /*Test 24
    verify E < F is false
  */
  ASSERT ( ! (F < E) );

  /*Test 25
    verify F > E is true
  */
  ASSERT ( F > E );

  /*Test 26
    verify F <= E is false
  */
  ASSERT ( !(F <= E) );

  /*Test 27
    verify F >= E is true
  */
  ASSERT ( F >= E );

  /*Test 28
    verify C == F is true
  */
  ASSERT ( C == F );

  /*Test 29
    verify C != F is false
  */
  ASSERT ( ! (C != F) );

  /*Test 30
    verify C < F is false
  */
  ASSERT ( ! (C < F) );

  /*Test 31
    verify C > F is false
  */
  ASSERT ( ! (C > F) );

  /*Test 32
    verify C <= F is true
  */
  ASSERT ( C <= F );

  /*Test 33
    verify C >= F is true
  */
  ASSERT ( C >= F );

  return 0;

}
