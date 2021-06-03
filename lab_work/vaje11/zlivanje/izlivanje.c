#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DOLZINA_IMENA 100

int main() {
    int stDatotek; scanf("%d", &stDatotek);
    FILE** vhodi = malloc(sizeof(FILE*) * stDatotek);
    //preberemno vse vhodne datoteke
    char* ime_datoteke = malloc(sizeof(char)* (MAX_DOLZINA_IMENA+1));
    for (int i = 0; i < stDatotek; i++) {
        scanf("%s", ime_datoteke);
        vhodi[i] = fopen(ime_datoteke, "r");
    }
    //preberemo se ime izhodne datoteke
    scanf("%s", ime_datoteke);
    FILE* izhod = fopen(ime_datoteke, "w");

    // inicializreamo array parov
    int stKoncanih = 0;
    int* blok = malloc(sizeof(int)*stDatotek);
    bool* bool_blok = malloc(sizeof(bool)*stDatotek);
    for (int i = 0; i < stDatotek; i++) {
        if(fscanf(vhodi[i], "%d", &blok[i])<1) {
            bool_blok[i] = true;
            stKoncanih++;
        }
    }

    while (stKoncanih < stDatotek) {
        int indeksMin = -1;
        for (int i = 0; i < stDatotek; i++) {
            if (!bool_blok[i]) {
                if (indeksMin == -1 || blok[i] < blok[indeksMin]) {
                    indeksMin = i;
                }
            }
        }
        fprintf(izhod, "%d\n", blok[indeksMin]);
        int novo;
        if(fscanf(vhodi[indeksMin], "%d", &novo) < 1) {
            bool_blok[indeksMin] = true;
            stKoncanih++;
        }
        else 
            blok[indeksMin] = novo;
    }
    for (int i = 0; i < stDatotek; i++) {
        fclose(vhodi[i]);
    }
    free(ime_datoteke);
    free(vhodi);
    fclose(izhod);
    free(blok);
    free(bool_blok);
}