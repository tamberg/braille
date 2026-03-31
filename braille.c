#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// parser states

#define INIT 0
#define READ_A 1
#define READ_C 2
#define READ_E 3
#define READ_I 4
#define READ_S 5
#define READ_SC 6
#define READ_0xC3 7
#define READ_0xC3A4 8
#define READ_DIGIT 9

// SVG templates

char *svg_start = 
    "<svg width=\"%.1fmm\" height=\"%.1fmm\" xmlns=\"http://www.w3.org/2000/svg\">\n";

char *svg_group =
    "  <g>\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "  </g>\n";

char *svg_end = 
    "</svg>\n";

void print_svg_group(unsigned char value, int x, int y) {
    char *dot1 = (value >> 0) & 1 ? "black" : "none";
    char *dot2 = (value >> 1) & 1 ? "black" : "none";
    char *dot3 = (value >> 2) & 1 ? "black" : "none";
    char *dot4 = (value >> 3) & 1 ? "black" : "none";
    char *dot5 = (value >> 4) & 1 ? "black" : "none";
    char *dot6 = (value >> 5) & 1 ? "black" : "none";

    printf(svg_group, 
        x + 0.0, y + 0.0, dot1,
        x + 0.0, y + 2.5, dot2,
        x + 0.0, y + 5.0, dot3,
        x + 2.5, y + 0.0, dot4,
        x + 2.5, y + 2.5, dot5,
        x + 2.5, y + 5.0, dot6);
}

// SCAD templates

char *scad_module =
    "$fn = 36;\n"
    "h_base = 2;\n"
    "h_dot = 0.6;\n"
    "r_dot = 0.8;\n"
    "\n"
    "module pattern(d1, d2, d3, d4, d5, d6) {\n"
    "    if (d1) { translate([0.0, 5.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d2) { translate([0.0, 2.5, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d3) { translate([0.0, 0.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d4) { translate([2.5, 5.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d5) { translate([2.5, 2.5, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d6) { translate([2.5, 0.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "}\n"
    "\n"
    "cube([%1.f, %1.f, h_base]);\n";

char *scad_object =
    "translate([%1.f, %1.f, h_base]) pattern(%d, %d, %d, %d, %d, %d);\n";

void print_scad_object(unsigned char value, int x, int y) {
    int dot1 = (value >> 0) & 1;
    int dot2 = (value >> 1) & 1;
    int dot3 = (value >> 2) & 1;
    int dot4 = (value >> 3) & 1;
    int dot5 = (value >> 4) & 1;
    int dot6 = (value >> 5) & 1;

    printf(scad_object, x + 0.0, y + 0.0, dot1, dot2, dot3, dot4, dot5, dot6);
}

// lookup table of braille tuples

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

struct tuple tuples[] = {
    // dot no.   87654321
    {"a", "⠁", 0b00000001},
    {"b", "⠃", 0b00000011},
    {"c", "⠉", 0b00001001},
    {"d", "⠙", 0b00011001},
    {"e", "⠑", 0b00010001},
    {"f", "⠋", 0b00001011},
    {"g", "⠛", 0b00011011},
    {"h", "⠓", 0b00010011},
    {"i", "⠊", 0b00001010},
    {"j", "⠚", 0b00011010},
    {"k", "⠅", 0b00000101},
    {"l", "⠇", 0b00000111},
    {"m", "⠍", 0b00001101},
    {"n", "⠝", 0b00011101},
    {"o", "⠕", 0b00010101},
    {"p", "⠏", 0b00001111},
    {"q", "⠟", 0b00011111},
    {"r", "⠗", 0b00010111},
    {"s", "⠎", 0b00011110},
    {"t", "⠞", 0b00011110},
    {"u", "⠥", 0b00100101},
    {"v", "⠧", 0b00100111},
    {"w", "⠺", 0b00111010},
    {"x", "⠭", 0b00101101},
    {"y", "⠽", 0b00111101},
    {"z", "⠵", 0b00110101},
    {" ", " ", 0b00000000},
    {",", "⠂", 0b00000010},
    {";", "⠆", 0b00000110},
    {":", "⠒", 0b00010010},
    {"?", "⠢", 0b00100010},
    {"!", "⠖", 0b00010110},
    {"(", "⠶", 0b00110110},
    {")", "⠶", 0b00110110},
    {"*", "⠔", 0b00010100},
    {"“", "⠦", 0b00100110}, // quote left
    {"”", "⠴", 0b00110100}, // quote right
    {".", "⠄", 0b00000100},
    {"-", "⠤", 0b00100100},
    {"\'", "⠠", 0b00100000},
    {"au", "⠡", 0b00100001},
    {"eu", "⠣", 0b00100011},
    {"ei", "⠩", 0b00101001},
    {"ie", "⠍", 0b00101100},
    {"ch", "⠹", 0b00111001},
    {"sch", "⠱", 0b00110001},
    {"st", "⠾", 0b00111110},
    {"ä", "⠜", 0b00011100},
    {"ö", "⠪", 0b00101010},
    {"ü", "⠳", 0b00110011},
    {"äu", "⠌", 0b00001100},
    {"ß", "⠮", 0b00101110},
    {"#", "⠼", 0b00111100},
    {"1", "⠁", 0b00000001},
    {"2", "⠃", 0b00000011},
    {"3", "⠉", 0b00001001},
    {"4", "⠙", 0b00011001},
    {"5", "⠑", 0b00010001},
    {"6", "⠋", 0b00001011},
    {"7", "⠛", 0b00011011},
    {"8", "⠓", 0b00010011},
    {"9", "⠊", 0b00001010},
    {"0", "⠚", 0b00011010}
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

// linked list of parsed parts

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

void append_ch(char ch) {
    if (ch != '\0') {
        char text[2];
        text[0] = ch;
        text[1] = '\0';
        append_str(text);
    }
}

// parser converting text to parts

// handle multi-byte chars ä, ö, ü, ß and
// group äu, au, ch, ei, eu, ie, sch, st
void parse_text(char *s) {
    parts = NULL;
    int i = 0;
    int done = 0;
    int state = INIT;
    while (!done) {
        if (state == INIT) {
            if (s[i] == 'a') {
                state = READ_A;
            } else if (s[i] == 'c') {
                state = READ_C;
            } else if (s[i] == 'e') {
                state = READ_E;
            } else if (s[i] == 'i') {
                state = READ_I;
            } else if (s[i] == 's') {
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) { // ä, ö, ü
                state = READ_0xC3;
            } else if ('0' <= s[i] && s[i] <= '9') { // 0 - 9
                append_ch('#');
                state = READ_DIGIT;
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
            } else if (s[i] == 'i') {
                append_ch('a');
                state = READ_I;
            } else if (s[i] == 's') {
                append_ch('a');
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_ch('a');
                state = READ_0xC3;
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
            } else if (s[i] == 'i') {
                append_ch('c');
                state = READ_I;
            } else if (s[i] == 's') {
                append_ch('c');
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_ch('c');
                state = READ_0xC3;
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
            } else if (s[i] == 'i') {
                append_ch('e');
                state = READ_I;
            } else if (s[i] == 's') {
                append_ch('e');
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_ch('e');
                state = READ_0xC3;
            } else {
                append_ch('e');
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_I) {
            if (s[i] == 'e') {
                append_str("ie");
                state = INIT;
            } else if (s[i] == 'a') {
                append_ch('i');
                state = READ_A;
            } else if (s[i] == 'c') {
                append_ch('i');
                state = READ_C;
            } else if (s[i] == 'i') {
                append_ch('i');
                state = READ_I;
            } else if (s[i] == 's') {
                append_ch('i');
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_ch('i');
                state = READ_0xC3;
            } else {
                append_ch('i');
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
            } else if (s[i] == 'i') {
                append_ch('s');
                state = READ_I;
            } else if (s[i] == 's') {
                append_ch('s');
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_ch('s');
                state = READ_0xC3;
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
            } else if (s[i] == 'e') {
                append_ch('s');
                append_ch('c');
                state = READ_E;
            } else if (s[i] == 'i') {
                append_ch('s');
                append_ch('c');
                state = READ_I;
            } else if (s[i] == 's') {
                append_ch('s');
                append_ch('c');
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_ch('s');
                append_ch('c');
                state = READ_0xC3;
            } else {
                append_ch('s');
                append_ch('c');
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_0xC3) {
            if (((unsigned char) s[i]) == 0xa4) { // ä
                state = READ_0xC3A4;
            } else if (((unsigned char) s[i]) == 0xb6) { // ö
                append_str("ö");
                state = INIT;
            } else if (((unsigned char) s[i]) == 0xbc) { // ü
                append_str("ü");
                state = INIT;
            } else if (((unsigned char) s[i]) == 0x9f) { // ß
                append_str("ß");
                state = INIT;
            } else {
                printf("%#02x\n", 0x000000ff & s[i]);
                assert(0); // not yet impl
            }
        } else if (state == READ_0xC3A4) { // ä
            if (s[i] == 'u') {
                append_str("äu");
                state = INIT;
            } else if (s[i] == 'a') {
                append_str("ä");
                state = READ_A;
            } else if (s[i] == 'c') {
                append_str("ä");
                state = READ_C;
            } else if (s[i] == 'e') {
                append_str("ä");
                state = READ_E;
            } else if (s[i] == 's') {
                append_str("ä");
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) {
                append_str("ä");
                state = READ_0xC3;
            } else {
                append_str("ä");
                append_ch(s[i]);
                state = INIT;
            }
        } else if (state == READ_DIGIT) {
            assert(i > 0);
            if ('0' <= s[i] && s[i] <= '9') { // 0 - 9
                append_ch(s[i - 1]);
                state = READ_DIGIT;
            } else if (s[i] == 'a') {
                append_ch(s[i - 1]);
                state = READ_A;
            } else if (s[i] == 'e') {
                append_ch(s[i - 1]);
                state = READ_E;
            } else if (s[i] == 's') {
                append_ch(s[i - 1]);
                state = READ_S;
            } else {
                append_ch(s[i - 1]);
                append_ch(s[i]);
                state = INIT;
            }
        }
        done = s[i] == '\0';
        i++;
    }
}

// part iterator functions

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
    (void)(x); // unused
    char *s = p->tuple->ascii;
    if (strlen(s) > 1) {
        printf("[%s]", s);
    } else {
        printf("%s", s);
    }
}

void print_part_braille_s(struct part *p, int x) {
    (void)(x); // unused
    printf("%s", p->tuple->braille_s);
}

void print_part_braille_l0(struct part *p, int x) {
    (void)(x); // unused
    //printf("%s  ", p->tuple->braille_l[0]);
    int b = p->tuple->braille_bits;
    printf("%s ", b & 0b00000001 ? "●" : "○");
    printf("%s ", b & 0b00001000 ? "●" : "○");
    printf(" ");
}

void print_part_braille_l1(struct part *p, int x) {
    (void)(x); // unused
    //printf("%s  ", p->tuple->braille_l[1]);
    int b = p->tuple->braille_bits;
    printf("%s ", b & 0b00000010 ? "●" : "○");
    printf("%s ", b & 0b00010000 ? "●" : "○");
    printf(" ");
}

void print_part_braille_l2(struct part *p, int x) {
    (void)(x); // unused
    //printf("%s  ", p->tuple->braille_l[2]);
    int b = p->tuple->braille_bits;
    printf("%s ", b & 0b00000100 ? "●" : "○");
    printf("%s ", b & 0b00100000 ? "●" : "○");
    printf(" ");
}

void print_part_braille_l3(struct part *p, int x) {
    (void)(x); // unused
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

void print_part_braille_svg_group(struct part *p, int i) {
    print_svg_group(p->tuple->braille_bits, 4 + i * 6, 4);
}

void print_part_braille_scad_object(struct part *p, int i) {
    print_scad_object(p->tuple->braille_bits, 4 + i * 6, 4);
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

void print_braille_svg() {
    int n = count_parts() - 1;
    printf(svg_start, 4.0 + (n * 6.0) + 2.5 + 4.0, 4.0 + (0 * 10.0) + 5.0 + 4.0);
    iterate_parts(print_part_braille_svg_group, NULL);
    printf("%s", svg_end);
}

void print_braille_scad() {
    int n = count_parts() - 1;
    printf(scad_module, 4.0 + (n * 6.0) + 2.5 + 4.0, 4.0 + (0 * 10.0) + 5.0 + 4.0);
    iterate_parts(print_part_braille_scad_object, NULL);
}

// main() function with options

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *text = argv[1];
        parse_text(text);    
        print_braille_text();
    } else if (argc == 3) {
        char *opt = argv[1];
        char *text = argv[2];
        parse_text(text);
        if (strcmp(opt, "-svg") == 0) {
            print_braille_svg();
        } else if (strcmp(opt, "-scad") == 0) {
            print_braille_scad();
        }
    } else {
        printf("usage: %s [-svg|-scad] text\n", argv[0]);
    }
    return 0;
}
