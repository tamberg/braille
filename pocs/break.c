#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct word {
    char text[32];
    struct word *next;
};

struct word *words;

void append_word(struct word *w) {
    if (words == NULL) {
        words = w;
    } else {
        struct word *x = words;        
        while (x->next != NULL) {
            x = x->next;
        }
        x->next = w;
    }
}

void parse_words(char *text) {
    int i = 0;
    while (text[i] != '\0') {
        struct word *w = malloc(sizeof(struct word));
        w->text[0] = '\0';
        w->next = NULL;
        int j = 0;
        while (text[i] != '\0' && text[i] != ' ') {
            //printf("%c\n", text[i]);
            w->text[j] = text[i];
            i++;
            j++;
        }
        w->text[j] = '\0';
        if (text[i] != '\0') {
            i++;
        }
        append_word(w);
    }
}

void print_words(){
    struct word *w = words;
    while (w != NULL) {
        printf("%s ", w->text);
        w = w->next;
    }
    printf("\n");
}

// 01234567 n = 8
// hello,** 6 < n
// this*is* 4 < n, 2 < r = 3 - 4 - 1
// a*wonder 1 < n, 9 > n
// ful*hack 3 < n, 4 <= 4

void layout_words(int n){
    int r = n;
    struct word *w = words;
    while (w != NULL) {
        int len = strlen(w->text);
        if (r > len) {
            printf("%s*", w->text);
            r -= len;            
            r--;   
            w = w->next;
        } else if (r == len) {
            printf("%s", w->text);
            r -= len;
            w = w->next;
        } else { // r < len
            if (r < n) {
                while (r > 0) {
                    printf("$");
                    r--;
                }
                printf("\n");
                r = n;
            } else {
                assert(0); // not yet implemented
            }
            //printf("%s*", w->text);
            //r--;
// TODO: split word
        }
        //r -= len;
        //w = w->next;
    }
}

int main(int argc, char *argv[]) {
    char *text = argv[1];
    int n = atoi(argv[2]);
    parse_words(text);
    print_words();
    layout_words(n);
    return 0;
}
