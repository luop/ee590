#include <iostream>
#include <math.h>
#include "fraction.h"

fraction fraction::ReduceToLowest () {

  int n = numer();
  int d = denom();
  bool p = posi();

  int s = std::min(n, d);

  for ( int i = s; i > 0; i --){

    if ( (n % i) == 0 && (d % i) == 0) {
      n = n / i;
      d = d / i;
    }
  }

  if ( !p ) {
    d = (-1) * d;
  }

  fraction r(n, d);
  return r;
}

fraction fraction::add ( const fraction &f ) const {

  int n1 = numer();
  int d1 = denom();
  bool p1 = posi();

  int n2 = f.numer();
  int d2 = f.denom();
  bool p2 = f.posi();

  int n, d;
  d = d1 * d2;

  if ( p1 && p2) {
    n = n1 * d2 + n2 * d1;
  }else if ( !p1 && p2 ) {
    n = n2 * d1 - n1 * d2;
  }else if ( p1 && !p2 ) {
    n = n1 * d2 - n2 * d1;
  }else {
    n = (-1) * (n1 * d2 + n2 * d1);
  }

  fraction a(n, d);
  return a.ReduceToLowest();
}

fraction fraction::subtract ( const fraction &f ) const {

  int n = f.numer();
  int d = f.denom();
  bool p = f.posi();

  if ( p ) {
    d = (-1) * d;
  }

  fraction a(n, d);
  return add(a);
}

fraction fraction::mult ( const fraction &f ) const {

  int n1 = numer();
  int d1 = denom();
  bool p1 = posi();

  int n2 = f.numer();
  int d2 = f.denom();
  bool p2 = f.posi();

  int n = n1 * n2, d;

  if ( (p1 && p2) || (!p1 && !p2) ){
    d = d1 * d2;
  }else{
    d = (-1) * d1 * d2;
  }

  fraction a(n, d);
  return a.ReduceToLowest();
}

fraction fraction::divide ( const fraction &f ) const {

  int n = f.numer();
  int d = f.denom();
  bool p = f.posi();

  if ( n == 0 ) {
    throw fraction_exception("Denominator cannot be 0");
  }

  if ( !p ) {
    d = (-1) * d;
  }

  fraction a(d, n);
  return mult(a);
}

bool fraction::equals ( const fraction &f ) const{

  int n1 = numer();
  int d1 = denom();
  bool p1 = posi();

  int n2 = f.numer();
  int d2 = f.denom();
  bool p2 = f.posi();

  return ( ( ( n1 * d2 ) == ( n2 * d1 ) ) && (p1 == p2) );
}

bool fraction::less_than ( const fraction &f ) const{

  int n1 = numer();
  int d1 = denom();
  bool p1 = posi();

  int n2 = f.numer();
  int d2 = f.denom();
  bool p2 = f.posi();

  bool smaller;

  if ( !p1 && p2){
    smaller = true;
  }else if ( p1 && !p2){
    smaller = false;
  }else if ( p1 && p2 ){
    smaller = ( n1 * d2 ) < ( n2 * d1 );
  }else{
    smaller = ( n1 * d2 ) > ( n2 * d1 );
  }

  return smaller;
}

fraction fraction::power ( int power ) {

  int n = numer();
  int d = denom();
  bool p = posi();

  int np, dp;

  if ( power == 0 ) {
    np = 1;
    dp = 1;
  }
  else if ( power > 0) {
    np = pow(n, power);
    dp = pow(d, power);
  }else{
    if ( n == 0 ) {
      throw fraction_exception("Denominator cannot be 0");
    }
    power = abs(power);
    dp = pow(n, power);
    np = pow(d, power);
  }

  if ( !p && ( (power % 2) != 0 ) ){
    dp = (-1) * dp;
  }
  fraction a(np, dp);
  return a;
}
