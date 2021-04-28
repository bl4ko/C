#include <stdio.h>

#define LENGTH(x) (int)(sizeof(x) / sizeof(x[0]))


int main()
{
    // int a[20];
    // for (int i =0; i < LENGTH(a); i++)
    //     a[i] = i;
    
    // for (int i = 0; i < LENGTH(a); i++)
    //     printf("a[%d] = %d\n", i, a[i]);
    

    // char b[35];
    // printf("%d\n", LENGTH(b));

    int a[20];
    printf("naslov arraya: %p\n", a);
    printf("naslov a[0]  : %p\n", &a[0]);
    printf("naslov a[1]  : %p\n", &a[1]);

}