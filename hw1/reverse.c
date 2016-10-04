#include <stdio.h>

int main ( int argc, char * argv[] ){

  if ( argc != 2) {
    printf ("Usage: %s filename \n", argv[0]);
    return 1;
  }

  FILE *file;
  char * fileName = argv[1];
  file = fopen(fileName, "r");

  if (file==NULL){
      printf ("Error reading file \n");
      return 1;
  }
  else{ //read file
    char c;
    int i = 0;

    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    rewind(file);
    char fileChar[length];

    do { // put the characters into array
      c = getc (file);
      fileChar[i] = c;
      i ++;
    } while (c != EOF);

    int j;
    // print the characters in reverse
    for (j=length-1; j >= 0; j --){
      putc(fileChar[j], stdout);
    }
    printf("\n");

    fclose (file);
  }
  return 0;
}
