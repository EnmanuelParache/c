CC=gcc

%.o: %.c
	${CC} $< -o $@

run: main.o
	./main.o

clean: main.o
	rm *.o