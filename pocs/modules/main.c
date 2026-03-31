#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parser.h"
#include "ascii.h"
#include "svg.h"
#include "scad.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *text = argv[1];
        parse_text(text);    
        print_braille_text();
    } else if (argc == 3) {
        char *opt = argv[1];
        char *text = argv[2];
        parse_text(text);
        if (strcmp(opt, "-svg") == 0) {
            print_braille_svg();
        } else if (strcmp(opt, "-scad") == 0) {
            print_braille_scad();
        }
    } else {
        printf("usage: %s [-svg|-scad] text\n", argv[0]);
    }
    return 0;
}
