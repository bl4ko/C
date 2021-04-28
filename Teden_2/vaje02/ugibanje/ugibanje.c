#include <stdio.h>

int main()
{
    int spMeja, zgMeja;
    scanf("%d%d", &spMeja, &zgMeja);
    while (spMeja < zgMeja) {
        int ugib = (spMeja + zgMeja) / 2;
        int odgovor;
        scanf("%d", &odgovor);
        switch (odgovor) {
            case 1:
                spMeja = ugib + 1;
                break;
            case -1:
                zgMeja = ugib - 1;
                break;
            case 0:
                printf("%d %d\n", spMeja, zgMeja);
                return 1;
        }
    }
    int a;
    scanf("%d", &a);
    if (a == 0) {
        printf("%d\n", zgMeja);
        return 1;
    }
    else {
        printf("PROTISLOVJE\n");
        return 0;
    }
}

// int a ,b;
    // scanf("%d%d", &a, &b);
    // int odgovor;
    // do {
    //     int poskus = (a+b) / 2;
    //     scanf("%d", odgovor);
    //     if (odgovor == 1)
    //         a = poskus + 1;
    //     else if (odgovor == -1)
    //         b = poskus - 1;
    // }   while (odgovor != 0 && a <= b);

    // if (a == b)
    //     printf("%d\n", a);
    // else if (a < b)
    //     printf("%d %d\n", a, b);
    // else 
    //     printf("PROTISLOVJE\n");
    // return 0;