#include <stdio.h>
#include <stdbool.h>

int main()
{

    int dolzinaZaporedja = getchar() - '0';
    getchar();

    int najvecje = -1;
    int drugoNajvecje = -1;

    for (int i = 0; i < dolzinaZaporedja; i++)
    {
        int stevilo = getchar() - '0';
        getchar();

        if (stevilo > najvecje) 
        {   
            drugoNajvecje = najvecje;
            najvecje = stevilo;
        }
        else if (stevilo > drugoNajvecje)
            drugoNajvecje = stevilo;
    }

    putchar(drugoNajvecje +'0');
    putchar('\n');
    return 0;
}

