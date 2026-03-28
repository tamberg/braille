// https://tamberg.mit-license.org

#include <stdio.h>
#include <assert.h>

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

void append_ch(char ch) {
    if (ch != '\0') {
        printf("%c", ch);
    }
}

void append_str(char *s) {
    printf("[%s]", s);
}

// groups äu, au, ch, eu, ei, sch, st
void parse_text(char *s) {
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

void print_parsed(char *text) {
    parse_text(text);
    printf("\n");
}

int main(void) {
    print_parsed("abc");
    print_parsed("hello");
    print_parsed("schulstress");
    print_parsed("ausschuss");
    print_parsed("spasschronist");
    print_parsed("spaßchronist");
    print_parsed("landeschronik");
    print_parsed("streuschaufel");
    print_parsed("schmauchspur");
    print_parsed("äußerst");
    print_parsed("1 2 3");
    print_parsed("1825");
    return 0;
}
