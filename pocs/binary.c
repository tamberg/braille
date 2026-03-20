#include <stdio.h>

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
   print_bin(0b00000001);
   print_bin(0b00000010);
   print_bin(0b00000100);
   print_bin(0b00001000);
   print_bin(0b00010000);
   print_bin(0b00100000);
   print_bin(0b01000000);
   print_bin(0b10000000);
   return 0;
}
