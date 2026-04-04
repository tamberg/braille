CC=gcc
CFLAGS=-std=c2x -pedantic -pedantic-errors -Werror -Wall -Wextra

all: braille

braille: braille.c

clean:
	rm -f braille
