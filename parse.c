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
//   12345678

struct tuple {
    char *ascii;
    char *braille_s;
    char *braille_l[3];
};

struct tuple tuples[] = {
    {"a", "⠁", {"● ○", "○ ○", "○ ○"}},
    {"b", "⠃", {"● ○", "● ○", "○ ○"}},
    {"c", "⠉", {"● ●", "○ ○", "○ ○"}},
    {"d", "⠙", {"● ●", "○ ●", "○ ○"}},
    {"e", "⠑", {"● ○", "○ ●", "○ ○"}},
    {"f", "⠋", {"● ●", "● ○", "○ ○"}},
    {"g", "⠛", {"● ●", "● ●", "○ ○"}},
    {"h", "⠓", {"● ○", "● ●", "○ ○"}},
    {"i", "⠊", {"○ ●", "● ○", "○ ○"}},
    {"j", "⠚", {"○ ●", "● ●", "○ ○"}},
    {"k", "⠅", {"● ○", "○ ○", "● ○"}},
    {"l", "⠇", {"● ○", "● ○", "● ○"}},
    {"m", "⠍", {"● ●", "○ ○", "● ○"}},
    {"n", "⠝", {"● ●", "○ ●", "● ○"}},
    {"o", "⠕", {"● ○", "○ ●", "● ○"}},
    {"p", "⠏", {"● ●", "● ○", "● ○"}},
    {"q", "⠟", {"● ●", "● ●", "● ○"}},
    {"r", "⠗", {"● ○", "● ●", "● ○"}},
    {"s", "⠎", {"○ ●", "● ○", "● ○"}},
    {"t", "⠞", {"○ ●", "● ●", "● ○"}},
    {"u", "⠥", {"● ○", "○ ○", "● ●"}},
    {"v", "⠧", {"● ○", "● ○", "● ●"}},
    {"w", "⠺", {"○ ●", "● ●", "○ ●"}},
    {"x", "⠭", {"● ●", "○ ○", "● ●"}},
    {"y", "⠽", {"● ●", "○ ●", "● ●"}},
    {"z", "⠵", {"● ○", "○ ●", "● ●"}},
    {" ", " ", {"○ ○", "○ ○", "○ ○"}},
    {",", "⠂", {"○ ○", "● ○", "○ ○"}},
    {";", "⠆", {"○ ○", "● ○", "● ○"}},
    {":", "⠒", {"○ ○", "● ●", "○ ○"}},
    {"?", "⠢", {"○ ○", "● ○", "○ ●"}},
    {"!", "⠖", {"○ ○", "● ●", "● ○"}},
    {"(", "⠶", {"○ ○", "● ●", "● ●"}},
    {")", "⠶", {"○ ○", "● ●", "● ●"}},
    {"*", "⠔", {"○ ○", "○ ●", "● ○"}},
    {"“", "⠦", {"○ ○", "● ○", "● ●"}}, // quote left
    {"”", "⠴", {"○ ○", "○ ●", "● ●"}}, // quote right
    {".", "⠄", {"○ ○", "○ ○", "● ○"}},
    {"-", "⠤", {"○ ○", "○ ○", "● ●"}},
    {"\'", "⠠", {"○ ○", "○ ○", "○ ●"}}, // single quote
    {"au", "⠡", {"● ○", "○ ○", "○ ●"}},
    {"eu", "⠣", {"● ○", "● ○", "○ ●"}},
    {"ei", "⠩", {"● ●", "○ ○", "○ ●"}},
    {"ch", "⠹", {"● ●", "○ ●", "○ ●"}},
    {"sch", "⠱", {"● ○", "○ ●", "○ ●"}},
    {"st", "⠾", {"○ ●", "● ●", "● ●"}},
    {"\n", "\n", {"", "", "\n"}} // TODO
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
    struct tuple *t = find_tuple(text);
    assert(t != NULL);
    struct part *p = create_part(t);
    assert(p->tuple == t);
    append_part(p);
}

void append_ch(char ch) { // TODO: vs. Unicode
    char text[2];
    text[0] = ch;
    text[1] = '\0';
    append_str(text);
}

void iterate_parts(void(*f)(struct part *p), void(*g)(void)) {
    struct part *p = parts;
    while (p != NULL) {
        if (f != NULL) { f(p); }
        p = p->next;
    }
    if (g != NULL) { g(); }
}

void print_part_ascii(struct part *p) {
    char *s = p->tuple->ascii;
    if (strlen(s) > 1) {
        printf("[%s]", s);
    } else {
        printf("%s", s);
    }
}

void print_part_braille_s(struct part *p) {
    printf("%s", p->tuple->braille_s);
}

void print_part_braille_l0(struct part *p) {
    printf("%s  ", p->tuple->braille_l[0]);
}

void print_part_braille_l1(struct part *p) {
    printf("%s  ", p->tuple->braille_l[1]);
}

void print_part_braille_l2(struct part *p) {
    printf("%s  ", p->tuple->braille_l[2]);
}

void print_part_braille_l3(struct part *p) {
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

void print_part_braille_l(struct part *p) {
    printf("%s\n", p->tuple->braille_l[0]);
    printf("%s\n", p->tuple->braille_l[1]);
    printf("%s\n", p->tuple->braille_l[2]);
    printf("\n");
}

void print_newline(void) {
    printf("\n");
}

void print_newlines(void) {
    printf("\n\n");
}

// au, eu, ei, ch, sch, st

void print_parsed(char *s) { // TODO: vs. Unicode
    int i = 0;
    int state = 0;
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
    iterate_parts(print_part_ascii, print_newlines);
    iterate_parts(print_part_braille_s, print_newlines);
    iterate_parts(print_part_braille_l0, print_newline);
    iterate_parts(print_part_braille_l1, print_newline);
    iterate_parts(print_part_braille_l2, print_newline);
    iterate_parts(print_part_braille_l3, print_newlines);
    //iterate_parts(print_part_braille_l, NULL);
    parts = NULL;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        print_parsed(argv[1]);
    } else if (argc == 1) {
        print_parsed("hoi goran");
        print_parsed("schulstress");
        print_parsed("ausschuss");
        print_parsed("spasschronist");
        print_parsed("landeschronik");
        print_parsed("streuschaufel");
        print_parsed("schmauchspur");
        //print_parsed("zitat “nice”");
    } else {
        printf("usage: %s text\n", argv[0]);
    }
    return 0;
}
