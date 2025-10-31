#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char x = 0b10101010;
    char y = 0b11110000;

    char mask = 0b00100000;


    if((x & mask) != 0){

    }

    char buffer[10];

    itoa(x,buffer, 2);
    printf("%s\n", buffer);
    return 0;
}
