#include <stdio.h>
#include <stdbool.h>
#include <math.h>


bool jePitagorejsko(int c)
{
    for (int a = 1; a < c; a++) {
        int b2 = c * c - a * a;
        int b = round(sqrt(b2));        
        if (b * b == b2)
            return true;
    }
    return false;   
}


int main() 
{   
    int spMeja, zgMeja;
    scanf("%d%d", &spMeja, &zgMeja);
    
    int stVseh = 0;
    for (int c = spMeja; c <= zgMeja; c++) {
        if (jePitagorejsko(c)) {
            stVseh++;
        }
    }
    printf("%d\n", stVseh);
    return 0;
}

//1, 100 -> 42
//1, 1000 -> 567
//1, 10000 -> 6449