#include <stdio.h>
#include <stdbool.h>

int main()
{
    int dolzinaZaporedja = getchar() - '0';
    getchar();

    //int vsiEnaki = 1;
    bool vsiEnaki = 1;
    int referencna = -1;

    for (int i = 0; i < dolzinaZaporedja; i++)
    {
        int stevilo = getchar() - '0';
        getchar();

        if (i==0) 
            referencna = stevilo;
        else if (stevilo != referencna) {
            vsiEnaki = 0;
            break;
        }
    }

    putchar(vsiEnaki ? '1' : '0');
    putchar('\n');
    return 0;
}