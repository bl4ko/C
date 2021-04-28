#include <stdio.h>

int combs(int n);

int main()
{
    printf("%d\n", combs(4));
    return 0;
}

int combs(int n)
{   
    int num = 0;
    for (int i1 =0; i1 < n; i1++)
        for (int i2 = 0; i2 < n; i2++)
            for (int i3 = 0; i3 < n; i3++) {
                printf("%d %d %d\n", i1, i2, i3);
                num = num + 1;
            }
    return num;
}