#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b) {
    bool tranzitivna = true, antitranzitivna = true, netranzitivna = false;
    for (int i = a; i <= b; i++)
        for (int j = a; j <= b; j++) 
            for (int k = a; k <=b;  k++) {
                if (tranzitivna)
                    if (f(i, j) && f(j,k))
                        if (!f(i,k))
                            tranzitivna = false;
                if (antitranzitivna)
                    if (f(i,j) && f(j,k))
                        if (f(i,k))
                            antitranzitivna = false;
                if (!netranzitivna)
                    if (f(i,j) && f(j,k) && !f(i,k))
                        netranzitivna = true;
            }
    if (tranzitivna && antitranzitivna)
        return 1;
    else if (tranzitivna)
        return 2;
    else if (antitranzitivna)
        return 3;
    else if (netranzitivna)
        return 4;
    else 
        return -1;
}

