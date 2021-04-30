
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

//vsota iterativno
int vsotaI(Vozlisce* zacetek) {
    int vsota = 0;
    while (zacetek != NULL) {
        vsota += zacetek->podatek;
        zacetek = zacetek->naslednje;
    }
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL)
        return 0;
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce* trenutno = zacetek;
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek=element;
    if (trenutno == NULL || trenutno->podatek > element) {
        novo->naslednje=trenutno;
        return novo;
    }
    while (trenutno->naslednje != NULL && trenutno->naslednje->podatek < element) {
        trenutno = trenutno -> naslednje;
    }
    novo->naslednje = trenutno->naslednje;
    trenutno->naslednje = novo;
    return zacetek;
}



Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek == NULL || zacetek->podatek >= element) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo -> naslednje = zacetek;
        novo -> podatek = element;
        return novo;
    }
    else if (zacetek->naslednje == NULL || zacetek->naslednje->podatek >= element) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek->naslednje;
        zacetek->naslednje = novo;
    }
    else {
        vstaviUrejenoR(zacetek->naslednje, element);
    }
    return zacetek;
}

int main() {
    return 0;
}
