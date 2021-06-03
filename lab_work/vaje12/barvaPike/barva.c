//hexdump -C (za pogled sestanjstiski zapis datoteke)
// 00000000  50 36 0a 33 20 32 0a 32  35 35 0a ff 00 00 00 ff  |P6.3 2.255......|
// 00000010  00 00 00 ff ff ff 00 ff  00 ff 00 ff ff           |.............|
// 0000001d

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 10000

int main(int argc, char* argv[]) {

    if (argc <= 3) 
        fprintf(stderr, "NAPAKA: premalo argumentov ob klicu programa\n");

    FILE* input = fopen(argv[1], "r");
    if (input == NULL) 
        fprintf(stderr, "NAPAKA: vhodna datoteka ni najdena\n");
    int vrstica; sscanf(argv[2], "%d", &vrstica);
    printf("vrstica=%d\n", vrstica);
    int stolpec; sscanf(argv[3], "%d", &stolpec);
    printf("stolpec=%d\n", stolpec);
    char* prvaVrstica = malloc(sizeof(char) * MAX_LINE+1);
    fgets(prvaVrstica, MAX_LINE+1 ,input);
    printf("prvaVrstica=%s", prvaVrstica);
    int sirina;
    fscanf(input, "%d", &sirina); //3
    printf("sirina=%d\n", sirina);
    fgetc(input);  //\n
    int visina;
    fscanf(input, "%d", &visina); //2
    printf("visina=%d\n", visina);
    int velikostNajvecjegaPiksla;
    fscanf(input, "%d", &velikostNajvecjegaPiksla);
    printf("maxPixlSize=%d\n", velikostNajvecjegaPiksla);
    fgetc(input); // presledek

    static unsigned char byte[3]; //3 byti = en piksel
    for (int i = 0; i < visina; i++) {
        for (int j = 0; j < sirina; j++) {
            fread(byte, sizeof(unsigned char), 3, input);
            if (i == vrstica && j == stolpec) {
                printf("%d %d %d\n", byte[0], byte[1], byte[2]);
                return 0;
            }
        }
    }
    return 1;
}

