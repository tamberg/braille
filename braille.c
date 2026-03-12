// https://tamberg.mit-license.org

#include <stdio.h>
#include <assert.h>

struct entry {
    char ch;
    char *braille;
};

struct entry entries[] = {
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
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s \"text\"\n", argv[0]);
        return -1;
    }
    char *text = argv[1];
    int i = 0;
    int ch = text[i];
    while (ch != '\0') {
        int pos = (ch == ' ') ? 26 : (ch - 'a');
        assert(ch == entries[pos].ch);
        printf("%s\n", entries[pos].braille);
        i++;
        ch = text[i];
    }
    return 0;
}
