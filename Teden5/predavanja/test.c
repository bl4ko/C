#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **c;
    int n = 3;
    int m = 2;
    int k = 1;
    //rezeviramo prostor
    c = (int**) malloc ( n* sizeof (int*));
        printf("&c   = %p,  c    = %p\n", &c,  c);
        printf("\n");
    
    for (int i = 0; i < n; i++) {
        c[i] = (int*)malloc (n*sizeof(int));
        printf("c[%d] = %p, &c[%d] = %p\n",i, c[i], i, &c[i]);
        for (int j = 0; j < m; j++) {
            c[i][j] = k++;
            //printf("c[%d][%d] = %d, &c[%d][%d] = %p", i, j, c[i][j], i, j, &c[i][j]);
        }
        printf("\n");
    }

    printf(" **c    = %d\n", **c);
    printf("c[0][0] = %d\n", c[0][0]);

    return 0;


}