#include <stdio.h>
#include <stdlib.h>

int elems[1000];

void combs(int *elems, int num_elems, int max_elem, int i)
{
    if (i == num_elems) {
        for (int j = 0; j < num_elems; j++)
            printf("%d ", elems[j]);
        printf("\n");
    }
    else {
        for (int elem = 1; elem <= max_elem; elem++) {
            elems[i] = elem;
            combs(elems, num_elems, max_elem, i+1);
        }
    }
}

int main()
{   
    int *elems;
    int num_elems = 4;
    elems = (int*)malloc (num_elems * sizeof(int));
    if (elems == NULL) exit (1);

    combs(elems, num_elems, 3, 0); 
    free(elems);
    return 0;
}