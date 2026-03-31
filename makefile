CC=gcc
CFLAGS=-std=c23 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: braille

braille: braille.c

clean:
	rm -f braille
