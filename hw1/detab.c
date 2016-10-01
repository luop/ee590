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

  //printf ("The file name is %s.\n",fileName);
  //printf ("The value entered is %d.\n",n);

  file = fopen(fileName, "r");

  if (file==NULL){
      printf ("Error reading file");
      return 1;
  }else{
    do {
      c = getc (file);
      if ( c == '\t'){
        int i;
        for ( i=0; i < n; i++ ) {
          putc(' ', stdout);
        }
      }else{
        putc(c, stdout);
      }
    } while (c != EOF);
    fclose (file);
  }
  return 0;
}
