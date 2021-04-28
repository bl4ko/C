#include <stdio.h>
#include <stdlib.h>

void preberiZaporedje(int *p, int n) 
{
    int stevka;
    for (int i =0; i < n; i++) {
        scanf("%d", &stevka);
        p[i] = stevka;
    }
}

int main()
{
    int n; scanf("%d", &n);
    int *prvoZap = (int*)calloc(n, 4), *drugoZap = (int*)calloc(n, 4);
    preberiZaporedje(prvoZap, n);
    preberiZaporedje(drugoZap, n);
    for (int i = 0; i < n; i++) {
        for (int j = i, k = 0; j < n; j++, k++) {
            if (prvoZap[j] != drugoZap[k]) {
                goto OuterLoop;
            }
        }
        printf("%d\n", i);
        return 0;
        OuterLoop: continue;
    }
    return -1;
}