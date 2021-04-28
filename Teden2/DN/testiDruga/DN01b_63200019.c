#include <stdio.h>

void izpisi(int n)
{   
    if (n/10)
        izpisi(n/10);
    putchar(n%10 + '0');
}

int main() 
{   
    int c = getchar();
    while (c != '1') 
        c = getchar();
    int stevec = 0;
    int sameNicle = 0;
    while (c== '1' || c == '0') {
        stevec+=1;
        c = getchar();
        if (c == '1')
            sameNicle = -1;
    }
    izpisi(sameNicle == 0 ? stevec-1 : stevec);
    putchar('\n');
    return 0;
}

