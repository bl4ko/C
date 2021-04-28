#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stMoznosti;

bool je_narascujoce(int* arr, int dolzina) 
{
    for (int i = 0; i < dolzina-1; i++)
        if (arr[i] > arr[i+1])
            return false;
    return true;
}

int* zamenjaj(int *arr, int dolzinaZaporedja, int r,  int prva_pozicija, int druga_pozicija) 
{   
    int* noviArr = malloc (sizeof(int) * dolzinaZaporedja);
    for (int i = 0; i < dolzinaZaporedja; i++) {
        if (i >= prva_pozicija && i < prva_pozicija + r) 
            noviArr[i] = arr[druga_pozicija+i-prva_pozicija];
        else if (i >= druga_pozicija && i < druga_pozicija + r) 
            noviArr[i] = arr[prva_pozicija + i - druga_pozicija];
        else
            noviArr[i] = arr[i];
    }
    return noviArr;
}

void rekurzija(int* arr, int k, int n, int r, int st_korakov)
{   
    if (je_narascujoce(arr, n)) {
        stMoznosti++;
    }
    if (st_korakov == k)
        return;
    for (int i = 0; i <= n - 2*r; i++) {
        for (int j = i + r; j <= n - r; j++) {
            int* noviArr = zamenjaj(arr, n, r, i, j);
            rekurzija(noviArr, k, n, r, st_korakov+1);
            free(noviArr);
        }
    }
}

int main() 
{
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    int r; scanf("%d", &r);

    int* zaporedje = (int*) malloc (sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &zaporedje[i]);
    }
    rekurzija(zaporedje, k, n, r, 0);
    free(zaporedje);
    printf("%d\n", stMoznosti);
    return 0;
}