#include <iostream>
#include <math.h>
#include "ComplexNum.h"

#define PI 3.14159265

ComplexNum ComplexNum::conjugate () {

  double r = realNum();
  double i = imagNum();

  ComplexNum j(r, (-1) * i);
  return j;
}

ComplexNum ComplexNum::add ( const ComplexNum &c ) const {

  double r1 = realNum();
  double i1 = imagNum();

  double r2 = c.realNum();
  double i2 = c.imagNum();

  ComplexNum a( (r1 + r2), (i1 + i2) ) ;
  return a;
}

ComplexNum ComplexNum::subtract ( const ComplexNum &c ) const {

  double r1 = realNum();
  double i1 = imagNum();

  double r2 = c.realNum();
  double i2 = c.imagNum();

  ComplexNum s( (r1 - r2), (i1 - i2) ) ;
  return s;
}

ComplexNum ComplexNum::mult ( const ComplexNum &c ) const {

  double r1 = realNum();
  double i1 = imagNum();

  double r2 = c.realNum();
  double i2 = c.imagNum();

  double r = r1 * r2 - i1 * i2;
  double i = i1 * r2 + r1 * i2;

  ComplexNum m( r, i ) ;
  return m;
}

ComplexNum ComplexNum::divide ( const ComplexNum &c ) const {

  double r1 = realNum();
  double i1 = imagNum();

  double r2 = c.realNum();
  double i2 = c.imagNum();

  if ( r2 == 0 && i2 == 0 ){
    throw ComplexNum_exception("Cannot divide 0");
  }

  double r = (r1 * r2 + i1 * i2)/(pow(r2, 2) + pow(i2, 2));
  double i = (i1 * r2 - r1 * i2)/(pow(r2, 2) + pow(i2, 2));

  ComplexNum d( r, i ) ;
  return d;
}

double ComplexNum::magnitude () {

  double r = realNum();
  double i = imagNum();

  return sqrt(pow(r, 2) + pow(i, 2));
}

double ComplexNum::angle () {

  double r = realNum();
  double i = imagNum();

  double a;

  if ( r > 0 ){
    a = atan (i/r) * 180 / PI;
  }else if ( ( r < 0 ) && ( i >= 0) ){
    a = atan (i/r) * 180 / PI + 180;
  }else if ( ( r < 0 ) && ( i < 0) ){
    a = atan (i/r) * 180 / PI - 180;
  }else if ( ( r == 0 ) && ( i > 0) ){
    a = 90;
  }else if ( ( r == 0 ) && ( i < 0) ){
    a = -90;
  }else{
    throw ComplexNum_exception("Indeterminate polar angle");
  }

  return a;
}

ComplexNum ComplexNum::power ( int p ) {

  if ( p < 0 ){

    throw ComplexNum_exception("Power function only supports power >= 0");

  } else if( p == 0 ){

    ComplexNum t = 1;
    return t;
  }
  else{
    
    return mult(power(p-1));
  }
}

ComplexNum ComplexNum::expPower () {

  double r = realNum();
  double i = imagNum();

  double er = exp(r);
  double cosi = cos(i);
  double sini = sin(i);

  ComplexNum e(er*cosi, er*sini);
  return e;
}

bool ComplexNum::equals ( const ComplexNum &c ) const{

  double r1 = realNum();
  double i1 = imagNum();

  double r2 = c.realNum();
  double i2 = c.imagNum();

  return ( (r1 == r2) && (i1 == i2));
}
