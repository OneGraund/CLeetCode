.PHONY: all compile docs clean cleeean

all: compile
	./main

compile: main_comp.o
	gcc -o main main_comp.o

debug: main_debug.o
	gcc -g -fsanitize=address -o main main_debug.o
	gdb main

main_comp.o: main.c 
	gcc -std=c99 -pedantic -Wall -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_POSIX_C_SOURCE=200809L \
		 -c main.c -o main_comp.o

main_debug.o: main.c 
	gcc -DDEBUG -g -Wall -fsanitize=address -c main.c -o main_debug.o

clean:
	rm -rf *.o main


