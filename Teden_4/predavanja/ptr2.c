#include <stdio.h>

int main()
{
    int i = 0;

    printf("i=%d @ %p\n", i, &i);
    scanf("%d", &i); //dam ji naslov na spremenljivko i, povemo fuknciji kam naj prebrano vrednost shrani
    printf("i=%d @ %p\n", i, &i);

    return 0;
}