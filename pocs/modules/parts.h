#ifndef PARTS_H
#define PARTS_H

#include "tuples.h"

struct part {
    struct tuple *tuple;
    struct part *next;
};

struct part *create_part(struct tuple *t);
extern struct part *parts;

void append_part(struct part *new);

void append_str(char *text);

void append_ch(char ch);

int count_parts();

void iterate_parts(void(*f)(struct part *, int), void(*g)(void));

#endif
