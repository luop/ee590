#include "hash.hh"
#include "null.hh"
#include "exception.hh"

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

  // TODO: method keys() that returns an Array of keys
  //           for ( k in keys() ) {
  //             set(k,hash.get(k))
  //           }

  //hash.get("first");

  std::vector<std::string> keys = hash.getKeys();

  Object * o;

  for(std::vector<std::string>::iterator it = keys.begin(); it != keys.end(); ++it) {

    o = hash.get((*it));
    set((*it), (*o));

  }


}

void Hash::set ( std::string key, Object &value ) {

  // TODO: Homework: Use delete if key exists to avoid duplicate keys
  //       or reset the value in place (make sure to delete old value!)

  int i = hash(key);

  Bucket * ptr_current = shelves[i];

  while ( ptr_current && ptr_current->key != key ) {
    ptr_current = ptr_current->next;
  }

  if ( ptr_current ) { // find duplicate keys
    if (ptr_current->value){
      delete (ptr_current->value);
    }
    ptr_current->value = value.clone();
  } else {
    Bucket * ptr = new Bucket;

    ptr->key = key;
    ptr->value = value.clone();
    ptr->next = shelves[i];
    shelves[i] = ptr;
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
      s += ptr->key + ":" + ptr->value->stringify() + ",";
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

std::vector<std::string> Hash::getKeys() const{

  std::vector<std::string> keys;

  Bucket * ptr;

  for ( int i=0; i<num_shelves; i++ ) {
    ptr = shelves[i];
    while ( ptr != NULL ) {
      keys.push_back(ptr->key);
      ptr = ptr->next;
    }
  }

  return keys;
}
