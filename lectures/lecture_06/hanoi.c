#include <stdio.h>
#include <math.h>

void hanoi1(char t1, char t2, char t3)
{
    printf("%c --> %c\n", t1, t3);
}

void hanoi2(char t1, char t2, char t3)
{
    printf("%c --> %c\n", t1, t2);  //hanoi1(t1, t3, t2)
    printf("%c --> %c\n", t1, t3);  //hanoi1(t1, t2, t3)
    printf("%c --> %c\n", t2, t3);  //hanoi1(t2, t1, t3)
}

void hanoi3(char t1, char t2, char t3)
{
    // 1. FAZA
    printf("%c --> %c\n", t1, t3);  //hanoi1(t1,t2,t3)  }
    printf("%c --> %c\n", t1, t2);  //hanoi1(t1,t3,t2)  }   hanoi2(t1,t3,t2)
    printf("%c --> %c\n", t3, t2);  //hanoi1(t3,t1,t2)  }

    // 2. FAZA
    printf("%c --> %c\n", t1, t3);  //hanoi1(t1,t2,t3);

    // 3. FAZA
    printf("%c --> %c\n", t2, t1);  //hanoi1(t2,t3,t1)  }
    printf("%c --> %c\n", t2, t3);  //hanoi1(t2,t1,t3)  }   hanoi2(t2,t1,t3)
    printf("%c --> %c\n", t1, t3);  //hanoi1(t1,t2,t3)  }
}

int num_moves;

void hanoi(int n, char t1, char t2, char t3) //imena stolpov
{
    if (n==1) {
        //printf("%c --> %c\n", t1, t3);
        num_moves++;
    }
    else {
        hanoi(n-1, t1, t3, t2);
        hanoi(1, t1, t2, t3);
        hanoi (n-1, t2, t1, t3);
    } 
}

int main()
{   
    int i; 
    scanf("%d", &i);
    hanoi(i, 'A', 'B', 'C');
    printf("%d\n", num_moves);
    printf("%d\n",(int)pow(2,i));
    return 0;
}