#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parts.h"
#include "svg.h"

char *svg_start = 
    "<svg width=\"%.1fmm\" height=\"%.1fmm\" xmlns=\"http://www.w3.org/2000/svg\">\n";

char *svg_group =
    "  <g>\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "  </g>\n";

char *svg_end = 
    "</svg>\n";

void print_svg_group(unsigned char value, int x, int y) {
    char *dot1 = (value >> 0) & 1 ? "black" : "none";
    char *dot2 = (value >> 1) & 1 ? "black" : "none";
    char *dot3 = (value >> 2) & 1 ? "black" : "none";
    char *dot4 = (value >> 3) & 1 ? "black" : "none";
    char *dot5 = (value >> 4) & 1 ? "black" : "none";
    char *dot6 = (value >> 5) & 1 ? "black" : "none";

    printf(svg_group, 
        x + 0.0, y + 0.0, dot1,
        x + 0.0, y + 2.5, dot2,
        x + 0.0, y + 5.0, dot3,
        x + 2.5, y + 0.0, dot4,
        x + 2.5, y + 2.5, dot5,
        x + 2.5, y + 5.0, dot6);
}

void print_part_braille_svg_group(struct part *p, int i) {
    print_svg_group(p->tuple->braille_bits, 4 + i * 6, 4);
}

void print_braille_svg() {
    int n = count_parts() - 1;
    printf(svg_start, 4.0 + (n * 6.0) + 2.5 + 4.0, 4.0 + (0 * 10.0) + 5.0 + 4.0);
    iterate_parts(print_part_braille_svg_group, NULL);
    printf("%s", svg_end);
}
