#include "test.hh"
#include "matrix.hh"
#include "fraction.h"

int main ( int argc, char * argv[] ) {

  fraction A(3, 4);
  ASSERT ( A.numer() == 3 && A.denom() == 4 && A.posi() );

}
