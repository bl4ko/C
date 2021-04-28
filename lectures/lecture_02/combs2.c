#include <stdio.h>

int combs(int n);

int main()
{
    printf("%d\n", combs(5));
    return 0;
}

int inner(int i1, int i2, int i3)
{
    printf("%d %d %d\n", i1, i2, i3);
    return 1;
}

//funkcija za zadno zanko
int loop3(int n, int i1, int i2, int i3)
{
    if (i3 == n)
        return 0;
    else 
        return inner(i1,i2,i3) + loop3(n,i1,i2,i3+1);
}

int loop2(int n, int i1, int i2)
{
    if (i2==n) 
        return 0;
    else {
        return loop3(n, i1, i2, 0) + loop2(n, i1, i2+1);
    }
}

int loop1(int n, int i1)
{
    if (i1==n)
        return 0;
    else {
        return loop2(n, i1, 0) +  loop1(n, i1+1);
    }
}

int combs(int n)
{   
    return loop1(n, 0);
}