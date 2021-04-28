#include <stdio.h>
#include <stdlib.h>

int max(int* arr, int indeks, int length, int maxInt)
{
    if (indeks == length)
        return maxInt;
    if (*(arr+indeks) > maxInt)
        maxInt = *(arr+indeks);
    max(arr, indeks+1, length, maxInt);
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
    printf("max(arr) = %d\n", max(arr, 0, dolzina, 0));
}