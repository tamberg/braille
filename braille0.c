// https://tamberg.mit-license.org

#include <stdio.h>

void print_braille(char ch) {
    char *s;
    if (ch == ' ') {
        s = " ";
    } else if (ch == 'a') {
        s = "⠁";
    } else if (ch == 'b') {
        s = "⠃";
    } else if (ch == 'c') {
        s = "⠉";
    } else if (ch == 'd') {
        s = "⠙";
    } else if (ch == 'e') {
        s = "⠑";
    } else if (ch == 'f') {
        s = "⠋";
    } else if (ch == 'g') {
        s = "⠛";
    } else if (ch == 'h') {
        s = "⠓";
    } else if (ch == 'i') {
        s = "⠊";
    } else if (ch == 'j') {
        s = "⠚";
    } else if (ch == 'k') {
        s = "⠅";
    } else if (ch == 'l') {
        s = "⠇";
    } else if (ch == 'm') {
        s = "⠍";
    } else if (ch == 'n') {
        s = "⠝";
    } else if (ch == 'o') {
        s = "⠕";
    } else if (ch == 'p') {
        s = "⠏";
    } else if (ch == 'q') {
        s = "⠟";
    } else if (ch == 'r') {
        s = "⠗";
    } else if (ch == 's') {
        s = "⠎";
    } else if (ch == 't') {
        s = "⠞";
    } else if (ch == 'u') {
        s = "⠥";
    } else if (ch == 'v') {
        s = "⠧";
    } else if (ch == 'w') {
        s = "⠺";
    } else if (ch == 'x') {
        s = "⠭";
    } else if (ch == 'y') {
        s = "⠽";
    } else if (ch == 'z') {
        s = "⠵";
    } else {
        s = "?";
    }
    printf("%s", s);
}

int main(void) {
    char *text = "hoi goran";
    int i = 0;
    char ch = text[i];
    while (ch != '\0') {
        print_braille(ch);
        i = i + 1;
        ch = text[i];
    }
    return 0;
}
