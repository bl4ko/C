#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long x, long a, long b) {
    long spodnjaMeja = a, zgornjaMeja = b;
    while (spodnjaMeja < zgornjaMeja) {
        long kandidat = (spodnjaMeja + zgornjaMeja) / 2;
        long vrednost = f(kandidat);
        if (vrednost > x)
            zgornjaMeja = kandidat - 1;
        else if (vrednost < x)
            spodnjaMeja = kandidat + 1;
        else
            return kandidat;
    }
    return spodnjaMeja;
}

