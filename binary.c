#include <stdio.h>
#include <string.h>

char *svg_doc_start = 
    "<svg height=\"100%\" width=\"100%\" xmlns=\"http://www.w3.org/2000/svg\">\n";

char *svg_pattern =
    "  <g transform=\"translate(%dmm %dmm)\">\n"
    "    <circle r=\"0.8mm\" cx=\"10.0mm\" cy=\"10.0mm\" fill=\"black\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"10.0mm\" cy=\"12.5mm\" fill=\"none\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"10.0mm\" cy=\"15.0mm\" fill=\"black\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"12.5mm\" cy=\"10.0mm\" fill=\"black\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"12.5mm\" cy=\"12.5mm\" fill=\"none\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "    <circle r=\"0.8mm\" cx=\"12.5mm\" cy=\"15.0mm\" fill=\"black\" stroke=\"black\" stroke-width=\"0.01mm\" />\n"
    "  </g>\n";

char *svg_doc_end = 
    "</svg>\n";

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

   printf("%s", svg_doc_start);
   printf(svg_pattern, 6, 6);
   printf(svg_pattern, 16, 6);
   printf(svg_pattern, 22, 6);
   printf("%s", svg_doc_end);
   return 0;
}
