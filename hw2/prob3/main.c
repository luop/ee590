#include <stdio.h>
#include <string.h>
#include "stack.h"

Stack * build_stack(char * filename) {

  FILE * file = fopen(filename, "r");

  Stack * s = stack_create ();

  char buf[100];

  while ( fgets(buf,1000, file )!=NULL ){
    //printf("%s",buf);
    push( s, buf );
  }

  fclose(file);

  return s;
}

void wrtie_csv(Stack * s, char * filename){

  FILE * file = fopen(filename, "w");
  //ASSERT ( file != NULL );

  int i;
  for (i = 0; i < s->size; i ++){
    //printf("%d", s->data[i]);
    //fputc(s->data[i] + '0', file);
    //fputc('\n', file);
    fprintf(file, "%s", s->data[i]);
  }

  fclose(file);
}

void print_stack(Stack * s){
  int i;
  for (i = 0; i < s->size; i ++){
    printf("%s", s->data[i]);
  }
}

void print_usage(char * program){
  printf("Usage: %s filename pop - pops the top element\n", program);
  printf("Usage: %s filename print_top - prints the top element\n", program);
  printf("Usage: %s filename swap_top - swaps the top two elements\n", program);
}

int main( int argc, char * argv[] ) {

  if ( argc != 3) {
    print_usage( argv[0] );
    return 1;
  }else{
    if( strcmp("pop", argv[2]) == 0 ){
      Stack * s = build_stack( argv[1] );
      printf("%s", pop( s ));
      wrtie_csv( s, argv[1] );
      stack_destroy ( s );
    }else if( strcmp("print_top", argv[2]) == 0 ){
      Stack * s = build_stack( argv[1] );
      //print_stack ( s );
      printf("%s", print_top( s ));
      stack_destroy ( s );
    }else if( strcmp("swap_top", argv[2]) == 0 ){
      Stack * s = build_stack( argv[1] );
      //print_stack( s );
      swap_top( s );
      print_stack( s );
      wrtie_csv( s, argv[1] );
      stack_destroy ( s );
    }else{
      print_usage( argv[0] );
    }
  }
}
