#include <stdio.h>

#include "lists.h"

typedef struct {int a; int b;} str1;
typedef struct {int c; ind d;} str1;

int main(int argc, char** argv) 
{
    printf("Hello world\n");
    lists();
#ifdef TEST
    printf("prg: %d\n", num_nodes);
#else
    printf("Done.\n");
#endif
    return 0;
}