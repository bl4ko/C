#include <stdio.h>
#include <math.h>



int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int vsota = a +b;
    printf("vsota = %d\n", vsota);

    printf("sqrt(%d) = %.2f\n", vsota, sqrt(vsota));

    return 0;
}