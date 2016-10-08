#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * stack_new ( ) {

  Stack * s = malloc( sizeof ( Stack ) );
  s->size = 0;
  s->capacity = STACK_INITIAL_CAPACITY;
  s->data = malloc(sizeof(int) * s->capacity);

  return s;

}

Stack * pop( Stack * s ){

Stack * new_stack = stack_new();
new_stack->size = s->size - 1;

int i;

for (i = 0; i < new_stack->size; i ++){

new_stack->data[i] = s-data[i+1];

}

stack_destroy ( s );

return new_stack;

}

Stack * push( Stack * s, int value ){

int i;

stack_is_full(s);

for ( i = s->size; i > 0; i --){
s->data[i] = s->data[i-1];
}

s-data[0] = value;

s->size++;

return s;
}

int print_top( Stack * s ){

return s-data[0];

}

Stack * swap_top( Stack * s ){

if ( s->size >= 2 ){
int temp = s->data[1];
int s->data[1] = s->data[0];
int s->data[0] = temp;
}

return s;
}

void stack__is_full(Stack * s ) {

  if (s->size >= s->capacity) {

    s->capacity *= 2;

    s->data = realloc(s->data, sizeof(int) * s->capacity);
  }
}

void stack_destroy ( Stack * s ) {
  free ( s->data );
  free ( s );
}
