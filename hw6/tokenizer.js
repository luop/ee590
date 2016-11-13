function Tokenizer(regexps) {

  this.re_string = "";
  this.re;
  this.tokens = [];
  this.i = 0;
  this.current_token = "";

  if ( regexps ) {
    for ( var i=0; i<regexps.length; i++ ) {
      this.add(regexps[i]);
    }
  }

}

Tokenizer.prototype.add = function(regexp) {
  if ( this.re_string == "" ) {
    this.re_string = regexp.source;
  } else {
    this.re_string += "|" + regexp.source;
  }
  this.re = RegExp(this.re_string,"g");
  return this;
}

Tokenizer.prototype.tokenize = function(str) {
  this.tokens = str.match(this.re);
  return this;
}

Tokenizer.prototype.current = function() {
  // TODO: Return current token
  if ( i == 0 ) {
    this.current_token = this.next();
  }

  return this.current_token;
}

Tokenizer.prototype.float_val = function() {
  // Possibly useful to return the current value as a float
  // or return NaN if it doesn't evaluate (using the built in
  // method parseFloat)
  return parseFloat(this.current());
}

Tokenizer.prototype.next = function() {
  // TODO
  return (this.tokens[(this.i)++]);
}

Tokenizer.prototype.eat = function() {
  // TODO
  if ( !(this.eof()) ) {
    this.current_token = this.next();
  }
  return this.current_token;
}

Tokenizer.prototype.eof = function() {
  // TODO
  return ( this.i >= this.tokens.length );
}

module.exports = Tokenizer;
