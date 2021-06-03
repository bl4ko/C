#include <stdio.h>

int main() {
    int cifra; scanf("%d", &cifra);
    int stStevk; scanf("%d", &stStevk);

    int log10 = 1;
    while (cifra > log10) {
        log10 *= 10;
    }
    log10/=10;

    for (int stevka = 1; cifra > 0; i++) {
        int stevka = cifra / log10;

    }
}