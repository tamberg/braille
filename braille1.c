#include <stdio.h>

char *braille[] = {
    "⠁", "⠃", "⠉", "⠙", "⠑", "⠋", "⠛", "⠓", "⠊", "⠚", 
    "⠅", "⠇", "⠍", "⠝", "⠕", "⠏", "⠟", "⠗", "⠎", "⠞",
    "⠥", "⠧", "⠺", "⠭", "⠽", "⠵" 
};

void print_braille(char ch) {
    char *s;
    if ('a' <= ch && ch <= 'z') {
        int i = (ch - 'a');
        s = braille[i];
    } else if (ch == ' ') {
        s = " ";
    } else {
        s = "?";
    }
    printf("%s", s);
}

int main(int argc, char *argv[]) {
    char *text = argv[1];
    int i = 0;
    char ch = text[i];
    while (ch != '\0') {
        print_braille(ch);
        i = i + 1;
        ch = text[i];
    }
    return 0;
}
