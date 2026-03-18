#include <stdio.h>
#include <string.h>

char *svg_doc_start = 
//    "<svg height=\"100%\" width=\"100%\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    "<svg width=\"%.1fmm\" height=\"%.1fmm\" xmlns=\"http://www.w3.org/2000/svg\">\n";

char *svg_pattern =
    "  <g>\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"%.1fmm\" cy=\"%.1fmm\" fill=\"%s\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "  </g>\n";

char *svg_doc_end = 
    "</svg>\n";

void print_pattern(unsigned char value, int x, int y) {
    char *dot1 = (value >> 0) & 1 ? "black" : "none";
    char *dot2 = (value >> 1) & 1 ? "black" : "none";
    char *dot3 = (value >> 2) & 1 ? "black" : "none";
    char *dot4 = (value >> 3) & 1 ? "black" : "none";
    char *dot5 = (value >> 4) & 1 ? "black" : "none";
    char *dot6 = (value >> 5) & 1 ? "black" : "none";

    printf(svg_pattern, 
        x + 0.0, y + 0.0, dot1,
        x + 0.0, y + 2.5, dot2,
        x + 0.0, y + 5.0, dot3,
        x + 2.5, y + 0.0, dot4,
        x + 2.5, y + 2.5, dot5,
        x + 2.5, y + 5.0, dot6);
}

void print_bin(unsigned char value) {
    printf("0b%d%d%d%d%d%d%d%d\n",
        (value >> 7) & 1,
        (value >> 6) & 1, 
        (value >> 5) & 1, 
        (value >> 4) & 1, 
        (value >> 3) & 1, 
        (value >> 2) & 1, 
        (value >> 1) & 1, 
        (value >> 0) & 1);
}

int main(void) {
    /*
    print_bin(0b00000000);
    print_bin(0b00000001);
    print_bin(0b00000010);
    print_bin(0b00000100);
    print_bin(0b00001000);
    print_bin(0b00010000);
    print_bin(0b00100000);
    print_bin(0b01000000);
    print_bin(0b10000000);
    printf("\n");
    printf("%lu\n", strlen("⠓"));
    print_bin("⠓"[0]);
    print_bin("⠓"[1]);
    print_bin("⠓"[2]);
    */

    printf(svg_doc_start, 4 + 3 * 6 + 2.5 + 4, 4 + 10 + 5 + 4);
    print_pattern(0b00000001, 4 + 0 * 6, 4);
    print_pattern(0b00000010, 4 + 1 * 6, 4);
    print_pattern(0b00000100, 4 + 2 * 6, 4);
    print_pattern(0b00001000, 4 + 3 * 6, 4);
    print_pattern(0b00010000, 4 + 0 * 6, 4 + 10);
    print_pattern(0b00100000, 4 + 1 * 6, 4 + 10);
    print_pattern(0b00101010, 4 + 2 * 6, 4 + 10);
    print_pattern(0b00111111, 4 + 3 * 6, 4 + 10);
    printf("%s", svg_doc_end);
    return 0;
}
