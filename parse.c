#include <stdio.h>

#define INIT 0
#define READ_A 1
#define READ_C 2
#define READ_E 3
#define READ_S 4
#define READ_SC 5

// au, eu, ei, ch, sch, st (ohne ss)

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
        }
        i++;
    }
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
