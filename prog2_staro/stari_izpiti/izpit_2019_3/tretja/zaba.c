#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int skoki(bool* new, int k1, int k2, int numS, int trPoz, int stPl) {
    if (numS == -1 || trPoz < 0 || trPoz >= stPl) 
        return 0;
    int nova = 0;
    if (new[trPoz] == false) {
        printf("%s%d", trPoz == 0 ? "" : ", ", trPoz);
        new[trPoz] = true;
        nova = 1;
    }
    // mamo 4 moznosti 2 x 2 (naprej in nazaj)
    return nova + skoki(new,k1,k2,numS-1,trPoz+k1,stPl) + skoki(new,k1,k2,numS-1,trPoz-k1,stPl) +
    skoki(new,k1,k2,numS-1,trPoz+k2,stPl) + skoki(new,k1,k2,numS-1,trPoz-k2,stPl);
}

int main() {
    int stPl; int k1; int k2; int numS;
    scanf("%d%d%d%d", &stPl, &k1, &k2, &numS);
    bool* new = malloc(sizeof(bool)*stPl);
    printf("Osvojene ploscice: {");
    printf("}\nStOsvojenih=%d\n", skoki(new, k1, k2, numS, 0, stPl));

    free(new);
    return 0;
}