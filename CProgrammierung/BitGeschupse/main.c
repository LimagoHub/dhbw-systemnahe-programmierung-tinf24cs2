#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char x = 0b10101010;
    char y = 0b11110000;

    //x |=  (1 << 5);

    //x &= ~(1 << 5);

    x ^= (1 << 5);

    char buffer[10];

    itoa(x,buffer, 2);
    printf("%s\n", buffer);
    return 0;
}
