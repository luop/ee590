
#include <stdio.h>
#include <string.h>
#include "stack.h"

Stack * build_stack(char * filename) {

  FILE * file = fopen(filename, "r");
  //ASSERT ( file != NULL );

  Stack * s = stack_create ();

  fseek(file, 0, SEEK_END);

  int length = ftell(file);

  int i = 1;
  char c;

  for( i = 1; i <= length; i ++){
    fseek(file, -i, SEEK_END);
    c = fgetc(file);
    //printf("char is %c", c);
    if ( isdigit(c) ){
      //printf("int is %d\n", c - '0');
      push( s, c - '0' );
    }
  }
  fclose(file);

  return s;
}

void wrtie_csv(Stack * s, char * filename){

  FILE * file = fopen(filename, "r+");
  //ASSERT ( file != NULL );

  int write_offset = 0;
  int read_offset = 0;
  int i = s->size - 1;

  char c = fgetc(file);

  while ( c != EOF ){

    printf("The char is %c\n", c);
    read_offset = ftell( file );
    fseek(file, write_offset, SEEK_SET);
    if ( i < 0){
      fputc(c, file);
    }else{
      if ( isdigit(c) ){
        char temp = s->data[i];
        printf("The i is %d\n", temp);
        fputc(temp + '0', file);
        i --;
      }
    }
    write_offset = ftell( file );
    fseek(file, read_offset, SEEK_SET);
    c = fgetc(file);
  }
  fclose(file);
}

void print_stack(Stack * s){
  int i;
  for (i = s->size - 1; i >= 0; i --){
    printf("%d", s->data[i]);
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
      printf("%d\n", pop( s ));
      wrtie_csv( s, argv[1] );
      stack_destroy ( s );
    }else if( strcmp("print_top", argv[2]) == 0 ){
      Stack * s = build_stack( argv[1] );
      print_stack ( s );
      printf("%d\n", print_top( s ));
      stack_destroy ( s );
    }else if( strcmp("swap_top", argv[2]) == 0 ){
      Stack * s = build_stack( argv[1] );
      swap_top( s );
      print_stack( s );
      wrtie_csv( s, argv[1] );
      stack_destroy ( s );
    }else{
      print_usage( argv[0] );
    }
  }
}
