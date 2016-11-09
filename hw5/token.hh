#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

class Token {

public:

  typedef enum { STRING, NUMBER, EXPONENTS, BOOLEAN, PUNCTUATION, NULLTOK } TOKEN_TYPE;

  Token(std::string s) : str(s), token_type(STRING) {}
  Token(const char s[]) : str(s), token_type(STRING) {}
  Token(double d, bool b) : number(d), is_integer(b), token_type(NUMBER) {}
  Token(double d, double e, bool b) : number(d), exponents(e), is_integer(b), token_type(EXPONENTS) {}
  Token(bool b) : boolean(b), token_type(BOOLEAN) {}
  Token(char c) : punctuation(c), token_type(PUNCTUATION) {}
  Token() : token_type(NULLTOK) {}

  TOKEN_TYPE type() const { return token_type; }

  inline bool matches(char c) { return token_type == PUNCTUATION && punctuation == c; }

  inline bool is_string(void) { return token_type == STRING; }
  inline bool is_bool(void) { return token_type == BOOLEAN; }
  inline bool is_number(void) { return token_type == NUMBER; }
  inline bool is_exponents(void) { return token_type == EXPONENTS; }
  inline bool is_int(void) { return is_integer; }
  inline bool is_null(void) { return token_type == NULLTOK; }

  inline std::string string_val() { return str; }
  inline double number_val() { return number; }
  inline double exponents_val() { return exponents; }
  inline bool bool_val() { return boolean; }

  std::string to_s ( void );

  friend std::ostream& operator<<(std::ostream& os, const Token &tok);

private:

  TOKEN_TYPE token_type;
  std::string str;
  double number;
  bool boolean;
  char punctuation;
  double exponents = 0;
  bool is_integer;

};

#endif
