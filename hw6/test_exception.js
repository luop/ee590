Parser = require('./parser.js');

try {
   p = new Parser(")0.5*2");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}

try {
   p = new Parser("0.5 * (2+");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}

try {
   p = new Parser("0.5*(2+ *");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}

try {
   p = new Parser("0.5*(2+)");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}

try {
   p = new Parser("0.5* *(2+)");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}

try {
   p = new Parser("0.5/(2 - 2)-1");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}

try {
   p = new Parser("0.5%(2-2)-1");
   p.parse();
} catch (e) {
   console.log(e.name, "at the character position of ", e.position);
}
