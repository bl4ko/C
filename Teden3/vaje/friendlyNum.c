#include <stdio.h>
#include <math.h>

int vsotaDeljiteljev(int x) 
{   
    int vsotaDel = 1;
    int zgornjaMeja = sqrt(x);
    for (int i =2; i <= zgornjaMeja ; i++) 
        if (x % i ==0)
            vsotaDel += i + x/i;
    if ((zgornjaMeja * zgornjaMeja) == x) vsotaDel-=zgornjaMeja;
    return vsotaDel;
}

int main() 
{
    int n;
    scanf("%d", &n);
    int kandidat = vsotaDeljiteljev(n);
    printf("%d\n", kandidat);
    if (vsotaDeljiteljev(kandidat) == n)
        printf("%d\n", kandidat);
    else
        printf("NIMA\n");
    return 0;
    // for (int i = 1; i < 1801; i++) {
    //     printf("%d %8d\n", i, vsotaDeljiteljev(i));
    // }
    // return 0;
}