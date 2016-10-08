#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * stack_new ( ) {

  Stack * s = malloc( sizeof ( Stack ));
  s->size = 0;
  s->capacity = STACK_INITIAL_CAPACITY;
  s->data = malloc(sizeof(int) * vector->capacity);

  return s;

}

void stack_destroy ( Stack * s ) {
  free ( s->data );
  free ( s );
}
