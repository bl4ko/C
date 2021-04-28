#include <stdio.h>
#include <math.h>

//vsota deljiteljev brez samega sebe
int vsotaDeljiteljev(int n)
{   
    int vsota = 1;
    int meja = sqrt(n);
    for (int i = 2; i <= meja; i++) {
        if (n % i == 0)
            vsota += i + n /i;
    }
    if ((meja * meja) == n) 
        vsota -= meja;
    return vsota;
}

int main()
{   
    int n;
    scanf("%d", &n);
    int kandidat = vsotaDeljiteljev(n);
    if (vsotaDeljiteljev(kandidat) == n && kandidat != n)
        printf("%d\n", kandidat);
    else
        printf("NIMA\n");
    return 0;
}

/*
TESTI
(220, 284)
(1184, 1210)
(2620, 2924)
(5020, 5564)
*/