#include <stdio.h>

int main()
{
    int H, M, T;
    scanf("%d %d %d", &H, &M, &T);
    if(M+T>=60)
        if(H+((M+T)/60)>=24)
            printf("%d %d", H+((M+T)/60)-24, M+T-60*((M+T)/60));
        else
            printf("%d %d", H+(M+T)/60, M+T-60*((M+T)/60));
    else
        printf("%d %d", H, M+T);
}