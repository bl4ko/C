#include <stdio.h>

#define N 1000 
#define MAX(a,b) a>b?a:b

int main()
{   
    // int n;
    // for (int i = 0; i < 1000; i++) {
    //     fread(&n, sizeof(int), 1, stdin);
    //     printf("%d\n", n);
    // }
    int n;
    for (int i = 0; i < 500; i++) {
        fread(&n, sizeof(int), 1, stdin);
        printf("%d\n", n);
    }
    return 0;
}