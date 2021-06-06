#include <stdio.h>

long memo[68][68];

long stKorakov(int n, int visina) {
    if (n==0) {
        return visina == 0 ? 1 : 0;
    }
    if (memo[n-1][visina+1] == -1) 
        memo[n-1][visina+1] = stKorakov(n-1, visina+1);
    long gor = memo[n-1][visina+1];
    long dol = 0;
    if (visina >= 1) {
        if (memo[n-1][visina-1] == -1) {
            memo[n-1][visina-1] = stKorakov(n-1, visina-
            1);
        }
        dol = memo[n-1][visina-1];
    }
    return gor + dol;
}

int main() {
    int n; fscanf(stdin, "%d", &n);
    for (int i = 0; i < 68; i++) 
        for (int j = 0; j < 68; j++) 
            memo[i][j] = -1;
    printf("%ld\n", stKorakov(n,0));
}