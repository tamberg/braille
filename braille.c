#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INIT 0
#define READ_A 1
#define READ_C 2
#define READ_E 3
#define READ_S 4
#define READ_SC 5

// https://en.wikipedia.org/wiki/Braille_Patterns

// 1 4 
// 2 5
// 3 6
// 7 8

// 0b00000000
//   87654321

char *svg_doc_start = 
//    "<svg height=\"100%\" width=\"100%\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    "<svg width=\"%.1fmm\" height=\"%.1fmm\" xmlns=\"http://www.w3.org/2000/svg\">\n";

char *svg_pattern =
    "  <g>\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "  </g>\n";

char *svg_doc_end = 
    "</svg>\n";

void print_pattern(unsigned char value, int x, int y) {
    char *dot1 = (value >> 0) & 1 ? "black" : "none";
    char *dot2 = (value >> 1) & 1 ? "black" : "none";
    char *dot3 = (value >> 2) & 1 ? "black" : "none";
    char *dot4 = (value >> 3) & 1 ? "black" : "none";
    char *dot5 = (value >> 4) & 1 ? "black" : "none";
    char *dot6 = (value >> 5) & 1 ? "black" : "none";

    printf(svg_pattern, 
        x + 0.0, y + 0.0, dot1,
        x + 0.0, y + 2.5, dot2,
        x + 0.0, y + 5.0, dot3,
        x + 2.5, y + 0.0, dot4,
        x + 2.5, y + 2.5, dot5,
        x + 2.5, y + 5.0, dot6);
}

struct tuple {
    char *ascii;
    char *braille_s;
    char *braille_l[3];
    unsigned char braille_bits;
};

struct tuple tuples[] = {
    {"a", "⠁", {"● ○", "○ ○", "○ ○"}, 0b00000001},
    {"b", "⠃", {"● ○", "● ○", "○ ○"}, 0b00000011},
    {"c", "⠉", {"● ●", "○ ○", "○ ○"}, 0b00001001},
    {"d", "⠙", {"● ●", "○ ●", "○ ○"}, 0b00011001},
    {"e", "⠑", {"● ○", "○ ●", "○ ○"}, 0b00010001},
    {"f", "⠋", {"● ●", "● ○", "○ ○"}, 0b00001011},
    {"g", "⠛", {"● ●", "● ●", "○ ○"}, 0b00011011},
    {"h", "⠓", {"● ○", "● ●", "○ ○"}, 0b00010011},
    {"i", "⠊", {"○ ●", "● ○", "○ ○"}, 0b00001010},
    {"j", "⠚", {"○ ●", "● ●", "○ ○"}, 0b00011010},
    {"k", "⠅", {"● ○", "○ ○", "● ○"}, 0b00000101},
    {"l", "⠇", {"● ○", "● ○", "● ○"}, 0b00000111},
    {"m", "⠍", {"● ●", "○ ○", "● ○"}, 0b00001101},
    {"n", "⠝", {"● ●", "○ ●", "● ○"}, 0b00011101},
    {"o", "⠕", {"● ○", "○ ●", "● ○"}, 0b00010101},
    {"p", "⠏", {"● ●", "● ○", "● ○"}, 0b00001111},
    {"q", "⠟", {"● ●", "● ●", "● ○"}, 0b00011111},
    {"r", "⠗", {"● ○", "● ●", "● ○"}, 0b00010111},
    {"s", "⠎", {"○ ●", "● ○", "● ○"}, 0b00011110},
    {"t", "⠞", {"○ ●", "● ●", "● ○"}, 0b00011110},
    {"u", "⠥", {"● ○", "○ ○", "● ●"}, 0b00100101},
    {"v", "⠧", {"● ○", "● ○", "● ●"}, 0b00100111},
    {"w", "⠺", {"○ ●", "● ●", "○ ●"}, 0b00111010},
    {"x", "⠭", {"● ●", "○ ○", "● ●"}, 0b00101101},
    {"y", "⠽", {"● ●", "○ ●", "● ●"}, 0b00111101},
    {"z", "⠵", {"● ○", "○ ●", "● ●"}, 0b00110101},
    {" ", " ", {"○ ○", "○ ○", "○ ○"}, 0b00000000},
    {",", "⠂", {"○ ○", "● ○", "○ ○"}, 0b00000010},
    {";", "⠆", {"○ ○", "● ○", "● ○"}, 0b00000110},
    {":", "⠒", {"○ ○", "● ●", "○ ○"}, 0b00010010},
    {"?", "⠢", {"○ ○", "● ○", "○ ●"}, 0b00100010},
    {"!", "⠖", {"○ ○", "● ●", "● ○"}, 0b00010110},
    {"(", "⠶", {"○ ○", "● ●", "● ●"}, 0b00110110},
    {")", "⠶", {"○ ○", "● ●", "● ●"}, 0b00110110},
    {"*", "⠔", {"○ ○", "○ ●", "● ○"}, 0b00010100},
    {"“", "⠦", {"○ ○", "● ○", "● ●"}, 0b00100110}, // quote left
    {"”", "⠴", {"○ ○", "○ ●", "● ●"}, 0b00110100}, // quote right
    {".", "⠄", {"○ ○", "○ ○", "● ○"}, 0b00000100},
    {"-", "⠤", {"○ ○", "○ ○", "● ●"}, 0b00100100},
    {"\'", "⠠", {"○ ○", "○ ○", "○ ●"}, 0b00100000},
    {"au", "⠡", {"● ○", "○ ○", "○ ●"}, 0b00100001},
    {"eu", "⠣", {"● ○", "● ○", "○ ●"}, 0b00100011},
    {"ei", "⠩", {"● ●", "○ ○", "○ ●"}, 0b00101001},
    {"ch", "⠹", {"● ●", "○ ●", "○ ●"}, 0b00111001},
    {"sch", "⠱", {"● ○", "○ ●", "○ ●"}, 0b00110001},
    {"st", "⠾", {"○ ●", "● ●", "● ●"}, 0b00111110}
};

int tuples_len = sizeof(tuples) / sizeof(tuples[0]);

struct tuple *find_tuple(char *ascii) {
    int i = 0;
    while (i < tuples_len && 
        strcmp(tuples[i].ascii, ascii) != 0
    ) {
        i++;
    }
    int found = i < tuples_len;
    assert(found);
    return &tuples[i];
}

struct part {
    struct tuple *tuple;
    struct part *next;
};

struct part *create_part(struct tuple *t) {
    struct part *p = malloc(sizeof(struct part));
    p->tuple = t;
    p->next = NULL;
    return p;
}

struct part *parts = NULL;

void append_part(struct part *new) {
    assert(new != NULL);
    assert(new->next == NULL);
    if (parts == NULL) {
        parts = new;
    } else {
        struct part *p = parts;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new;
    }
}

void append_str(char *text) {
    //printf("append_str, text = %s\n", text);
    struct tuple *t = find_tuple(text);
    assert(t != NULL);
    struct part *p = create_part(t);
    assert(p->tuple == t);
    append_part(p);
}

void append_ch(char ch) { // TODO: vs. Unicode
    if (ch != '\0') {
        char text[2];
        text[0] = ch;
        text[1] = '\0';
        append_str(text);
    }
}

int count_parts() {
    int i = 0;
    struct part *p = parts;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

void iterate_parts(void(*f)(struct part *, int), void(*g)(void)) {
    int i = 0;
    struct part *p = parts;
    while (p != NULL) {
        if (f != NULL) { f(p, i); }
        p = p->next;
        i++;
    }
    if (g != NULL) { g(); }
}

void print_part_ascii(struct part *p, int x) {
    char *s = p->tuple->ascii;
    if (strlen(s) > 1) {
        printf("[%s]", s);
    } else {
        printf("%s", s);
    }
}

void print_part_braille_s(struct part *p, int x) {
    printf("%s", p->tuple->braille_s);
}

void print_part_braille_l0(struct part *p, int x) {
    printf("%s  ", p->tuple->braille_l[0]);
}

void print_part_braille_l1(struct part *p, int x) {
    printf("%s  ", p->tuple->braille_l[1]);
}

void print_part_braille_l2(struct part *p, int x) {
    printf("%s  ", p->tuple->braille_l[2]);
}

void print_part_braille_l3(struct part *p, int x) {
    char *s = p->tuple->ascii;
    int len = strlen(s);
    if (len == 1) {
        printf(" %s ", s);
    } else if (len == 2) {
        printf("%s ", s);
    } else if (len == 3) {
        printf("%s", s);
    }
    printf("  ");
}

void print_part_braille_l(struct part *p, int x) {
    printf("%s\n", p->tuple->braille_l[0]);
    printf("%s\n", p->tuple->braille_l[1]);
    printf("%s\n", p->tuple->braille_l[2]);
    printf("\n");
}

void print_part_braille_bits(struct part *p, int i) {
    print_pattern(p->tuple->braille_bits, 4 + i * 6, 4);
}

void print_newline(void) {
    printf("\n");
}

void print_newlines(void) {
    printf("\n\n");
}

// au, eu, ei, ch, sch, st

void parse_text(char *s) { // TODO: vs. Unicode
    int i = 0;
    int state = INIT;
    while (s[i] != '\0') {
        if (state == INIT) {
            if (s[i] == 'a') {
                state = READ_A;
            } else if (s[i] == 'c') {
                state = READ_C;
            } else if (s[i] == 'e') {
                state = READ_E;
            } else if (s[i] == 's') {
                state = READ_S;
            } else {
                append_ch(s[i]);       
            }
        } else if (state == READ_A) {
            if (s[i] == 'u') {
                append_str("au");
                state = INIT;
            } else if (s[i] == 'a') {
                append_ch('a');
                state = READ_A;
            } else if (s[i] == 'c') {
                append_ch('a');
                state = READ_C;
            } else if (s[i] == 'e') {
                append_ch('a');
                state = READ_E;
            } else if (s[i] == 's') {
                append_ch('a');
                state = READ_S;
            } else {
                append_ch('a');
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_C) {
            if (s[i] == 'h') {
                append_str("ch");
                state = INIT;
            } else if (s[i] == 'a') {
                append_ch('c');
                state = READ_A;
            } else if (s[i] == 'c') {
                append_ch('c');
                state = READ_C;
            } else if (s[i] == 'e') {
                append_ch('c');
                state = READ_E;
            } else if (s[i] == 's') {
                append_ch('c');
                state = READ_S;
            } else {
                append_ch('c');
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_E) {
            if (s[i] == 'i') {
                append_str("ei");
                state = INIT;
            } else if (s[i] == 'u') {
                append_str("eu");
                state = INIT;
            } else if (s[i] == 'a') {
                append_ch('e');
                state = READ_A;
            } else if (s[i] == 'c') {
                append_ch('e');
                state = READ_C;
            } else if (s[i] == 'e') {
                append_ch('e');
                state = READ_E;
            } else if (s[i] == 's') {
                append_ch('e');
                state = READ_S;
            } else {
                append_ch('e');
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_S) {
            if (s[i] == 'c') {
                state = READ_SC;
            } else if (s[i] == 't') {
                append_str("st");
                state = INIT;
            } else if (s[i] == 'a') {
                append_ch('s');
                state = READ_A;
            } else if (s[i] == 'e') {
                append_ch('s');
                state = READ_E;
            } else if (s[i] == 's') {
                append_ch('s');
                state = READ_S;
            } else {
                append_ch('s');
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_SC) {
            if (s[i] == 'h') {
                append_str("sch");
                state = INIT;
            } else if (s[i] == 'a') {
                append_ch('s');
                append_ch('c');
                state = READ_A;
            } else if (s[i] == 's') {
                append_ch('s');
                append_ch('c');
                state = READ_S;
            } else {
                append_ch('s');
                append_ch('c');
                append_ch(s[i]);
                state = INIT;
            }
        }
        i++;
    }
    if (state == READ_A) {
        append_ch('a');
    } else if (state == READ_C) {
        append_ch('c');
    } else if (state == READ_E) {
        append_ch('e');
    } else if (state == READ_S) {
        append_ch('s');
    } else if (state == READ_SC) {
        append_ch('s');
        append_ch('c');
    }
}

void print_braille_text(char *text) {
    parse_text(text);    
    iterate_parts(print_part_ascii, print_newlines);
    iterate_parts(print_part_braille_s, print_newlines);
    iterate_parts(print_part_braille_l0, print_newline);
    iterate_parts(print_part_braille_l1, print_newline);
    iterate_parts(print_part_braille_l2, print_newline);
    iterate_parts(print_part_braille_l3, print_newlines);
    //iterate_parts(print_part_braille_l, NULL);
    parts = NULL;
}

void print_braille_svg(char *text) {
    parse_text(text);
    int n = count_parts() - 1;
    printf(svg_doc_start, 4.0 + (n * 6.0) + 2.5 + 4.0, 4.0 + (0 * 10.0) + 5.0 + 4.0);
    iterate_parts(print_part_braille_bits, NULL);
    printf("%s", svg_doc_end);
    parts = NULL;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *text = argv[1];
        print_braille_text(text);
    } else if (argc == 3) {
        char *opt = argv[1];
        char *text = argv[2];
        assert(strcmp(opt, "-svg") == 0);
        print_braille_svg(text);
    } else {
        printf("usage: %s [-svg] text\n", argv[0]);
    }
    return 0;
}
