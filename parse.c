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

struct part {
    char text[6];
    struct part *next;
};

struct part *create_part(char *text) {
    struct part *p = malloc(sizeof(struct part));
    strcpy(p->text, text);
    p->next = NULL;
    return p;
}

struct part *parts = NULL;

void print_parts() {
    struct part *p = parts;
    while (p->next != NULL) {
        printf("%s", p->text);
        p = p->next;
    }
    printf("\n");
}

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
    struct part *p = create_part(text);
    append_part(p);
}

void append_ch(char ch) {
    char text[2];
    text[0] = ch;
    text[1] = '\0';
    append_str(text);
}

// au, eu, ei, ch, sch, st

void print_parsed(char *s) {
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
                append_str("[au]");
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
                append_str("[ch]");
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
                append_str("[ei]");
                state = INIT;
            } else if (s[i] == 'u') {
                append_str("[eu]");
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
                append_str("[st]");
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
                append_str("[sch]");
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
    print_parts();
    parts = NULL;
}

int main(void) {
    print_parsed("hello\n");
    print_parsed("schulstress\n");
    print_parsed("ausschuss\n");
    print_parsed("spasschronist\n");
    print_parsed("landeschronik\n");
    print_parsed("streuschaufel\n");
    print_parsed("schmauchspur\n");
    return 0;
}
