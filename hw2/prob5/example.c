#include <stdio.h>
#include "matrix.h"

int main ( int argc, char * argv[] ) {

  Matrix * A = matrix_new ( 2, 2 ),
         * B = matrix_random ( 4, 4 ),
         * C, * D;

  matrix_set ( A, 0, 0, 1 ); matrix_set ( A, 0, 1, 2 );
  matrix_set ( A, 1, 0, 3 ); matrix_set ( A, 1, 1, 4 );

  C = matrix_add ( A, A );
  matrix_print ( C ); NL;
  matrix_destroy ( C );

  matrix_print ( B ); NL;
  C = matrix_minor ( B, 1 );
  matrix_print ( C ); NL;
  matrix_destroy ( C );

  printf ( "det = %lf\n", matrix_det ( B ) );

  C = matrix_identity ( 3 );
  matrix_print(C); NL;
  matrix_destroy(C);

  printf ("A matrix is: \n");
  matrix_print ( A ); NL;

  printf ("A matrix times 0.2 is: \n");
  C = matrix_scale ( A, 0.2 );
  matrix_print(C); NL;
  matrix_destroy(C);

  printf ("A transpose is: \n");
  C = matrix_transpose ( A );
  matrix_print(C); NL;
  matrix_destroy(C);

  printf ("A times A is - C: \n");
  C = matrix_mult ( A, A );
  matrix_print(C); NL;

  printf ("A power of 2 is - D: \n");
  D = matrix_power ( A, 2 );
  matrix_print(D); NL;

  printf ("Are C and D equal? %d\n", matrix_equal ( C, D ));

  printf ("Are A and B equal? %d\n", matrix_equal ( A, B ));

  printf ("Are A and C equal? %d\n", matrix_equal ( A, C ));

  matrix_destroy(C);
  matrix_destroy(D);

  C = matrix_from_file ( "data/m1.mat" );
  printf ("C matrix from m1.dat is: \n");
  matrix_print(C); NL;
  printf ( "det = %lf\n", matrix_det ( C ) );


  D = matrix_cofactor (C);
  printf ("C matrix cofactor is: \n");
  matrix_print ( D ); NL;
  matrix_destroy(D);

  printf ("C matrix inverse is D: \n");
  D = matrix_inverse ( C );
  matrix_print ( D ); NL;

  printf ("C times D: \n");
  matrix_print ( matrix_mult ( C, D ) ); NL;
  matrix_destroy(C);
  matrix_destroy(D);

  return 0;

}
