#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrix_add ( Matrix * A, Matrix * B ) {

  ASSERT ( A->rows == B->rows && A->columns == B->columns );

  Matrix * C = matrix_new ( A->rows, A->columns );

  int i, j;

  for ( i=0; i<A->rows; i++ ) {
    for ( j=0; j<A->columns; j++ ) {
      matrix_set(C, i, j, matrix_get(A,i,j) + matrix_get(B,i,j) );
    }
  }

  return C;

}

Matrix * matrix_minor ( Matrix * M, int n ) {

  ASSERT ( 0 <= n && n < M->columns );

  Matrix * P = matrix_new ( M->rows - 1, M->columns - 1 );

  int i, j;

  for ( i=1; i<M->rows; i++ ) {
    for ( j=0; j<n; j++ ) {
      matrix_set(P,i-1,j,matrix_get(M,i,j));
    }
  }

  for ( i=1; i<M->rows; i++ ) {
    for ( j=n+1; j<M->columns; j++ ) {
      matrix_set(P,i-1,j-1,matrix_get(M,i,j));
    }
  }

  return P;

}

double matrix_det ( Matrix * M ) {

  if ( M->rows == 1 && M->columns == 1 ) {

    return matrix_get(M,0,0);

  } else {

    double sign = 1,
           sum = 0;

    int i;

    for ( i=0; i<M->columns; i++ ) {
      Matrix * P = matrix_minor ( M, i );
      sum += sign * matrix_get(M,0,i) * matrix_det(P);
      sign *= -1;
      matrix_destroy ( P );
    }

    return sum;

  }

}

int matrix_equal ( Matrix * A, Matrix * B ){
  if ( A->rows != B->rows || A->columns != B->columns){
    return 0;
  }else{
    int i, j;

    double precision = 0.00001;
    double a, b;
    int equal = 0;

    for ( i=0; i<A->rows; i++ ) {
      for ( j=0; j<A->columns; j++ ) {
        a = matrix_get(A,i,j);
        b = matrix_get(B,i,j);
        if ( ( ( a - precision ) < b ) && ( ( ( a + precision ) > b ) ) ){
          equal = 1;
          break;
        }
      }
    }
    return equal;
  }
}

Matrix * matrix_identity ( int n ){

  Matrix * C = matrix_new ( n, n );

  int i, j;

  for ( i=0; i<n; i++ ) {
    for ( j=0; j<n; j++ ) {
      if ( i == j){
        matrix_set(C, i, j, 1 );
      }else{
        matrix_set(C, i, j, 0 );
      }
    }
  }

  return C;
}

Matrix * matrix_scale ( Matrix * M, double s ){

  Matrix * C = matrix_new ( M->rows, M->columns );

  int i, j;

  for ( i=0; i<M->rows; i++ ) {
    for ( j=0; j<M->columns; j++ ) {
      matrix_set(C, i, j, matrix_get(M,i,j) * s  );
    }
  }

  return C;
}

Matrix * matrix_transpose ( Matrix * M ){

  Matrix * C = matrix_new ( M->columns, M->rows );

  int i, j;

  for ( i=0; i<M->rows; i++ ) {
    for ( j=0; j<M->columns; j++ ) {
      matrix_set(C, j, i, matrix_get(M,i,j) );
    }
  }

  return C;
}

Matrix * matrix_mult ( Matrix * A, Matrix * B ){

  ASSERT ( A->columns == B->rows );

  Matrix * C = matrix_new ( A->rows, B->columns );

  int i, j, k;

  double sum = 0;

  for ( i=0; i<A->rows; i++ ) {
    for ( j=0; j<B->columns; j++ ) {
      for ( k = 0; k < B->rows; k ++){
        sum = sum + matrix_get(A,i,k) * matrix_get(B,k,j);
      }
      matrix_set(C, i, j, sum);
      sum = 0;
    }
  }

  return C;
}

Matrix * matrix_power ( Matrix * M, int n ){

  if ( n == 0 ){

    return matrix_identity ( M->rows );

  }else if ( n == 1 ){

    return M;

  }else {

    return matrix_mult ( M, matrix_power ( M, n - 1) );

  }

}
