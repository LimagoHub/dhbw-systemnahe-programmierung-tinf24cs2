#include <stdio.h>
#include <string.h>
#include "stdlib.h"


double sum(int anzahl, double ersterWert, ...){

    double result = 0;
    double *ptr = &ersterWert;

    for(int i = 0; i < anzahl; i ++) {
        result += ptr[i];
    }
    return result;
}

void ausgabe(char * erstesWort, ...) {
    char ** ptr = &erstesWort;
    while(*ptr)
        printf("%s\n", *ptr++);
}

int main(int argc, char ** argv, char ** env) {

    ausgabe("Hallo", "Welt", "Hallo","Universum", NULL);
    //printf("%lf\n", sum(3, 10.0, 20.0,30.0));
    return 0;
}
