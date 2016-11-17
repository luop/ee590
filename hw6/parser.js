Tokenizer = require('./tokenizer.js')

// exception object
exception = require('./exception.js')

function Parser(str) {

  this.str = str; // the string to be parsed

  this.tokenizer = new Tokenizer();

  this.tokenizer
      .add(/\+/)
      .add(/-/) // Add tokens here
      .add(/\(/)
      .add(/\)/)
      .add(/\d+(?!\.)([eE][-+]?\d+)?/)
      .add(/\.\d+([eE][-+]?\d+)?/)
      .add(/\d+\.\d*([eE][-+]?\d+)?/)
      .add(/\*/)
      .add(/\//)
      .add(/%/);

  this.position = 0; // the character position of the tokenizer when the error is thrown

}

Parser.prototype.factor = function() {
  // TODO
  if ( !(isNaN(this.tokenizer.current())) ) {
      var num = this.tokenizer.float_val();
      this.position = (this.str).indexOf(this.tokenizer.current(), this.position);
      this.tokenizer.eat();
      return num;
  } else if ( this.tokenizer.current() == '(' ) {
      this.tokenizer.eat();
      var num = this.exr();
      if ( this.tokenizer.current() == ')' ){
        this.tokenizer.eat();
        return num;
      }else{
        this.position = (this.position < this.str.length - 1) ? ((this.str).indexOf(this.tokenizer.current(), this.position + 1)) : this.position;
        throw new exception("factor: syntax error", this.position);
      }
  } else {
      this.position = (this.position < this.str.length - 1) ? ((this.str).indexOf(this.tokenizer.current(), this.position + 1)) : this.position;
      throw new exception("factor: syntax error", this.position);
  }
}

Parser.prototype.unary = function() {
  var num = 0;

  if ( this.tokenizer.current() == '+' ){
    this.position = (this.str).indexOf('+', this.position);
    this.tokenizer.eat();
    num = this.factor();
  }else if ( this.tokenizer.current() == '-' ){
    this.position = (this.str).indexOf('-', this.position);
    this.tokenizer.eat();
    num = (-1) * this.factor();
  }else{
    num = this.factor();
  }

  return num;
}

Parser.prototype.term = function() {
  // TODO
  var num = this.unary();

  while ( this.tokenizer.current() == '*' || this.tokenizer.current() == '/' || this.tokenizer.current() == '%' ) {
    if ( this.tokenizer.current() == '*' ){
      this.position = (this.str).indexOf('*', this.position);
      this.tokenizer.eat();
      num = num * this.unary();
    }

    if ( this.tokenizer.current() == '/' ){
      this.position = (this.str).indexOf('/', this.position);
      this.tokenizer.eat();
      var t = this.unary();
      if ( t != 0 ){
        num = num / t;
      }else{
        throw new exception("Divide by 0", this.position);
      }
    }

    if ( this.tokenizer.current() == '%' ){
      this.position = (this.str).indexOf('%', this.position);
      this.tokenizer.eat();
      var t = this.unary();
      if ( t != 0 ){
        num = num % t;
        if (num < 0){
          num = (t - Math.abs(num)) % t;
        }
      }else{
        throw new exception("Modulo by 0", this.position);
      }
    }
  }

  return num;
}

Parser.prototype.exr = function() {
  // TODO
  var num = 0;

  if ( this.tokenizer.current() == '+' ){
    this.position = (this.str).indexOf('+', this.position);
    num = this.term();
  }else if ( this.tokenizer.current() == '-' ){
    this.position = (this.str).indexOf('-', this.position);
    num = this.term();
  }else{
    num = this.term();
  }

  while ( this.tokenizer.current() == '+' || this.tokenizer.current() == '-' ) {
    if ( this.tokenizer.current() == '+' ){
      this.position = (this.str).indexOf('+', this.position);
      this.tokenizer.eat();
      num = num + this.term();
    }

    if ( this.tokenizer.current() == '-' ){
      this.position = (this.str).indexOf('-', this.position);
      this.tokenizer.eat();
      num = num - this.term();
    }
  }

  return num;
}

Parser.prototype.parse = function() {
  // TODO
  this.tokenizer.tokenize(this.str);
  if ( this.tokenizer.current() == '(' ) {
    return this.exr();
  } else if ( this.tokenizer.current() == '+' ) {
    return this.exr();
  } else if ( this.tokenizer.current() == '-' ) {
    return this.exr();
  } else if ( !(isNaN(this.tokenizer.current())) ) {
    return this.exr();
  } else {
    var s = "Unexpected token ";
    var token = this.tokenizer.current();
    s += token;
    throw new exception(s, (this.str).indexOf(token, this.position));
  }
}

module.exports = Parser;
