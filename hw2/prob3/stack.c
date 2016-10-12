#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * stack_create () {

  Stack * s = malloc( sizeof ( Stack ) );
  s->size = 0;
  s->capacity = STACK_INITIAL_CAPACITY;
  s->data = (char**)malloc(sizeof(char*) * s->capacity);

  return s;

}

char * pop( Stack * s ){

  ASSERT ( s->size > 0 );

  char * topop = s->data[0];
  int i;
  for (i = 0; i < s->size - 1; i ++){
    s->data[i] = s->data[i + 1];
  }
  s->size--;
  return topop;

}

void push( Stack * s, char * value ){

  stack_is_full(s);

  s->data[s->size] = (char*)malloc(STRING_SIZE * sizeof(char));
  sprintf(s->data[s->size], value);

  s->size++;

}

char * print_top( Stack * s ){

  ASSERT ( s->size > 0 );
  return s->data[0];

}

void swap_top( Stack * s ){

  if ( s->size >= 2 ){

    char * temp = s->data[1];
    s->data[1] = s->data[0];
    s->data[0] = temp;
  }

}

void stack_is_full(Stack * s ) {

  if (s->size >= s->capacity) {

    s->capacity *= 2;

    s->data = realloc(s->data, sizeof(char*) * s->capacity);
  }
}

void stack_destroy ( Stack * s ) {
  free ( s->data );
  free ( s );
}
