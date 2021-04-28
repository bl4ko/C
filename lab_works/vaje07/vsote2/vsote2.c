#include <stdio.h>
#include <stdlib.h>

void particije(int n, int k, int* elementi, int indeks)
{   
    if (n < k)
        k = n;
    if (n == 0 && k == 0) {
        for (int i = 0; i < indeks-1; i++)
            printf("%d + ", elementi[i]);
        printf("%d\n", elementi[indeks-1]);
    }
    else if (k!=0) {
        elementi[indeks] = k;
        particije(n-k, k, elementi, indeks+1);
        particije(n, k-1, elementi, indeks); 
    }
}

int main()
{   
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    int* p = (int*) malloc (n * sizeof(int));
    particije(n,k,p,0);
    return 0;
}