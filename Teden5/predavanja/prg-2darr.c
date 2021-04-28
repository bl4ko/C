#include <stdio.h>
#include <stdlib.h>

int a[3][2] = {{0,1}, {2,3}, {4,5}}; 

int sum (int b[3][2]) 
{
    int s = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            s = s + b[i][j];
    return s;
}

int sum1(int b[][2], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            s = s + b[i][j];
    return s;
}

/*  NEDELA
int sum2(int b[][], int n, int m)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s = s + b[i][j]; 
    return s;
}
*/

int sum2(int **b, int n, int m) //dvojni pointer **b, (kazalec na kazalce)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s = s + b[i][j]; 
    return s;
}



int main()
{
    for (int i = 0; i < 3; i++)  {
        for (int j = 0; j < 2; j++)  {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //vidimo da 2-dimenzionalna tabela ubistvu eno dimenzionlana
    int *p = &(a[0][0]);
    for (int i = 0; i < 6; i++)
        printf("%d ", p[i]);
    printf("\n");

    printf("sum: %d\n", sum(a));
    printf("sum: %d\n", sum1(a,3));
    //printf("sum: %d\n", sum2(a, 2, 3)); //Nebo delovalo, drugo dimenzijo rabimo vedt

    int **b;
    int n = 3;
    int m = 2;
    int k = 1;
    b = (int**)malloc (n * sizeof (int*)); //zunanja tabela
    for (int i = 0; i < n; i++) {
        b[i] = (int*)malloc (m*sizeof(int)); // notranje tabele;
        for (int j = 0; j < m; j++) {
            b[i][j] = k++; 
        }
    } 
    printf("sum=%d\n", sum2(b,n,m));
    //FREE (beg):
    for (int i = 0; i < n; i++)
        free(b[i]); //sprostim notranje tabele
    free(b); //sprostim zunanjo tabelo
    // FREE (end)

    return 0;
}