#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parts.h"

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
