
CC=gcc
CFLAGS=-I.
DEPS = counter.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: counter.o main.o 
	$(CC) -o exec main.o counter.o
