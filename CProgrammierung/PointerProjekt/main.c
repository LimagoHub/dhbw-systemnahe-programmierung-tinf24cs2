#include <stdio.h>

size_t stringlenght(char * wort) {
    register size_t counter = 0;

    while(wort[counter])
        counter ++;

    return counter;
}


void stringcopy(char * destination, char *source) {

    while(*destination++ = *source++){}
}



int main(int argc, char ** argv) {

    char wort[] = "hallo";
    char buffer[100];

    int a = 10;
    stringcopy(buffer, wort);

    printf("%d\n", argc);

    //printf("%s\n", wort);
    //printf("%d\n", sizeof(wort));

    return 0;
}
