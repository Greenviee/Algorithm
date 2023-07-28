#include <stdio.h>

int Fibonacci(int x);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", Fibonacci(n));
}

int Fibonacci(int x)
{
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    else
        return Fibonacci(x-1) + Fibonacci(x-2);
}