#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "rb");
    int nTemp = 10;
    char* temp = malloc(sizeof(char) * nTemp);
    fgets(temp, nTemp, vhod);
    free(temp);

    int sirina = 0;
    int visina = 0;
    int dummy = 0;
    fscanf(vhod, "%d%d%d", &sirina, &visina, &dummy);
    fgetc(vhod);    // \n

    // preberemo podatke o slikovnih pikah
    unsigned char* barve = malloc(3 * sirina * visina * sizeof(unsigned char));
    fread(barve, sizeof(unsigned char), 3 * visina * sirina, vhod);
    fclose(vhod);   //ne potrebujemo jo vec

    // pretovri barve v sivine
    unsigned char* sivine = malloc(sirina * visina * sizeof(unsigned char));
    int b = 0;
    int s = 0;
    for (int i = 0; i < visina; i++) {
        for (int j = 0; j < sirina; j++) {
            sivine[s] = (30 * barve[b] + 59 * barve[b + 1] + 11 * barve[b+2]) / 100;
            b+= 3;
            s++;
        }
    }
    free(barve);

    FILE* izhod = fopen(argv[2], "wb");
    fprintf(izhod, "P5\n");
    fprintf(izhod, "%d %d\n", sirina, visina);
    fprintf(izhod, "255\n");
    fwrite(sivine, sizeof(unsigned char), visina * sirina, izhod);
    fclose(izhod);

    free(sivine);
    return 0;
}
