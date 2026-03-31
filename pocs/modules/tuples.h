#ifndef TUPLES_H
#define TUPLES_H

struct tuple {
    char *ascii; // TODO: rename
    char *braille_s;
    unsigned char braille_bits;
};

// see https://en.wikipedia.org/wiki/Braille_ASCII & Braille_Patterns
// and https://www.sbs.ch/fileadmin/braille200/Braille-Alphabet.pdf

// dot layout

// 1 4 
// 2 5
// 3 6
// 7 8

extern struct tuple tuples[];

extern int tuples_len;

struct tuple *find_tuple(char *ascii);

#endif
