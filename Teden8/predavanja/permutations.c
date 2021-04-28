#include <stdio.h>
#include <stdlib.h>

void perms(int *elems, int num_elems, int indeks)
{
    if (indeks == num_elems) {
        for (int i = 0; i < num_elems; i++) {
            printf("%d ", elems[i]);
        }
        putchar('\n');
        return;
    }
    for (int i = indeks; i < num_elems; i++) {
        int tmp;
        tmp = elems[indeks]; elems[indeks] = elems[i]; elems[i] = tmp;
        perms(elems, num_elems, indeks+1);
        tmp = elems[indeks]; elems[indeks] = elems[i]; elems[i] = tmp;
    }
}

int main()
{
    static int elems[100];
    int num_elems = 4;
    for (int j = 0; j < num_elems; j++) {
        elems[j] = j+1;
    }
    perms(elems, num_elems, 0);
}