#include <stdio.h>
#include <stdlib.h>

void arrayToString(int *arr, int indeks, int dolzina) 
{
    if (indeks < dolzina) {
        printf("%d ", *(arr+indeks));
        arrayToString(arr, indeks+1, dolzina);
    }
}

int main()
{   
    printf("Vnesite dolzino Arraya: ");
    int dolzina; scanf("%d", &dolzina);
    int* arr = (int*) malloc (sizeof(int) * dolzina);
    for (int i = 0; i < dolzina; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &(*(arr+i)));
    }
    arrayToString(arr, 0, dolzina);
    putchar('\n');
    return 0;
}