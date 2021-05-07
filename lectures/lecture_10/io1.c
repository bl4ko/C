#include <stdio.h>
#include <string.h>

// Stvari ki si jih moramo zapomnit.
// FILE
// fopen, fclose
// fgetc, fputc, EOF
// stdin, stdout, stderr

int main(int argc, char *argv[])
{
    FILE *input;   
    FILE *output;

    if (argc < 3) return 1;
    if (strcmp (argv[1], "-") == 0) {
        input = stdin;  
    }
    else {
        input = fopen(argv[1], "r"); // argument r = read, 
        if (input == NULL) {
            //printf("ERROR input !\n");  // <= posebni primer fprintf(stdout, "ERROR inp!\n")
            fprintf(stderr, "ERROR input!\n");
            return 1;
        }
    }
    if (strcmp (argv[2], "-") == 0) {
        output = stdout;    // datoteka ki se izpise na zaslonu
    }
    else {
        output = fopen(argv[2], "w");  // argument w = write
        if (output == NULL) {
            //printf("ERROR output!\n"); // <= fprintf (stdout, "ERROR out!\n");
            fprintf(stderr, "ERROR input!\n");
            return 1;
        }
    }

    int ch;
    do {
        ch = fgetc(input);
        if (ch != EOF) fputc(ch, output);
    } while (ch != EOF);

    fclose(input);                
    fclose(output);
    return 0;
}