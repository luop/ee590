Tokenizer = require('./tokenizer.js');

t = new Tokenizer();

t.add(/\+/)
 .add(/-/)
 .add(/\(/)
 .add(/\)/)
 .add(/\d+(?!\.)/)
 .add(/\.\d+/)
 .add(/\d+\.\d*/)
 .add(/\*/)
 .add(/\//)
 .add(/%/)
 .tokenize("0.5*(-1+2/3.0)");

 console.log(t.tokens);

 while ( !(t.eof()) ) {
  var token = t.eat();
  switch (token) {
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case '(':
  case ')':
    console.log("PUNCTUATION: " + token);
    break;
  default:
    console.log("NUMBER: " + token);
  }
 }

e = new Tokenizer();

e.add(/\+/)
 .add(/-/)
 .add(/\(/)
 .add(/\)/)
 .add(/\d+(?!\.)([eE][-+]?\d+)?/)
 .add(/\.\d+([eE][-+]?\d+)?/)
 .add(/\d+\.\d*([eE][-+]?\d+)?/)
 .add(/\*/)
 .add(/\//)
 .add(/%/)
 .tokenize("0.5e10*(-1e10+2e-3/3.0E+4)");

 console.log(e.tokens);

 while ( !(e.eof()) ) {
  var token = e.eat();
  switch (token) {
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case '(':
  case ')':
    console.log("PUNCTUATION: " + token);
    break;
  default:
    console.log("NUMBER: " + token);
  }
 }
