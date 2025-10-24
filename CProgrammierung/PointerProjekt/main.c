#include <stdio.h>

int main(void) {
    int feld[10];

    feld[0] = 10; // feld + index * sizeof(int)
    feld[1] = 20; // feld + index * sizeof(int)

    int* ptr = feld;


    printf("%d\n", *ptr);
    printf("%d\n", *feld);
    printf("%d\n", feld[0]);
    printf("%d\n", ptr[0]);

    printf("%d\n", feld[1]);
    printf("%d\n", ptr[1]);

    printf("%d\n", *(ptr + 1));

    printf("%d\n", sizeof(ptr));
    printf("%d\n", sizeof(feld));


    return 0;
}
