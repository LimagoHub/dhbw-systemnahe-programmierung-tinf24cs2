#include <stdio.h>

void stringcopy(char * destination, char *source) {

}


int main(void) {

    char wort[] = "hallo";
    char buffer[100];

    int a = 10;
    stringcopy(buffer, wort);

    printf("%s\n", buffer);

    //printf("%s\n", wort);
    //printf("%d\n", sizeof(wort));

    return 0;
}
