#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naloga.h"
#include <ctype.h>

int vsota(int* zac, int* kon) {
    int vsota = 0;
    int *zacetek = zac;
    while (zacetek <= kon)
        vsota += *zacetek++;
    return vsota;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if (*indeks == -1) {
        *indeks = *kazalec - t; 
    }
    else {
        *kazalec = t + *indeks; 
    }
}

// void frekvenceCrk(char* niz, int** frekvence) {
    
//     int length = 'z' - 'a' + 1;
//     int *t = (int*) calloc(length, sizeof(int));
//     char *p = niz;
//     while (*p != '\0') {
//         char znak = *p;
//         if (znak >= 'A' && znak <= 'Z' || znak >= 'a' && znak <= 'z') {
//             int indeks = (znak >= 'a') ? (znak - 'a') : (znak - 'A');
//             t[indeks]++;
//         }
//         p++;
//     }
//     *frekvence = t;
// }

void frekvenceCrk(char* niz, int** frekvence) {
    
    int length = 'z' - 'a' + 1;
    int *t = (int*) calloc(length, sizeof(int));
    for (int i = 0; i < strlen(niz); i++) {
        char znak = tolower(niz[i]);
        if (isalpha(znak)) {
            int indeks = znak - 'a';
            t[indeks]++;
        }
    }
    *frekvence = t;
}


int main() {
    // int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // printf("%d\n", vsota(&t[2], &t[4]));

    return 0;


}
