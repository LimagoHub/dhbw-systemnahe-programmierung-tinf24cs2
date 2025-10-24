#include <stdio.h>
#include <string.h>
#include "stdlib.h"

inline int NeuesMax(int x, int y) {
    return x>y?x:y;
}

#define SIEBEN 3+4
#define MAX(x,y) x>y?x:y

int main() {


    int a = 20;
    int b =30;
    int m = NeuesMax(++a,++b); // ++a>++b?++a:++b


    return 0;
}
