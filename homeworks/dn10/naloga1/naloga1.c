
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "naloga1.h"

/*
Iterativen pristop k problemu.
Definitivno je rekurziven bolsi, vendar mi ni uspel.
*/

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    if (zacetek == NULL) return NULL;       // trivialen pogoj
    if (k == 1) return zacetek;             // trivialen pogoj
    Vozlisce* prejsne = NULL;
    Vozlisce* sprehajalec = zacetek;
    for (int i = 1; sprehajalec != NULL; i++) {
        if (i % k == 0) {
            if (prejsne == NULL) {
                prejsne = sprehajalec;
                zacetek = sprehajalec;
            }
            else {
                prejsne -> naslednje = sprehajalec;
                prejsne = prejsne -> naslednje;
            }
            sprehajalec = sprehajalec -> naslednje;
        }
        else {
            Vozlisce* za_izbris = sprehajalec;
            //printf("izbrisano: %d{%p}\n", za_izbris->podatek, za_izbris);
            sprehajalec = sprehajalec -> naslednje;
            free(za_izbris);
        }
    }
    prejsne -> naslednje = NULL; return zacetek;
}

Vozlisce* generiraj_tabelo(int* t, int st_elementov) {
    if (st_elementov <= 0) {
        return NULL;
    }
    Vozlisce* novo_vozlisce= malloc(sizeof(Vozlisce));
    novo_vozlisce -> podatek = *t;
    novo_vozlisce -> naslednje = generiraj_tabelo(t+1, st_elementov-1);  
    return novo_vozlisce;  
}

void narisi_array(Vozlisce* zacetek) {
    bool prvic = true;
    //printf("[");
    while (zacetek!=NULL) {
        if (prvic) {
            //printf("%d", zacetek-> podatek);
            prvic = false;
        }
        else {
            //printf(", %d", zacetek->podatek);
        }
        zacetek = zacetek -> naslednje;
    }
    //printf("]\n");
}

void izrisi_naslove(Vozlisce* zacetek) {
    bool prvic = true;
    //printf("[");
    while (zacetek!=NULL) {
        if (prvic) {
            //printf("{%p}", zacetek);
            prvic = false;
        }
        else {
            //printf(", {%p}", zacetek);
        }
        zacetek = zacetek -> naslednje;
    }
    //printf("]\n");
}


int main() {
    // Vozlisce* zacetek = NULL;
    // int tabela[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    // zacetek = generiraj_tabelo(tabela, 17);
    // //printf("TAB: "); narisi_array(zacetek); //printf("\n");
    // //printf("____Nova tabela____\n");
    // zacetek = zdesetkaj(zacetek, 5);
    // //printf("TAB: "); narisi_array(zacetek); //printf("\n");
    // izrisi_naslove(zacetek);
    return 0;
}


