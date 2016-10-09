all: stack

stack: main.c stack.c stack.h
		gcc -c main.c stack.c
		gcc -o stack main.o stack.o

clean:
		rm -f stack *.o
