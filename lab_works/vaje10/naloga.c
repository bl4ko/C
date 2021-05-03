
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

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
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek=element;
    if (zacetek == NULL || zacetek->podatek > element) {
        novo->naslednje=zacetek;
        zacetek = novo;
    } else {
        Vozlisce* v = zacetek;
        while (v->naslednje != NULL && v->naslednje->podatek < element) {
            v = v -> naslednje;
        }
        novo -> naslednje = v->naslednje;
        v -> naslednje = novo;
    }
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek == NULL || element < zacetek -> podatek) {
        Vozlisce* novo = malloc (sizeof(Vozlisce));
        novo -> naslednje = zacetek;
        novo -> podatek = element;
        return novo;
    }
    zacetek -> naslednje = vstaviUrejenoR(zacetek -> naslednje, element);
    return zacetek;
}

int main() {
    return 0;
}
