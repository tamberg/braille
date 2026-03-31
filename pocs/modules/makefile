CC=gcc
CFLAGS=-std=c23 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: braille

braille: tuples.o parts.o parser.o ascii.o svg.o scad.o main.c
	$(CC) -o braille tuples.o parts.o parser.o ascii.o svg.o scad.o main.c $(CFLAGS) $(LDFLAGS)

tuples.o: tuples.h tuples.c
parts.o: parts.h parts.c
parser.o: parser.h parser.c
ascii.o: ascii.h ascii.c
svg.o: svg.h svg.c
scad.o: scad.h scad.c

clean:
	rm -f braille
	rm -f *.o
