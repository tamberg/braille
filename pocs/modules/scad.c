#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "parts.h"
#include "scad.h"

char *scad_module =
    "$fn = 36;\n"
    "h_base = 2;\n"
    "h_dot = 0.6;\n"
    "r_dot = 0.8;\n"
    "\n"
    "module pattern(d1, d2, d3, d4, d5, d6) {\n"
    "    if (d1) { translate([0.0, 5.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d2) { translate([0.0, 2.5, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d3) { translate([0.0, 0.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d4) { translate([2.5, 5.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d5) { translate([2.5, 2.5, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "    if (d6) { translate([2.5, 0.0, 0]) cylinder(h_dot, r_dot, r_dot); }\n"
    "}\n"
    "\n"
    "cube([%1.f, %1.f, h_base]);\n";

char *scad_object =
    "translate([%1.f, %1.f, h_base]) pattern(%d, %d, %d, %d, %d, %d);\n";

void print_scad_object(unsigned char value, int x, int y) {
    int dot1 = (value >> 0) & 1;
    int dot2 = (value >> 1) & 1;
    int dot3 = (value >> 2) & 1;
    int dot4 = (value >> 3) & 1;
    int dot5 = (value >> 4) & 1;
    int dot6 = (value >> 5) & 1;

    printf(scad_object, x + 0.0, y + 0.0, dot1, dot2, dot3, dot4, dot5, dot6);
}

void print_part_braille_scad_object(struct part *p, int i) {
    print_scad_object(p->tuple->braille_bits, 4 + i * 6, 4);
}

void print_braille_scad() {
    int n = count_parts() - 1;
    printf(scad_module, 4.0 + (n * 6.0) + 2.5 + 4.0, 4.0 + (0 * 10.0) + 5.0 + 4.0);
    iterate_parts(print_part_braille_scad_object, NULL);
}
