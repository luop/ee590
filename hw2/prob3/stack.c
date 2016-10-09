#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * stack_create () {

  Stack * s = malloc( sizeof ( Stack ) );
  s->size = 0;
  s->capacity = STACK_INITIAL_CAPACITY;
  s->data = malloc(sizeof(int) * s->capacity);

  return s;

}

int pop( Stack * s ){

  ASSERT ( s->size > 0 );
  s->size--;
  return s->data[s->size];

}

void push( Stack * s, int value ){

  stack_is_full(s);

  s->data[s->size] = value;

  s->size++;

}

int print_top( Stack * s ){

  return s->data[s->size - 1];

}

void swap_top( Stack * s ){

  if ( s->size >= 2 ){
    int size = s->size;
    int temp = s->data[size - 1];
    s->data[size - 1] = s->data[size - 2];
    s->data[size - 2] = temp;
  }

}

void stack_is_full(Stack * s ) {

  if (s->size >= s->capacity) {

    s->capacity *= 2;

    s->data = realloc(s->data, sizeof(int) * s->capacity);
  }
}

void stack_destroy ( Stack * s ) {
  free ( s->data );
  free ( s );
}
