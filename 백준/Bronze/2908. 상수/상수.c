#include <stdio.h>

int flip(int a);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(flip(a)>=flip(b))
        printf("%d", flip(a));
    else
        printf("%d", flip(b));
}

int flip(int a)
{
    int hun, one, f_number;
    hun = a/100;
    one = a%10;
    f_number = a - 100*hun - one + 100*one + hun;
    return f_number;
}