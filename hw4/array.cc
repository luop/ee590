#include "array.hh"
#include "null.hh"
#include "exception.hh"

Array::Array() {
  max = 10;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = NULL;
  }
}

// Destructors
Array::~Array(){

  for ( int i=0; i < max; i++ ) {
    if (values[i]){
      delete values[i];
    }
  }

  if (values){
    delete[] values;
  }

}

Array::Array ( const Array &array ) {

  max = array.max;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = NULL;
    if ( array.values[i] ){
      values[i] = array.values[i]->clone();
    }
  }

}

void Array::set(int index, Object &object) {

  if (index < max){
    if ( values[index] ){
      delete values[index];
    }
    values[index] = object.clone();
  }else{
    int new_max = index + 1;
    Object ** new_values = new Object *[new_max];
    for ( int i=0; i < new_max; i++ ) {
      if (i < max){
        new_values[i] = values[i];
      }else if (i == index) {
        new_values[i] = object.clone();
      }else{
        new_values[i] = new Null();
      }
    }
    delete[] values;
    values = new_values;
    max = new_max;
  }
}

Object* Array::get(int index) {
  if ( 0 <= index && index < max && values[index] != NULL ) {
    return values[index];
  } else {
    throw json_exception("Array out of bounds");
  }
}

std::string Array::stringify() {

  std::string s = "[";

  int m = -1;

  for ( int i=0; i<max; i++ ) {
    if ( values[i] != NULL ) {
      m = i;
    }
  }

  for ( int i=0; i<=m; i++ ) {
    if ( values[i] != NULL ) {
      s += values[i]->stringify();
    } else {
      s += "null";
    }
    if ( i < m ) {
      s += ",";
    }
  }

  s += "]";

  return s;

}
