#include <stdio.h>
#include <assert.h>

#define INIT 0
#define READ_A 1
#define READ_C 2
#define READ_E 3
#define READ_S 4
#define READ_SC 5
#define READ_0xC3 6

// au, eu, ei, ch, sch, st

void print_parsed(char *s) {
    int i = 0;
    int done = 0;
    int state = 0;
    while (!done) {
        if (state == INIT) {
            if (s[i] == 'a') {
                state = READ_A;
            } else if (s[i] == 'c') {
                state = READ_C;
            } else if (s[i] == 'e') {
                state = READ_E;
            } else if (s[i] == 's') {
                state = READ_S;
            } else if (((unsigned char) s[i]) == 0xc3) { // ä, ö, ü, ...
                state = READ_0xC3;
            } else {
                printf("%c", s[i]);
            }
        } else if (state == READ_A) {
            if (s[i] == 'u') {
                printf("[au]");
                state = INIT;
            } else if (s[i] == 'a') {
                printf("a");
                state = READ_A;
            } else if (s[i] == 'c') {
                printf("a");
                state = READ_C;
            } else if (s[i] == 'e') {
                printf("a");
                state = READ_E;
            } else if (s[i] == 's') {
                printf("a");
                state = READ_S;
            } else {
                printf("a%c", s[i]);
                state = INIT;
            }
        } else if (state == READ_C) {
            if (s[i] == 'h') {
                printf("[ch]");
                state = INIT;
            } else if (s[i] == 'a') {
                printf("c");
                state = READ_A;
            } else if (s[i] == 'c') {
                printf("c");
                state = READ_C;
            } else if (s[i] == 'e') {
                printf("c");
                state = READ_E;
            } else if (s[i] == 's') {
                printf("c");
                state = READ_S;
            } else {
                printf("c%c", s[i]);
                state = INIT;
            }
        } else if (state == READ_E) {
            if (s[i] == 'i') {
                printf("[ei]");
                state = INIT;
            } else if (s[i] == 'u') {
                printf("[eu]");
                state = INIT;
            } else if (s[i] == 'a') {
                printf("e");
                state = READ_A;
            } else if (s[i] == 'c') {
                printf("e");
                state = READ_C;
            } else if (s[i] == 'e') {
                printf("e");
                state = READ_E;
            } else if (s[i] == 's') {
                printf("e");
                state = READ_S;
            } else {
                printf("e%c", s[i]);
                state = INIT;
            }
        } else if (state == READ_S) {
            if (s[i] == 'c') {
                state = READ_SC;
            } else if (s[i] == 't') {
                printf("[st]");
                state = INIT;
            } else if (s[i] == 'a') {
                printf("s");
                state = READ_A;
            } else if (s[i] == 'e') {
                printf("s");
                state = READ_E;
            } else if (s[i] == 's') {
                printf("s");
                state = READ_S;
            } else {
                printf("s%c", s[i]);
                state = INIT;
            }
        } else if (state == READ_SC) {
            if (s[i] == 'h') {
                printf("[sch]");
                state = INIT;
            } else if (s[i] == 'a') {
                printf("sc");
                state = READ_A;
            } else if (s[i] == 's') {
                printf("sc");
                state = READ_S;
            } else {
                printf("sc%c", s[i]);
                state = INIT;
            }
        } else if (state == READ_0xC3) {
            if (((unsigned char) s[i]) == 0xa4) { // ä
                printf("ä");
                state = INIT;
            } else if (((unsigned char) s[i]) == 0xb6) { // ö
                printf("ö");
                state = INIT;
            } else if (((unsigned char) s[i]) == 0xbc) { // ü
                printf("ü");
                state = INIT;
            } else {
                printf("%#02x\n", 0x000000ff & s[i]);
                assert(0); // not yet impl
            }
        }
        done = s[i] == '\0';
        i++;
    }
}

int main(void) {
    print_parsed("abc"); printf("\n");
    print_parsed("hello\n");
    print_parsed("schulstress\n");
    print_parsed("ausschuss\n");
    print_parsed("spasschronist\n");
    print_parsed("landeschronik\n");
    print_parsed("streuschaufel\n");
    print_parsed("schmauchspur\n");
    print_parsed("äüö\n");
    return 0;
}
