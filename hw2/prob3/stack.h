#ifndef _STACK_H
#define _STACK_H

#define STACK_INITIAL_CAPACITY 100
#define STRING_SIZE 100

typedef struct {
  char ** data;
  int size;
  int capacity;

} Stack;

Stack * stack_create ();

void stack_destroy ( Stack * s );

char * pop( Stack * s );

void push( Stack * s, char * data );

char * print_top( Stack * s );

void swap_top( Stack * s );

void stack_is_full ( Stack * s );

/* utilities */
#define ASSERT(_cond_) {                                                          \
  if ( ! ( _cond_ ) ) {                                                           \
    fprintf (stderr, "Internal error: assertion '%s' failed at %s, line %d\n",    \
                   #_cond_ , __FILE__, __LINE__);                                 \
    exit ( -1 );                                                                  \
  }                                                                               \
}

#define NL printf ( "\n" );

#endif
