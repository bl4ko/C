#include <stdio.h>
#include <stdlib.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* obrni(Vozlisce* zac) {
    if (zac == NULL || zac -> naslednje == NULL) {
        return zac;
    }
    Vozlisce* prejsno = NULL; 
    Vozlisce* trenutno = zac; 
    Vozlisce* naslednje = zac -> naslednje; 
    while (trenutno != NULL) {
        trenutno -> naslednje = prejsno; 
        prejsno = trenutno; 
        if (naslednje == NULL) 
            break;
        trenutno = naslednje; 
        naslednje = naslednje -> naslednje; 
    }
    return trenutno;
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
    int n = atoi(argv[1]);
    Vozlisce** vozlisca = zgradiVozlisca(n);
    izrisi(vozlisca[0]);
    Vozlisce* zacetek = obrni(vozlisca[0]);
    izrisi(zacetek);
    pocisti(zacetek);
    return 0;
}


