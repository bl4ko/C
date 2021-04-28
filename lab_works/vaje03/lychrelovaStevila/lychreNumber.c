#include <stdio.h>
#include <stdbool.h>

long obratno(long n)
{   
    long obratno = 0;
    while (n > 0) {
        obratno = obratno * 10 + n % 10;
        n /= 10;
    }
    return obratno;
}

bool jeLych(long n, int k)
{  
    for (int i = 1; i <= k; i++) {
        n += obratno(n); 
        if (n == obratno(n))
            return false;
        if (n > 1e17)
            return true;
    }
    return true;
}

int main()
{   
    int k;
    int spMeja, zgMeja;
    scanf("%d", &k);
    scanf("%d %d", &spMeja, &zgMeja);
    int steviloLych = 0;
    for (int i = spMeja; i <= zgMeja; i++) {
        if (jeLych(i, k)) 
            steviloLych++;
    }
    printf("%d\n", steviloLych);
    return 0;
}
