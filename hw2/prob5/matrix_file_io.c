#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrix_from_file ( const char filename[] ) {

  Matrix * M;
  FILE * fp = fopen ( filename, "r" );
  ASSERT ( fp != NULL );

  int rows = 0, cols = 0;

  fscanf ( fp, "%d,%d", &rows, &cols );
  ASSERT ( rows > 0 && cols > 0 );

  M = matrix_new ( rows, cols );

  int i, j;

  for ( i=0; i<rows; i++ ) {
    for ( j=0; j<cols; j++ ) {
      double x;
      char c;
      fscanf ( fp, "%lf", &x );
      ASSERT ( !feof(fp) );
      fscanf ( fp, "%c", &c );
      ASSERT ( !feof(fp) );
      matrix_set ( M, i, j, x );
    }
  }

  fclose(fp);

  return M;

}
