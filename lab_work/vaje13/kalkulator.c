/*
Na vhodu 1000 znakov iz mnozice
- {0, 1, ..., 9, +, -, *, /, (, )}

3 + 4 * (5-2)
1. Odstranimo odvecne zunanje oklepaje
- npr. (6-2*9) so odvecni
- npr. (5-8) * (2+7) niso odvecni
-> oklepaji so odvec ko so vsi operandi znotraj zunanjih oklepajev
(input se zacne z zunanjimi oklepaji in konca z zunanjimi oklepaji)

2. Posci najbolj desni svoboden + ali -, ce takega operatorja ni, pa najbolj 
desni svoboden operator * ali /
- izraz locimo na desni del in levi del operatorja in izraza rekurzivno izracunamo
                3 + 4 * (5-2)
                /           \
               3            4*(5-2)
                           /       \
                          4        (5-2)
                                     |
                                    5-2
                                   /   \
                                  5     2

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN

int poisciOperator(char* niz) 
{
    return 0;
}

int kalkulator(char* niz) 
{
    // 1. odstranimo zunanje oklepaje
    while (niz[0] == '(' && niz[strlen(niz)-1] == ')') {
        memmove(&niz[0], &niz[1], strlen(niz));
        niz[strlen(niz) - 1] = '\0';    
    }

    // 2. poiscemo najbolj svoboden +,- / ce takega operatorja ni *,/
    // int poisci_prosti_operant(niz)   // vrne indeks
    int indOperatorja = poisciOperator(niz);
    

    // 3. rekurzivno razbijemo niz na dva pod operanda
    int vsota = 0;
    switch (niz[indeks]) {
        case '+':
            vsota = kalkulator(podniz1) + kalkulator(podniz2);
        case '-':
            vsota = kalkulator(podniz1) - kalkulator(podniz2);
        case '/':
            vsota = kalkulator(podniz1) / kalkulator(podniz2);
        case '*':
            vsota = kalkulator(podniz1) * kalkulator(podniz2);
        default:
            fprintf(stderr, "NAPAKA: locitveni operand ni pravilen: [%c]\n", niz[indeks]);
            return 0;
    }
    free(podniz1);
    free(podniz2);
    return vsota;
}

int main()
{
    char* vhod = malloc(sizeof(char)*MAX_LEN+1);
    scanf("%s", vhod);
    int rezultat = kalkulator(vhod);
    printf("%s\n", vhod);
    printf("%d\n", rezultat);
    free(vhod);
    return 0;
}