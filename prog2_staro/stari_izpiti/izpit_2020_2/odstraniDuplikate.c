#include <stdio.h>

void odstaniDuplikate(FILE* vhod, FILE* izhod) {
    char c;
    char prejsne = -1;
    while ((c=fgetc(vhod))!=EOF) {
        if (c==prejsne && ((c>='a' && c<= 'z') || (c>= 'A' && c<='Z'))) {
            continue;
        }
        else {
            prejsne = c;
            fputc(c, izhod);
        }
    }
}

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "r");
    odstaniDuplikate(vhod, stdout);
    return 0;
}