#include "hash.hh"
#include "null.hh"
#include "exception.hh"
#include "string.hh"
#include <iostream>

Hash::Hash() {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

}

// Destructors
Hash::~Hash(){

  Bucket * ptr = NULL;
  Bucket * ptr_next = NULL;

  for ( int i=0; i<num_shelves; i++ ) {
    ptr = shelves[i];
    while ( ptr != NULL ) {

      delete ptr->value;
      ptr_next = ptr->next;
      delete ptr;
      ptr = ptr_next;

    }
  }
}

Hash::Hash ( const Hash &hash ) {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

  Array keys = hash.getKeys();

  std::string s;

  Object * o;

  for (int i = 0; i < hash.numKeys; i ++) {

    s = keys.get(i)->stringify();
    s.replace(0, 1, "");
    s.replace(s.length() - 1, 1, "");
    o = hash.get(s)->clone();
    set(s, (*o));

  }


}

void Hash::set ( std::string key, Object &value ) {

  int i = hash(key);

  Bucket * ptr_current = shelves[i];

  while ( ptr_current && ptr_current->key != key ) {
    ptr_current = ptr_current->next;
  }

  if ( ptr_current ) { // find duplicate keys
    if (ptr_current->value){
      //delete old value
      delete (ptr_current->value);
    }
    //reset the value in place
    ptr_current->value = value.clone();
  } else {
    Bucket * ptr = new Bucket;

    ptr->key = key;
    ptr->value = value.clone();
    ptr->next = shelves[i];
    shelves[i] = ptr;

    numKeys ++;
  }

}

Object * Hash::get ( std::string key ) const {

  int i = hash(key);
  Bucket * ptr = shelves[i];

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  if ( ptr ) {
    return ptr->value;
  } else {
    throw json_exception("No value for key");
  }

}

int Hash::hash ( std::string s ) const{

  int n = 0;

  for ( int i=0; i<s.length(); i++ ) {
    n += (int) s[i];
  }

  return n % num_shelves;

}

std::string Hash::stringify() {

  std::string s = "{";

  for ( int i=0; i<num_shelves; i++ ) {
    Bucket * ptr = shelves[i];
    while ( ptr != NULL ) {
      s += "\"" + ptr->key + "\":" + ptr->value->stringify() + ",";
      ptr = ptr->next;
    }
  }

  if ( s[s.length()-1] == ',' ) {
    s[s.length()-1] = '}';
  } else {
    s += "}";
  }

  return s;

}

Array Hash::getKeys() const{

  Array keys;
  String s("");
  Bucket * ptr;

  int index = 0;

  for ( int i=0; i<num_shelves; i++ ) {
    ptr = shelves[i];
    while ( ptr != NULL ) {
      s.set(ptr->key);
      keys.set(index,s);
      ptr = ptr->next;
      index ++;
    }
  }

  return keys;
}
