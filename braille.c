// https://tamberg.mit-license.org

#include <stdio.h>
#include <string.h>
#include <assert.h>

struct letter {
    char ch;
    char *braille;
};

struct letter letters[] = {
    {'a', "● ○\n"
          "○ ○\n"
          "○ ○\n"
    },
    {'b', "● ○\n"
          "● ○\n"
          "○ ○\n"
    },
    {'c', "● ●\n"
          "○ ○\n"
          "○ ○\n"
    },
    {'d', "● ●\n"
          "○ ●\n"
          "○ ○\n"
    },
    {'e', "● ○\n"
          "○ ●\n"
          "○ ○\n"
    },
    {'f', "● ●\n"
          "● ○\n"
          "○ ○\n"
    },
    {'g', "● ●\n"
          "● ●\n"
          "○ ○\n"
    },
    {'h', "● ○\n"
          "● ●\n"
          "○ ○\n"
    },
    {'i', "○ ●\n"
          "● ○\n"
          "○ ○\n"
    },
    {'j', "○ ●\n"
          "● ●\n"
          "○ ○\n"
    },
    {'k', "● ○\n"
          "○ ○\n"
          "● ○\n"
    },
    {'l', "● ○\n"
          "● ○\n"
          "● ○\n"
    },
    {'m', "● ●\n"
          "○ ○\n"
          "● ○\n"
    },
    {'n', "● ●\n"
          "○ ●\n"
          "● ○\n"
    },
    {'o', "● ○\n"
          "○ ●\n"
          "● ○\n"
    },
    {'p', "● ●\n"
          "● ○\n"
          "● ○\n"
    },
    {'q', "● ●\n"
          "● ●\n"
          "● ○\n"
    },
    {'r', "● ○\n"
          "● ●\n"
          "● ○\n"
    },
    {'s', "○ ●\n"
          "● ○\n"
          "● ○\n"
    },
    {'t', "○ ●\n"
          "● ●\n"
          "● ○\n"
    },
    {'u', "● ○\n"
          "○ ○\n"
          "● ●\n"
    },
    {'v', "● ○\n"
          "● ○\n"
          "● ●\n"
    },
    {'w', "○ ●\n"
          "● ●\n"
          "○ ●\n"
    },
    {'x', "● ●\n"
          "○ ○\n"
          "● ●\n"
    },
    {'y', "● ●\n"
          "○ ●\n"
          "● ●\n"
    },
    {'z', "● ○\n"
          "○ ●\n"
          "● ●\n"
    },
    {' ', "○ ○\n"
          "○ ○\n"
          "○ ○\n"
    },
    {',', "○ ○\n"
          "● ○\n"
          "○ ○\n"
    },
    {';', "○ ○\n"
          "● ○\n"
          "● ○\n"
    },
    {':', "○ ○\n"
          "● ●\n"
          "○ ○\n"
    },
    {'?', "○ ○\n"
          "● ○\n"
          "○ ●\n"
    },
    {'!', "○ ○\n"
          "● ●\n"
          "● ○\n"
    },
    {'(', "○ ○\n"
          "● ●\n"
          "● ●\n"
    },
    {')', "○ ○\n"
          "● ●\n"
          "● ●\n"
    },
    {'*', "○ ○\n"
          "○ ●\n"
          "● ○\n"
    },
// error: character too large for enclosing character literal type
//
//    {'“', "○ ○\n" // quote left
//          "● ○\n"
//          "● ●\n"
//    }
//    {'”', "○ ○\n" // quote right
//          "○ ●\n"
//          "● ●\n"
//    },
    {'.', "○ ○\n"
          "○ ●\n"
          "● ○\n"
    },
    {'-', "○ ○\n"
          "○ ●\n"
          "● ○\n"
    },
    {'\'', "○ ○\n" // single quote
          "○ ○\n"
          "○ ●\n"
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
    while (n < 32 && ch != '\0') {
        int i = index_of(ch);
        line[n] = &letters[i];
        n++;
        ch = read_ch();
    }

    // print line
    int j = 0;
    while (j < n) {
        printf("%c", line[j]->braille[0]);
        printf("%c", line[j]->braille[1]);
        printf("%c", line[j]->braille[2]);
        printf("%c", line[j]->braille[3]);
        printf("%c", line[j]->braille[4]);
        printf("%c", line[j]->braille[5]);
        printf("%c", line[j]->braille[6]);
        printf("   ");
        j++;
    }
    printf("\n");

    int k = 0;
    while (k < n) {
        printf("%c", line[k]->braille[8]);
        printf("%c", line[k]->braille[9]);
        printf("%c", line[k]->braille[10]);
        printf("%c", line[k]->braille[11]);
        printf("%c", line[k]->braille[12]);
        printf("%c", line[k]->braille[13]);
        printf("%c", line[k]->braille[14]);
        printf("   ");
        k++;
    }
    printf("\n");

    int m = 0;
    while (m < n) {
        printf("%c", line[m]->braille[16]);
        printf("%c", line[m]->braille[17]);
        printf("%c", line[m]->braille[18]);
        printf("%c", line[m]->braille[19]);
        printf("%c", line[m]->braille[20]);
        printf("%c", line[m]->braille[21]);
        printf("%c", line[m]->braille[22]);
        printf("   ");
        m++;
    }
    printf("\n");

    return 0;
}
