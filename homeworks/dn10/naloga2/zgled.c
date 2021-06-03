#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"



int main() {
    int a = 21342344;
    char* beseda = malloc(sizeof(char) * 32);
    beseda = strcat(beseda, "avion: ");
    int returnValue = sprintf(beseda, "%d", a);
    printf("return = %d\n", returnValue);
    printf("beseda = %s\n", beseda);
    free(beseda);
    return 0;
}