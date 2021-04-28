#include <stdio.h>
#include <stdlib.h>

int MEMO[1001][1001];

int najvisjaCena(int stPredmetov, int* prostornine, int* cene,int ix, int vNah) {
    if (ix == stPredmetov)
        return 0;
    if (MEMO[ix][vNah] > 0 ) {
        return MEMO[ix][vNah];
    }

    int naj_cena = najvisjaCena(stPredmetov, prostornine, cene, ix+1, vNah);
    
    if (prostornine[ix] <= vNah) {
        int z_predmetom= cene[ix] + najvisjaCena(stPredmetov, prostornine, cene, ix+1, vNah-prostornine[ix]);
        if (z_predmetom > naj_cena)
            naj_cena = z_predmetom;
    }
    MEMO[ix][vNah] = naj_cena;
    return MEMO[ix][vNah];
}

int main()
{
    int volumen; scanf("%d", &volumen);
    int st_predmetov; scanf("%d", &st_predmetov);
    int* volumni_predmetov = calloc(st_predmetov, sizeof(int));
    for (int i = 0; i < st_predmetov; i++) 
        scanf("%d", &volumni_predmetov[i]);
    int* cene_predmetov = calloc(st_predmetov, sizeof(int));
    for (int i = 0; i < st_predmetov; i++) 
        scanf("%d", &cene_predmetov[i]);
    printf("%d\n",najvisjaCena(st_predmetov, volumni_predmetov, cene_predmetov, 0, volumen));

    free(volumni_predmetov);
    free(cene_predmetov);
}