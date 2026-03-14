#include <stdio.h>

#define INIT 0
#define READ_S 1
#define READ_A 2
#define READ_SC 3

void print_parsed(char *s) {
    int i = 0;
    int state = 0;
    while (s[i] != '\0') {
        if (state == INIT) {
            if (s[i] == 'a') {
                state = READ_A;
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
            } else if (s[i] == 's') {
                printf("a");
                state = READ_S;
            } else {
                printf("a%c", s[i]);
                state = INIT;
            }
        } else if (state == READ_S) {
            if (s[i] == 'c') {
                state = READ_SC;
            } else if (s[i] == 's') {
                printf("[ss]");
                state = INIT;
            } else if (s[i] == 'a') {
                printf("s");
                state = READ_A;
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
    return 0;
}
