#include <stdio.h>

int main ( int argc, char * argv[] )
{
  FILE *file;
  char c;

  if ( argc != 3) {
    printf ("Usage: %s filename n \n", argv[0]);
    return 1;
  }

  char * fileName = argv[1];
  char * number = argv[2];

  int n = atoi (number);

  file = fopen(fileName, "r");

  if (file==NULL){
      printf ("Error reading file \n");
      return 1;
  }
  else{
    do {
      c = getc (file);
      if ( c == '\t'){
        int i;
        for ( i=0; i < n; i++ ) {
          putc(' ', stdout);
        }
      }
      if ( c != '\0' && c != '\t') {
        putc(c, stdout);
      }
    } while (c != EOF);
    fclose (file);
  }
  return 0;
}
