
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga2.h"

int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}

// void izrisi(Ulomek ulomek, char* ime) {
//     printf("%s: %d/%d\n", ime, ulomek.st, ulomek.im);
// }

// void izrisiTocko(Tocka tocka) {
//     printf("T(%d/%d,%d/%d)\n",tocka.x.st, tocka.x.im, tocka.y.st, tocka.y.im);
// }

void okrajsajUlomek(Ulomek* ulomek) {
    ////izrisi(*ulomek, "prvotni");
    if (ulomek->st < 0 && ulomek-> im < 0) {
        ulomek->st = -ulomek->st;
        ulomek->im = -ulomek->im;
    }
    else if (ulomek-> im < 0) {
        ulomek->im = -ulomek->im;
        ulomek->st = -ulomek->st;
    }
    int gcd = hcf(ulomek->im < 0 ? -ulomek->im : ulomek->im, ulomek->st < 0 ? -ulomek->st : ulomek->st);
    //printf("gcd = %d\n", gcd);
    if (gcd == 1) {
        ////izrisi(*ulomek, "okrajsan");
        return;
    }
    ulomek->st = ulomek->st / gcd;
    ulomek->im = ulomek->im / gcd;
    ////izrisi(*ulomek, "okrajsan");
}


Tocka projekcija(Tocka t, Premica p) {
    Tocka* presecisce = malloc(sizeof(Tocka));
    if (p.navpicna) {
        presecisce->x = p.n;
        presecisce->y = t.y;
    }
    else if (p.k.st == 0) {
        presecisce->x = t.x;
        presecisce->y = p.n;
    }
    else {
        //pravoktonica p2 ki bo v imenovalcu hranila predznak
        Premica* p2 = malloc(sizeof(Premica));
        p2->k.st =  p.k.im;
        p2->k.im = -p.k.st;
        okrajsajUlomek(&(p2->k));
        //izrisi(p2->k, "k");
        // izracunamo se n = -kx + y
        p2->n.st =  p2->k.st * t.x.st;
        p2->n.im = -p2->k.im * t.x.im;

        p2->n.st = p2->n.st * t.y.im + t.y.st*p2->n.im;
        p2->n.im = p2->n.im * t.y.im;
        okrajsajUlomek(&(p2->n));
        //izrisi(p2->n, "n");
        
        //nabor spremenljivk
        int k1 = p2->k.st, k2 = p2->k.im, n1 = p2->n.st, n2= p2->n.im;
        int k3 = p.k.st, k4 = p.k.im, n3 = p.n.st, n4 = p.n.im;

        // x koordinata presecisca
        presecisce->x.st = n3*n2*k2*k4 - (n1*n4*k2*k4);
        presecisce->x.im = n4*n2*k1*k4 - (k3*k2*n4*n2);
        okrajsajUlomek(&(presecisce->x));
        //izrisi(presecisce->x, "x");

        // y koordinata presecisca
        int x1 = presecisce->x.st, x2 = presecisce->x.im;
        presecisce->y.st = k1*x1*n2 + n1*k2*x2;
        presecisce->y.im = k2*x2*n2;
        okrajsajUlomek(&(presecisce->y));
        //izrisi(presecisce->y, "y");
        free(p2);
    }
    return *presecisce;
}

int main() {
    return 0;
}
