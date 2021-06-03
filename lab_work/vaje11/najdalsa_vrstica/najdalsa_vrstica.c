c#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ZGORNJA_MEJA_DOLZINE 1000000

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "ERROR number of arguments!\n");
        return 1;
    }
    printf("argc= %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");
    
    char* maxline = malloc(sizeof(char) * ZGORNJA_MEJA_DOLZINE+1);
    int max_length = 0;
    char* line = malloc(sizeof(char) * ZGORNJA_MEJA_DOLZINE+1);
    while (fgets(line, ZGORNJA_MEJA_DOLZINE+1, input) != NULL) {
        int length = strlen(line);
        if (length > max_length) {
            max_length = length;
            strcpy(maxline, line);
        }
    } 
    fprintf(output, "%s", maxline);
    free(line);
    free(maxline);
    fclose(input);
    fclose(output);
    return 0;
}