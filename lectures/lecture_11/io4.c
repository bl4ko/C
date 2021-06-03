#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE *input;   
    FILE *output;

    if (argc < 3) return 1;
    if (strcmp (argv[1], "-") == 0) {
        input = stdin;  
    }
    else {
        input = fopen(argv[1], "r"); 
        fprintf(stderr, "ERROR input!\n");
        return 1;
    }

    if (strcmp (argv[2], "-") == 0) {
        output = stdout;    
    }
    else {
        output = fopen(argv[2], "w");  
        if (output == NULL) {
            fprintf(stderr, "ERROR input!\n");
            return 1;
        }
    }

    // program ki bere samo stevke
    
    int c = 0;
    while ((c = fgetc(input)) != EOF) { 
        if (('0' <= c) && (c <= '9')) {
            fputc(c, output);
            // fflush(output);    // iz medpomnilnika zahteva prepis podatkov fizicno na disk
            printf("=> %c\n", c);   
        }
    }
    fclose(input);                
    fclose(output);

    exit(0);    //zapre datoteke in jih pospravi na disk
    _exit(0);    // prekini izvajanje programa zdj, takoj brez ukvarjanja z zapiranjem datotek
    return 0;
}