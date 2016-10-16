#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class fraction_exception : public std::runtime_error {
public:
  fraction_exception(const char msg[]) : std::runtime_error(msg) { }
};

class fraction{
  private :
    int numerator;
    int denominator;
    bool positive;
  public :
    // Constructors and destructors
    fraction(int n, int d);
    fraction(int n) : fraction(n,1) {};
    ~fraction();

    // The copy constructor
    fraction( const fraction &f );
    fraction& operator=(const fraction &other);

    inline int numer(void) const { return numerator; }
    inline int denom(void) const { return denominator; }
    inline bool posi(void) const { return positive; }

    // Operations
    fraction ReduceToLowest ();
    fraction add ( const fraction &f ) const;
    fraction subtract ( const fraction &f ) const;
    fraction mult ( const fraction &f ) const;
    fraction divide ( const fraction &f ) const;
    fraction power ( const fraction &f ) const;
    bool equals ( const fraction &f ) const;
    bool less_than ( const fraction &f ) const;

    inline fraction operator=(int n) { return fraction(n); }

    inline fraction operator+(const fraction &f) { return add(f); }
    inline fraction operator-(const fraction &f) { return subtract(f); }
    inline fraction operator*(const fraction &f) { return mult(f); }
    inline fraction operator/(const fraction &f) { return divide(f); }

    // Overload '-', the unary minus operator to negate a fraction
    inline fraction operator-() { return fraction(numer(), (-1) * denom()); }

    inline bool operator==(const fraction &f) { return equals(f); }
    inline bool operator!=(const fraction &f) { return !equals(f); }

    inline bool operator<(const fraction &f) { return less_than(f); }
    inline bool operator>(const fraction &f) { return f.less_than(*this); }
    inline bool operator<=(const fraction &f) { return less_than(f) || equals(f); }
    inline bool operator>=(const fraction &f) { return f.less_than(*this) || f.equals(*this); }
};

// Interface with ostreams
std::ostream& operator<<(std::ostream& os, const fraction &f);

#endif
