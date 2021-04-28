
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -e__main__ -o test01 test01.c naloga2.c
./test01

*/

#include <stdio.h>
#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    int* vmesniKazalec = *a;
    *a = *b;
    *b = vmesniKazalec;
}

void uredi(int** a, int** b, int** c) {
    if (**a > **b)
        zamenjaj(a, b); 
    if (**a > **c)
        zamenjaj(a, c);
    if (**b > **c)
        zamenjaj(b,c);   
}

int main() {
    return 0;
}
