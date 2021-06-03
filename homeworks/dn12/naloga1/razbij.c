#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_NAME 50

int main(int argc, char** argv) 
{   
    
    if (argc < 3) { 
        fprintf(stderr, "Premalo vhodnih argumentov!\n");
        return 1;
    }
    FILE* vhod = fopen(argv[1], "r");
    
    char* imeDatoteke = malloc(sizeof(char) * MAX_FILE_NAME);
    sprintf(imeDatoteke, "%s.0", argv[1]);
    FILE* izhodnaDatoteka = fopen(imeDatoteke, "w");
    int indeksDatoteke = 0;
    int dolzinaDatoteke = 0;  
    int byte;
    int k = atoi(argv[2]);
    
    while ((byte = fgetc(vhod)) != EOF) {
        fputc(byte, izhodnaDatoteka);
        dolzinaDatoteke++;
        if (dolzinaDatoteke == k) {
            dolzinaDatoteke = 0;
            indeksDatoteke++;
            fclose(izhodnaDatoteka);
            sprintf(imeDatoteke, "%s.%d", argv[1], indeksDatoteke);
            izhodnaDatoteka = fopen(imeDatoteke, "w");
        }
    }
    free(imeDatoteke);
    fclose(izhodnaDatoteka);
    fclose(vhod);
}