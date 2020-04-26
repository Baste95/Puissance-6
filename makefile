CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99
LDFLAGS=
EXEC=puissance6V2

all: $(EXEC)

puissance6V2: main.o insertion.o plateau.o verification.o test.o 
	$(CC) -o puissance6V2  main.o insertion.o plateau.o verification.o test.o $(LDFLAGS)

insertion.o: insertion.c plateau.h
	$(CC) -o insertion.o -c insertion.c $(CFLAGS)

plateau.o: plateau.c plateau.h
	$(CC) -o plateau.o -c plateau.c $(CFLAGS)

verification.o: verification.c plateau.h
	$(CC) -o verification.o -c verification.c $(CFLAGS)

test.o: test.c plateau.h
	$(CC) -o test.o -c test.c $(CFLAGS)

main.o: main.c plateau.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean plateau.h
	rm -rf $(EXEC)
