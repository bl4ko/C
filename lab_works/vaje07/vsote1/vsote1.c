#include <stdio.h>

long MEMO[401][401];

long particije(int n, int k)
{   
    if (n == 0 && k == 0)
        return 1;
    if (k == 0)
        return 0;
    if (MEMO[n][k] > 0)
        return MEMO[n][k];
    long z = particije(n-k, k <= n-k ? k : n-k);
    long brez = particije(n, k-1);
    long stNacinov = z + brez;
    MEMO[n][k] = z + brez;
    return stNacinov;
}

int main()
{   
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    printf("%ld\n", particije(n,k));
    return 0;
}