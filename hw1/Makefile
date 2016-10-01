detab: detab.c
	gcc -o detab detab.c

fsm: main.c fsm.c fsm.h
		gcc -c main.c fsm.c
		gcc -o fsm main.o fsm.o
clean:
		rm -f detab fsm *.o
