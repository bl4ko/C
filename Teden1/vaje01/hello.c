#include <stdio.h>

int globalna_neki = 10; //raje globalne spremenljivke glej Stack and heap memory


int main() 
{
    int aa[10];

    int *pt = (int *) malloc((10 * sizeof(int))); //tabela gre na heap
    free(pt); //brisemo

    printf("Pozdravljen, svet!\n"); //carriage return vrne kazalec na zacetek vrstice {CR LF, LF}
    return 0; //podatek nasemu OS kako se je program izvedel, 0-okej
}