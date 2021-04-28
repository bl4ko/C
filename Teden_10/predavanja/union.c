#include <stdio.h>
/*
struct i_or_f
{
    int i;
    float f;
}
*/

union i_or_f    //zgodba o varcevanju pomnilnika (uporabljamo zgolj enega od vecih podatkov v njem)
{
    int i;
    double f;
};

void print(union i_or_f u)  {
    printf("print: i=%d f=%f\n", u.i, u.f);
}

int main()
{
    union i_or_f x;
    printf("sizeof=%lu\n", sizeof(union i_or_f));
    printf("%p(%p, %p)\n", &x, &(x.i), &(x.f));     //naslova lezita na enakem naslovu;

    x.i = 0;
    printf("i=%d f=%f\n", x.i, x.f);
    x.f = 3.14;
    printf("i=%d f=%f\n", x.i, x.f);

    print(x);
    print((union i_or_f)1234);
    print((union i_or_f)(double)2.71);
    print((union i_or_f)2.71);
    return 0;
}