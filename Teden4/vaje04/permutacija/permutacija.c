#include <stdio.h>
#include <stdbool.h>

#define MAX_VELIKOST_STEVILA 1000000


bool stevila[MAX_VELIKOST_STEVILA];

int main() 
{   
    int n, stevka;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stevka);
        if (stevka >= n || n < 0 || stevila[stevka] == true) {
            printf("NE\n");
            return 0;
        }
        stevila[stevka] = true;
    }
    printf("DA\n");

    return 0;
    
}