
#include <stdio.h>
#include <stdlib.h>

int global;

void treeLen(int** arr, int stevec, int indeks, int n)
{   
    //printf("(%d, %d), stevec = %d, indeks = %d\n", arr[0][indeks], arr[1][indeks], stevec, indeks);
    if (indeks >= n || indeks < 0 || (arr[0][indeks] == 0 && arr[1][indeks] == 0)) {
        global = stevec > global ? stevec : global;
        return;
    }  
    if (arr[0][indeks] != 0)
        treeLen(arr, stevec+1, indeks+arr[0][indeks],n);
    if (arr[1][indeks] != 0)
        treeLen(arr, stevec+1, indeks+arr[1][indeks], n);
}

int main() 
{   
    int n; scanf("%d", &n);
    int** twoDimensional = calloc(2, sizeof(int*));

    twoDimensional[0] = calloc(n, sizeof(int));
    twoDimensional[1] = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &twoDimensional[0][i]);
        scanf("%d", &twoDimensional[1][i]);
    }
    treeLen(twoDimensional, 0, 0, n);
    printf("%d\n", global);
    return 0;
}