#include <stdio.h>
#include <stdlib.h>

void obrni(FILE* vhod, FILE* izhod) {
    int stVrstic = 0;
    char** vrstice = malloc(sizeof(char*)*1000);
    char* vrstica = malloc(sizeof(char)*1001);
    while (fgets(vrstica, 1000, vhod) != NULL) {
        vrstice[stVrstic] = vrstica;
        printf("vrstice[%d]=%s",stVrstic, vrstica);
        stVrstic++;
        vrstica = malloc(sizeof(char)*1001);
    }
    printf("\n");
    for (int i = stVrstic-1; i >= 0; i--) {
        fprintf(izhod, "vrstice[%d]=%s",i, vrstice[i]);
        free(vrstice[i]);
    }
    free(vrstice);
}

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "r");
    obrni(vhod, stdout);
    fclose(vhod);
    return 0;
}