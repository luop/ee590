#include <stdio.h>
#include <string.h>
#include "fsm.h"

#define ACCEPT 2
#define REJECT 3
#define NUM_RULES 3

int main ( int argc, char * argv[] ) {

  if ( argc != 3) {
    printf ("Usage: %s filename input \n", argv[0]);
    return 1;
  }

  FILE *file;
  char * fileName = argv[1];
  file = fopen(fileName, "r");

  if (file==NULL){
      printf ("Error reading file \n");
      return 1;
  }

  char buf[1000];
  char *states;
  char alphabet[1000];

  int i = 0, j, k;
  int temp[300][300];

  while ( fgets(buf,1000, file )!=NULL ){
    printf("%s",buf);

    if ( strrchr (buf,',') > 0 ){
      states = strtok(buf, ",");
      j = 0;
      while ( states != NULL){
        temp[i][j] = atoi(states);
        states = strtok(NULL, ",");
        j ++;
      }
      i ++;
    }else{
      //Get input alphabet
      for(k=0; buf[k]!='\0'; k ++){
        alphabet[k]=buf[k];
      }
      alphabet[k] = '\0';
    }
  }

  int numRules = j;
  int r[i][numRules];

  int m, n;
  for ( m = 0; m < i; m ++){

    for (n = 0; n < j; n ++){
      printf ("m is %d, n is %d, state is %d \n", m, n, temp[m][n]);
      r[m][n] = temp[m][n];
    }
  }

  fclose(file);

  /*
     Example Regular Expression: ab*c
     0 -a-> 1                2 = ACCEPT
     1 -b-> 1                3 = REJECT
     1 -c-> 2
   */

  /* Check the input string */
  char * input = argv[2];
  int finalState = fsm(alphabet,numRules,r,input);
  if ( finalState == ACCEPT ) {
    printf ( "accept\n");
  } else {
    printf ( "reject\n");
  }

  printf ("The final state of the FSM is %d \n", finalState);
}
