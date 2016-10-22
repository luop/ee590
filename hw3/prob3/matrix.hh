#include <iostream>
#include <stdexcept>

class matrix_exception : public std::runtime_error {
public:
  matrix_exception(const char msg[]) : std::runtime_error(msg) { }
};

template <class T>
class matrix {

public:

  matrix(int r, int c);
  matrix(int s) : matrix(s,s) {};
  ~matrix();

  static matrix identity( int s );
  // The copy constructor
  matrix ( const matrix &m );

  matrix add ( const matrix &m ) const;
  void set(int r, int c, T x);
  T get(int r, int c) const;
  inline int rows(void) const { return num_rows; }
  inline int columns(void) const { return num_columns; }
  bool in_range(int r, int c) const;

  matrix mult ( const matrix &m ) const;
  void scale ( T d );
  matrix minnor ( int r, int c );
  T det(void);
  matrix inverse ( void );
  bool equals ( const matrix & m ) const;
  bool less_than ( const matrix & m ) const;

  inline matrix operator+(const matrix &m) { return add(m); }
  inline matrix operator-(const matrix &m) { matrix temp = m; temp.scale(-1); return add(temp); }
  inline matrix operator*(const matrix &m) { return mult(m); }
  inline bool operator==(const matrix &m) { return equals(m); }
  inline bool operator!=(const matrix &m) { return !equals(m); }

  inline bool operator<(const matrix &m) { return less_than(m); }
  inline bool operator>(const matrix &m) { return m.less_than(*this); }
  inline bool operator<=(const matrix &m) { return less_than(m) || equals(m); }
  inline bool operator>=(const matrix &m) { return m.less_than(*this) || m.equals(*this); }

private:
  int num_rows, num_columns;
  T * value;

};

// Interface with ostreams
template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T> &m);

#include "matrix.impl.hh"
#include "matrix.ops.hh"
