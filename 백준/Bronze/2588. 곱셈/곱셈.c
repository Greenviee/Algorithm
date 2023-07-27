#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a*(b%10)); //3
    printf("%d\n", a*((b/10)%10)); //4
    printf("%d\n", a*(b/100)); //5
    printf("%d\n", a*(b%10)+a*((b/10)%10)*10+a*(b/100)*100);
}