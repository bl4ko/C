
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga1.c
./test01

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    while (*--t != 0);
    int* zacetek = t+1;
    while (*++t != 0) 
        (*dolzina)++; 
    *konec = t-1;
    return zacetek;
}

int main() {
    return 0;
}
