template <class T>
matrix<T> matrix<T>::mult ( const matrix &m ) const {

  if ( columns() != m.rows() ) {
    throw matrix_exception("Attemped to multiple matrices with incompatible sizes");
  }

  matrix<T> M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      M.set(i,j,0);
      for ( int k=0; k<columns(); k++ ) {
        M.set(i,j, (T) (M.get(i,j) + get(i,k) * m.get(k,j)));
      }
    }
  }

  return M;

}

template <class T>
void matrix<T>::scale ( T d ) {
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      set(i,j, (T) (d*get(i,j)));
    }
  }
}

template <class T>
matrix<T> matrix<T>::minnor ( int r, int c ) {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Attempted to take minnor with out of range indices");
  }

  matrix<T> p ( rows() - 1, columns() - 1 );

  int I, J;

  for ( int i=0, I=0; i<rows(); i++ ) {
    for ( int j=0, J=0; j<columns(); j++ ) {
      if ( i != r && j != c ) {
        p.set(I,J, (T) (get(i,j)));
        J++;
      }
    }
    if ( i != r ) {
      I++;
    }
  }

  return p;

}

template <class T>
T matrix<T>::det(void) {

  if ( rows() == 1 && columns() == 1 ) {

    return (T) (get(0,0));

  } else {

    T sign = 1, sum = 0;

    for ( int i=0; i<columns(); i++ ) {
      sum += sign * (T) (get(0,i)) * (T) (minnor(0,i).det());
      sign *= -1;
    }

    return sum;

  }

}

template <class T>
matrix<T> matrix<T>::inverse ( void ) {

  matrix<T> m(rows(),columns());

  if ( rows() != columns() ) {
    throw matrix_exception("Attempted to invert non-square matrix");
  }

  T d = det();

  if ( d == 0 ) {
    throw matrix_exception("Attempted to invert non-invertible matrix");
  }

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      T sign = ( (i+j)%2 == 0 ) ? 1 : -1;
      m.set(i,j, (T) (sign*minnor(j,i).det()/d));
    }
  }

  return m;

}

template <class T>
bool matrix<T>::equals ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( (T) (get(i,j)) != (T) (m.get(i,j)) ) {
        return false;
      }
    }
  }
  return true;
}

template <class T>
bool matrix<T>::less_than ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( (T) (get(i,j)) >= (T) (m.get(i,j)) ) {
        return false;
      }
    }
  }
  return true;
}
