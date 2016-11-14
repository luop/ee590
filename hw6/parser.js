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
      .add(/\d+(?!\.)/)
      .add(/\.\d+/)
      .add(/\d+\.\d*/)
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
      //this.position = (this.str).indexOf('(', this.position) + 1;
      this.tokenizer.eat();
      var num = this.exr();
      if ( this.tokenizer.current() == ')' ){
        //this.position = (this.str).indexOf(')', this.position) + 1;
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

Parser.prototype.term = function(unary_minus) {
  // TODO
  var num = this.factor();

  if (unary_minus){
    num = (-1) * num;
  }

  while ( this.tokenizer.current() == '*' || this.tokenizer.current() == '/' || this.tokenizer.current() == '%' ) {
    if ( this.tokenizer.current() == '*' ){
      this.position = (this.str).indexOf('*', this.position);
      this.tokenizer.eat();
      num = num * this.factor();
    }

    if ( this.tokenizer.current() == '/' ){
      this.position = (this.str).indexOf('/', this.position);
      this.tokenizer.eat();
      var t = this.factor();
      if ( t != 0 ){
        num = num / t;
      }else{
        throw new exception("Divide by 0", this.position);
      }
    }

    if ( this.tokenizer.current() == '%' ){
      this.position = (this.str).indexOf('%', this.position);
      this.tokenizer.eat();
      var t = this.factor();
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
  var unary_minus = false;

  if ( this.tokenizer.current() == '+' ){
    this.position = (this.str).indexOf('+', this.position);
    this.tokenizer.eat();
    num = this.term(unary_minus);
  }else if ( this.tokenizer.current() == '-' ){
    this.position = (this.str).indexOf('-', this.position);
    this.tokenizer.eat();
    unary_minus = true;
    num = this.term(unary_minus);
    unary_minus = false;
  }else{
    num = this.term(unary_minus);
  }

  while ( this.tokenizer.current() == '+' || this.tokenizer.current() == '-' ) {
    if ( this.tokenizer.current() == '+' ){
      this.position = (this.str).indexOf('+', this.position);
      this.tokenizer.eat();
      num = num + this.term(unary_minus);
    }

    if ( this.tokenizer.current() == '-' ){
      this.position = (this.str).indexOf('-', this.position);
      this.tokenizer.eat();
      num = num - this.term(unary_minus);
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
