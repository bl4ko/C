#include <stdio.h>
#include <stdlib.h>

struct s 
{
    char i;
    double f;
    int j;
}
sl;

int main()
{
    printf("sizeof=%lu\n", sizeof(struct s));
    printf("%p(%p, %p, %p)\n", &sl, &(sl.i), &(sl.f), &sl.j);
    return 0;
}