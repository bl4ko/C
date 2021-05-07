#include <stdio.h>
#include <string.h>
#include <errno.h>


/*
* fscanf, fprintf
* errno
*/

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

    while(1) {
        int i;
        int res = fscanf(input, "%d", &i);
        if (errno != 0) {
            fprintf(stderr, "ERROR: errno!\n");
            if (errno == ERANGE) {
                fprintf(stderr, "errno = ERANGE\n");
            }
            break;
        }
        printf("res=%d\n", res);
        if (res == EOF) break;
        if (res == 0) {
            fprintf(stderr, "ERROR: read!\n");
            break;
        }
        fprintf(output, "READ: %d\n", i);
    }
    

    fclose(input);                
    fclose(output);
    return 0;
}