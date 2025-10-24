#include <stdio.h>
#include <string.h>
#include "stdlib.h"





typedef int (*MyIntPtrType)();
typedef double(*Operation)(double, double);

int sinnDesLebens() {
    return 42;
}

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return add(a, -b);
}

double mult(double a, double b) {
    return a * b;
}

int main(int argc, char ** argv, char ** env) {


    Operation feld[] = {add,sub, mult};

    double a = 3.0;
    double b = 4.0;

    for(int i = 0 ; i < sizeof (feld)/sizeof (Operation); i++){
        printf("%lf\n",feld[i](a,b) );
    }


    return 0;
}
