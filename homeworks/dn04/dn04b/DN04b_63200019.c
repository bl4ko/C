#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    int* stevke = (int*) calloc (k, sizeof(int));
    for (int i = 0; i < n; i++) {
        int stevka; scanf("%d", &stevka);
        if (stevka<k)
            stevke[stevka]++;
    }
    long vsota = 0;
    for (int i = 1; i <= k/2; i++) {
        if (stevke[i] > 0 && stevke[k-i] > 0) 
            vsota += (long) stevke[i] * (long) stevke[k-i];
        }
    if (k % 2 == 0 && stevke[k/2] >= 2) 
        vsota -= (stevke[k/2] * stevke[k/2] + stevke[k/2]) / 2; //magic
    printf("%ld\n", vsota);
    free(stevke);
    return 0;
}
    