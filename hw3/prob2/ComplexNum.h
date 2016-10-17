#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H

#include <iostream>
#include <stdexcept>

class ComplexNum_exception : public std::runtime_error {
public:
  ComplexNum_exception(const char msg[]) : std::runtime_error(msg) { }
};

class ComplexNum{
  private :
    double real;
    double imaginary;
  public :
    // Constructors and destructors
    ComplexNum(double r, double i);
    ComplexNum(double r) : ComplexNum(r,0) {};
    ~ComplexNum();

    // The copy constructor
    ComplexNum( const ComplexNum &c );
    ComplexNum& operator=(const ComplexNum &other);

    inline double realNum(void) const { return real; }
    inline double imagNum(void) const { return imaginary; }

    // Operations
    ComplexNum conjugate ();
    ComplexNum add ( const ComplexNum &c ) const;
    ComplexNum subtract ( const ComplexNum &c ) const;
    ComplexNum mult ( const ComplexNum &c ) const;
    ComplexNum divide ( const ComplexNum &c ) const;
    double magnitude ();
    double angle ();
    ComplexNum power ( int p );
    ComplexNum expPower ();
    bool equals ( const ComplexNum &c ) const;
    //bool less_than ( const ComplexNum &c ) const;

    inline ComplexNum operator=(double n) { return ComplexNum(n); }

    inline ComplexNum operator+(const ComplexNum &c) { return add(c); }
    inline ComplexNum operator-(const ComplexNum &c) { return subtract(c); }
    inline ComplexNum operator*(const ComplexNum &c) { return mult(c); }
    inline ComplexNum operator/(const ComplexNum &c) { return divide(c); }

    // Overload '-', the unary minus operator to negate a ComplexNum
    inline ComplexNum operator-() { return ComplexNum((-1) * realNum(), (-1) * imagNum()); }

    inline bool operator==(const ComplexNum &c) { return equals(c); }
    inline bool operator!=(const ComplexNum &c) { return !equals(c); }

    //inline bool operator<(const ComplexNum &c) { return less_than(f); }
    //inline bool operator>(const ComplexNum &c) { return f.less_than(*this); }
    //inline bool operator<=(const ComplexNum &c) { return less_than(f) || equals(f); }
    //inline bool operator>=(const ComplexNum &c) { return f.less_than(*this) || f.equals(*this); }
};

// Interface with ostreams
std::ostream& operator<<(std::ostream& os, const ComplexNum &c);

#endif
