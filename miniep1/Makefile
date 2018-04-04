CC=gcc
CFLAGS=-ansi -pedantic -Wall -O2

all: hello

hello: ep.o
	$(CC) $(CFLAGS) ep.o -o ep
	./ep

ep.o: ep.c
	$(CC) -c ep.c

clean:
	rm *.o