#include <stdio.h>
#include <limits.h>

//#define MAX_STEVIL = 1000000
//int zaporedje[MAX_STEVIL];

// int sestej(int zacetek, int konec, int a[]) {
//     int vsota = 0;
//     for (int i = zacetek; i <= konec; i++) {
//         vsota += a[i];
//     }
//     return vsota;   
// }

// int main()
// {
//     int n, stevka;
//     scanf("%d", &n);

//     for (int i =0; i < n; i++) {
//         scanf("%d", &stevka);
//         stevila[i] = stevka;
//     }

//     int maxVsota = 0;
//     //vsa mozna podzaporedja
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             int trenutnaVsota = sestej(i, j, stevila) ;
//             if (maxVsota == 0 || trenutnaVsota > maxVsota)
//                 maxVsota = trenutnaVsota;
//         }
//     }
//     printf("%d\n", maxVsota);
//     return 0; 
// }

//V2
// int main()
// {
//     int n, stevka;
//     scanf("%d", &n);

//     for (int i =0; i < n; i++) {
//         scanf("%d", &stevka);
//         stevila[i] = stevka;
//     }

//     int najVrsta = 0;
//     for (int i = 0; i < n; i++) {
//         int vrsta = 0;
//         for (int j = i; j < n; j++) {
//             vrsta += stevila[j];
//             if (najVrsta == 0 || vrsta > najVrsta)
//                 najVrsta = vrsta;
//         }
//     }   
//     printf("%d\n", najVrsta);
//     return 0;
// }


//V3
int main()
{
    //DN tudi zacetek in konec zaporedja
    int dolzina;
    scanf("%d", &dolzina);

    int najVsota  = INT_MIN, vsota = 0;
    int maxStart = 0, maxStop = 0;
    int start = 0;

    for (int i = 0; i < dolzina; i++) {
        int stevka;
        scanf("%d", &stevka);
        vsota += stevka;
        if (vsota > najVsota) {
            najVsota = vsota;
            maxStart = start;
            maxStop = i;

        }
        if (vsota < 0) {
            vsota = 0;
            start = i + 1;
        }
    }
    printf("%d\n", najVsota);
    //printf("[%d,%d]\n", maxStart, maxStop);
    return 0;
}


