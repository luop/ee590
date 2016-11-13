Tokenizer = require('./tokenizer.js')

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

}

Parser.prototype.factor = function() {
  // TODO
  if ( !(isNaN(this.tokenizer.current())) ) {
      var num = this.tokenizer.float_val();
      this.tokenizer.eat();
      return num;
  } else if ( this.tokenizer.current() == '(' ) {
      this.tokenizer.eat();
      var num = this.exr();
      if ( this.tokenizer.current() == ')' ){
        this.tokenizer.eat();
        return num;
      }else{
        return 0;
      }
  } else {
      //throw ParserException("factor: syntax error");
      return 0;
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
      this.tokenizer.eat();
      num = num * this.factor();
    }

    if ( this.tokenizer.current() == '/' ){
      this.tokenizer.eat();
      var t = this.factor();
      if ( t != 0 ){
        num = num / t;
      }else{

      }
    }

    if ( this.tokenizer.current() == '%' ){
      this.tokenizer.eat();
      var t = this.factor();
      if ( t != 0 ){
        num = num % t;
      }else{

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
    this.tokenizer.eat();
    num = this.term(unary_minus);
  }else if ( this.tokenizer.current() == '-' ){
    this.tokenizer.eat();
    unary_minus = true;
    num = this.term(unary_minus);
    unary_minus = false;
  }else{
    num = this.term(unary_minus);
  }

  while ( this.tokenizer.current() == '+' || this.tokenizer.current() == '-' ) {
    if ( this.tokenizer.current() == '+' ){
      this.tokenizer.eat();
      num = num + this.term(unary_minus);
    }

    if ( this.tokenizer.current() == '-' ){
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
    return 0;
  }
}

module.exports = Parser;
