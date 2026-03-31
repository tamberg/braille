#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parts.h"
#include "ascii.h"

void print_part_ascii(struct part *p, int x) {
    (void) x; // unused
    char *s = p->tuple->ascii;
    if (strlen(s) > 1) {
        printf("[%s]", s);
    } else {
        printf("%s", s);
    }
}

void print_part_braille_s(struct part *p, int x) {
    (void) x; // unused
    printf("%s", p->tuple->braille_s);
}

void print_part_braille_l0(struct part *p, int x) {
    (void) x; // unused
    int b = p->tuple->braille_bits;
    printf("%s ", b & 0b00000001 ? "●" : "○");
    printf("%s ", b & 0b00001000 ? "●" : "○");
    printf(" ");
}

void print_part_braille_l1(struct part *p, int x) {
    (void) x; // unused
    int b = p->tuple->braille_bits;
    printf("%s ", b & 0b00000010 ? "●" : "○");
    printf("%s ", b & 0b00010000 ? "●" : "○");
    printf(" ");
}

void print_part_braille_l2(struct part *p, int x) {
    (void) x; // unused
    int b = p->tuple->braille_bits;
    printf("%s ", b & 0b00000100 ? "●" : "○");
    printf("%s ", b & 0b00100000 ? "●" : "○");
    printf(" ");
}

void print_part_braille_l3(struct part *p, int x) {
    (void) x; // unused
    char *s = p->tuple->ascii;
    int len;
    if ((unsigned char) s[0] == 0xc3) {
        if (s[2] == '\0') { // e.g. "ä"
            len = 1;
        } else { // e.g. "äu"
            len = 2;
        }
    } else {
        len = strlen(s);
    }
    if (len == 1) {
        printf(" %s ", s);
    } else if (len == 2) {
        printf("%s ", s);
    } else if (len == 3) {
        printf("%s", s);
    }
    printf("  ");
}

void print_newline(void) {
    printf("\n");
}

void print_newlines(void) {
    printf("\n\n");
}

void print_braille_text() {
    iterate_parts(print_part_ascii, print_newlines);
    iterate_parts(print_part_braille_s, print_newlines);
    iterate_parts(print_part_braille_l0, print_newline);
    iterate_parts(print_part_braille_l1, print_newline);
    iterate_parts(print_part_braille_l2, print_newline);
    iterate_parts(print_part_braille_l3, print_newlines);
}
