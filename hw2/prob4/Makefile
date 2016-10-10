all: day

day: main.c day.c day.h
		gcc -c main.c day.c
		gcc -o day main.o day.o

clean:
		rm -f day *.o
