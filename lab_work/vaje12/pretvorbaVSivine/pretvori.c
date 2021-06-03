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
    FILE* output = fopen("%s.pgm", "w");
    if (output == NULL)
        fprintf(stderr, "NAPAKA: izhodne datoteke, ni bilo mogoce narediti\n");
    int vrstica; sscanf(argv[2], "%d", &vrstica);
    int stolpec; sscanf(argv[3], "%d", &stolpec);

    char* prvaVrstica = malloc(sizeof(char) * MAX_LINE+1);
    fgets(prvaVrstica, MAX_LINE+1 ,input);
    fprintf(output, "P5\n");


    int sirina; fscanf(input, "%d", &sirina); 
    fgetc(input);  // [\n]
    int visina; fscanf(input, "%d", &visina); 
    fprintf(output, "%d %d\n", sirina, visina);
    
    int velikostNajvecjegaPiksla; fscanf(input, "%d", &velikostNajvecjegaPiksla);
    fprintf("%d\n", velikostNajvecjegaPiksla);
    
    fgetc(input); // [\n]
    fputc(output, '\n');

    static unsigned char byte[3]; //3 byti = en piksel
    for (int i = 0; i < visina; i++) {
        for (int j = 0; j < sirina; j++) {
            fread(byte, sizeof(unsigned char), 3, input);
            int sivinskaVrednost = (30*byte[0] + 59*byte[1] + 11*byte[2])/100;
            fwrite(sivinskaVrednost,1, sizeof(unsigned char), output);
        }
    }
    return 1;
}