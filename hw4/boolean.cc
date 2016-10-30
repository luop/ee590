#include "boolean.hh"

Boolean::Boolean(bool b) : value(b) {
}

// Destructors
Boolean::~Boolean(){}

std::string Boolean::stringify() {

  std::string s;

  if (value){
    s = "true";
  }else{
    s = "false";
  }

  return s;
}
