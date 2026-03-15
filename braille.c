// https://tamberg.mit-license.org

#include <stdio.h>
#include <assert.h>

struct letter {
    char ch;
    char *braille_s;
    char *braille_l[3];
}; 

// https://en.wikipedia.org/wiki/Braille_ASCII

struct letter letters[] = {
    {'a', "⠁", {"● ○",
                "○ ○",
                "○ ○"}
    },
    {'b', "⠃", {"● ○",
                "● ○",
                "○ ○"}
    },
    {'c', "⠉", {"● ●",
                "○ ○",
                "○ ○"}
    },
    {'d', "⠙", {"● ●",
                "○ ●",
                "○ ○"}
    },
    {'e', "⠑", {"● ○",
                "○ ●",
                "○ ○"}
    },
    {'f', "⠋", {"● ●",
                "● ○",
                "○ ○"}
    },
    {'g', "⠛", {"● ●",
                "● ●",
                "○ ○"}
    },
    {'h', "⠓", {"● ○",
                "● ●",
                "○ ○"}
    },
    {'i', "⠊", {"○ ●",
                "● ○",
                "○ ○"}
    },
    {'j', "⠚", {"○ ●",
                "● ●",
                "○ ○"}
    },
    {'k', "⠅", {"● ○",
                "○ ○",
                "● ○"}
    },
    {'l', "⠇", {"● ○",
                "● ○",
                "● ○"}
    },
    {'m', "⠍", {"● ●",
                "○ ○",
                "● ○"}
    },
    {'n', "⠝", {"● ●",
                "○ ●",
                "● ○"}
    },
    {'o', "⠕", {"● ○",
                "○ ●",
                "● ○"}
    },
    {'p', "⠏", {"● ●",
                "● ○",
                "● ○"}
    },
    {'q', "⠟", {"● ●",
                "● ●",
                "● ○"}
    },
    {'r', "⠗", {"● ○",
                "● ●",
                "● ○"}
    },
    {'s', "⠎", {"○ ●",
                "● ○",
                "● ○"}
    },
    {'t', "⠞", {"○ ●",
                "● ●",
                "● ○"}
    },
    {'u', "⠥", {"● ○",
                "○ ○",
                "● ●"}
    },
    {'v', "⠧", {"● ○",
                "● ○",
                "● ●"}
    },
    {'w', "⠺", {"○ ●",
                "● ●",
                "○ ●"}
    },
    {'x', "⠭", {"● ●",
                "○ ○",
                "● ●"}
    },
    {'y', "⠽", {"● ●",
                "○ ●",
                "● ●"}
    },
    {'z', "⠵", {"● ○",
                "○ ●",
                "● ●"}
    },
    {' ', " ", {"○ ○",
                "○ ○",
                "○ ○"}
    },
    {',', "⠂", {"○ ○",
                "● ○",
                "○ ○"}
    },
    {';', "⠆", {"○ ○",
                "● ○",
                "● ○"}
    },
    {':', "⠒", {"○ ○",
                "● ●",
                "○ ○"}
    },
    {'?', "⠢", {"○ ○",
                "● ○",
                "○ ●"}
    },
    {'!', "⠖", {"○ ○",
                "● ●",
                "● ○"}
    },
    {'(', "⠶", {"○ ○",
                "● ●",
                "● ●"}
    },
    {')', "⠶", {"○ ○",
                "● ●",
                "● ●"}
    },
    {'*', "⠔", {"○ ○",
                "○ ●",
                "● ○"}
    },
// error: character too large for enclosing character literal type
//
//    {'“', "⠦", {"○ ○", // quote left
//                "● ○",
//                "● ●"}
//    }
//    {'”', "?", {"○ ○", // quote right
//                "○ ●",
//                "● ●"}
//    },
    {'.', "⠄", {"○ ○",
                "○ ○",
                "● ○"}
    },
    {'-', "⠤", {"○ ○",
                "○ ○",
                "● ●"}
    },
    {'\'', "⠠", {"○ ○", // single quote
                 "○ ○",
                 "○ ●"}
    }
};

int index_of(char ch) {
    assert( // valid chars [a-z] or one of the special chars
        ('a' <= ch && ch <= 'z') || 
        ch == ' ' || ch == ',' || ch == ';' || ch == ':' ||
        ch == '?' || ch == '!' || ch == '(' || ch == ')' ||
        ch == '.' || ch == '-' || ch == '\'');
    int i = 0;
    while (letters[i].ch != ch) {
        i++;
    }
    return i;
}

struct letter *letter_by(char ch) {
    int i = index_of(ch);
    return &letters[i];
}

int pos = 0;
char *text;

int read_ch() {
    int ch = text[pos];
    pos++;
    return ch;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s \"text\"\n", argv[0]);
        return -1;
    }

    // build line
    struct letter *line[32];
    text = argv[1];
    int n = 0;
    int ch = read_ch();
    while (ch != '\0') {
        assert(n < 32);
        line[n] = letter_by(ch);
        n++;
        ch = read_ch();
    }

    // print line small
    for (int i = 0; i < n; i++) {
        printf("%s", line[i]->braille_s);
    }
    printf("\n\n");

    // print line large
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < n; x++) {
            printf("%s   ", line[x]->braille_l[y]);
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++) {
        printf(" %c    ", line[j]->ch);
    }
    printf("\n");

    return 0;
}
