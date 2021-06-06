#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* test = fopen(argv[1], "r");
    char* imeDatoteke = malloc(sizeof(char)*21);
    fscanf(test, "%s", imeDatoteke); 
    FILE* vhod = fopen(imeDatoteke, "r");
    fscanf(test, "%s", imeDatoteke);
    FILE* izhod = fopen(imeDatoteke, "w"); 
    fgetc(test);
    char znak = fgetc(test); 
    char* zmagovalnaVrstica = malloc(sizeof(char)*1001);
    char* vrstica = malloc(sizeof(char)*1001);
    while (fgets(vrstica, 1001, vhod) != NULL) {
        for (int i = 0; i < strlen(vrstica); i++) {
            if (vrstica[i] == znak) {
                strcpy(zmagovalnaVrstica, vrstica);
                break;
            }
        }
    }
    printf("%d\n", fprintf(izhod, "%s", zmagovalnaVrstica));
    free(vrstica); free(zmagovalnaVrstica); free(imeDatoteke);
    fclose(vhod); fclose(izhod);
    return 0; 
}
