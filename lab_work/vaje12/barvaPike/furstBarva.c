#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    // preberi glavo datoteke
    int nTemp = 10;
    char* temp = malloc(sizeof(char) * nTemp);
    fgets(temp, nTemp, vhod);   // prva vrstica (P6 + \n)
    
    int sirina = 0;
    int visina = 0;
    fscanf(vhod, "%d%d", &sirina, &visina); // sirina in visina
    fgetc(vhod);        // \n na koncu druge vrstice

    fgets(temp, nTemp, vhod);
    free(temp)

    //fseek() iskanje pozicije v binarni datoteki
    // preberemo podatke o slikovnih pikah (komponente R, G in B posameznih pik)
    unsigned char* pike = malloc(3 * sirina * visina * sizeof(unsigned char));
    fread(pike, sizeof(unsigned char), 3 * visina * sirina, vhod);
    fclose(vhod);

    // izluscimo barvne komponente pike na podanih koordinatah
    int indByta = (vrstica * sirina + stolpec) * 3;
    printf("%d %d %d\n", pike[indeks], pike[indeks+1], pike[indeks+2]);

    free(pike);
    return 0;
    
}