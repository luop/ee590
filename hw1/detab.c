#include <stdio.h>

int main ( int argc, char * argv[] ){

  if ( argc != 3) {
    printf ("Usage: %s filename n \n", argv[0]);
    return 1;
  }

  FILE *file;
  char * fileName = argv[1];
  char * number = argv[2];

  int n = atoi (number);

  file = fopen(fileName, "r");

  if (file==NULL){
      printf ("Error reading file \n");
      return 1;
  }
  else{ // read file
    char c;
    do {
      c = getc (file);
      if ( c == '\t'){ // replace tab with n spaces
        int i;
        for ( i=0; i < n; i++ ) {
          putc(' ', stdout);
        }
      }
      if ( c != '\0' && c != '\t') { // print out a character
        putc(c, stdout);
      }
    } while (c != EOF);
    fclose (file);
  }
  return 0;
}
