#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *text = argv[1]; 
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        printf("%#02x\n", 0x000000ff & text[i]);
    }
    return 0;
}
