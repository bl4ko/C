#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *input;   
    FILE *output;

    if (argc < 3) return 1;
    if (strcmp (argv[1], "-") == 0) {
        input = stdin;  
    }
    else {
        input = fopen(argv[1], "r"); 
        if (input == NULL) {
            fprintf(stderr, "ERROR input!\n");
            return 1;
        }
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

    static unsigned char block[1024];
    int* iblock = ((int*)(&block[0]));

    int len = 0;
    while(1) {
        int n = fread(block, sizeof(unsigned char), 1024, input);
        for (int i =0; i < 256; i++) printf("%d ", iblock[i]); printf("\n");
        len += n;
        if (n < 1024) break;
    }
    printf("LENGTH: %d\n", len);

    fclose(input);                
    fclose(output);
}