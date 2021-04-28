#include <stdio.h>

int sum(int start, int end)
{
    if (start == end)
        return end;
    return start + sum(start+1, end);
}


int main()
{
    int zac; scanf("%d", &zac);
    int kon; scanf("%d", &kon);
    printf("The sum of numbers from %d to %d : %d\n", zac, kon,sum(zac, kon));
}