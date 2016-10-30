#include "object.hh"
#include "array.hh"

typedef struct _Bucket {
  std::string key;
  Object * value;
  _Bucket * next;
} Bucket;

class Hash : public Object {

public:

  Hash();

  // Destructors
  ~Hash();

  Hash ( const Hash &hash );

  Hash * clone() { return new Hash(*this); }
  void set ( std::string key, Object &value);
  Object * get ( std::string key ) const;
  std::string stringify();

  Array getKeys() const;

private:

  int hash ( std::string s ) const;
  static const int num_shelves = 256;
  Bucket * shelves[num_shelves];
  int numKeys = 0;

};
