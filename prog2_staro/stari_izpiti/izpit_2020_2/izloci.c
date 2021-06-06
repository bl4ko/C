#include <stdio.h>
#include <stdlib.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v) {
    if (zac==v) {
        Vozlisce* prejsno = zac;
        zac = zac -> naslednje;
        free(prejsno);
        return zac;
    }
    Vozlisce* sprehajalec = zac -> naslednje;
    Vozlisce* prejsne = zac;
    while (sprehajalec != NULL) {
        if (sprehajalec == v) {
            prejsne -> naslednje = sprehajalec-> naslednje;
            free(sprehajalec);
            return zac;
        }
        prejsne = sprehajalec;
        sprehajalec = sprehajalec -> naslednje;
    }
    return zac;
}

Vozlisce** zgradiVozlisca(int stVozlisc) {
    Vozlisce** vozlisca = malloc(sizeof(Vozlisce*) * stVozlisc);
    for (int i = 0; i < stVozlisc;i++) {
       vozlisca[i] = malloc(sizeof(Vozlisce));
       vozlisca[i] -> podatek = i;
       if (i != 0)
        vozlisca[i-1] -> naslednje = vozlisca[i];
    }
    vozlisca[stVozlisc-1]-> naslednje == NULL;
    return vozlisca;
}

void pocisti(Vozlisce* zacetno) {
    Vozlisce* prejsno = zacetno;
    while (zacetno != NULL) {
        prejsno = zacetno;
        zacetno = zacetno->naslednje;
        free(prejsno);
    }
}

void izrisi(Vozlisce* zacetno) {
    while (zacetno != NULL) {
        printf("[%d]-->", zacetno->podatek);
        zacetno=zacetno->naslednje;
    }
    printf("%p\n", zacetno);
}

int main(int argc, char** argv) {
    int stVozlisc = atoi(argv[1]);
    int indeksIzlocenega = atoi(argv[2]);
    Vozlisce** vozlisca = zgradiVozlisca(stVozlisc);
    Vozlisce* zac = izloci(vozlisca[0], vozlisca[indeksIzlocenega]);
    izrisi(zac);
    pocisti(zac);
}