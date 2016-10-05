#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fsm.h"

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
  char *data;
  char alphabet[1000];

  int i = 0, j, k;
  int temp[300][300];

  // line number of the file
  int line = 1;

  // array to store accecpt states
  int accept[100];

  // the number of accept state
  int numaccept = 0;

  while ( fgets(buf,1000, file )!=NULL ){ //read file
    if ( line == 1 ){ // Get input alphabet
      for(k=0; buf[k]!='\0'; k ++){
        alphabet[k]=buf[k];
      }
      alphabet[k] = '\0';
    }else if ( line == 2 ){
      if ( strrchr (buf,',') > 0 ){
        data = strtok(buf, ",");
        j = 0;
        while ( data != NULL){ // add all accept states to an array
          accept[j] = atoi(data);
          data = strtok(NULL, ",");
          j ++;
        }
        numaccept = j;
      }else{ // put a single accept state to an array
        accept[0] = atoi(buf);
        numaccept = 1;
      }
    }else {
      if ( strrchr (buf,',') > 0 ){
        data = strtok(buf, ",");
        j = 0;
        while ( data != NULL){ // build fsm tables based on csv file
          temp[i][j] = atoi(data);
          data = strtok(NULL, ",");
          j ++;
        }
        i ++;
      }
    }
    line ++;
  }

  // get the number of rules
  int numRules = j;
  int r[i][numRules];

  int m, n;
  for ( m = 0; m < i; m ++){
    for (n = 0; n < j; n ++){
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

  // get the final state of the input
  int finalState = fsm(alphabet,numRules,r,input);

  int isaccept = 0;

  //printf ("The final state of the FSM is %d \n", finalState);

  // Check if the fsm reaches accept state
  for ( k=0; k < numaccept; k ++) {
    if ( accept[k] == finalState ) {
      isaccept = 1;
      break;
    }
  }

  if ( isaccept  ) { // the fsm is in accept state
    printf ( "accept\n");
  } else {
    printf ( "reject\n");
  }
}
