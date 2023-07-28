#include <stdio.h>

int main()
{
    int num, a, b, i;
    scanf("%d", &num);
    for(i=0;i<num;i++)
    {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n",i+1, a, b, a+b);
    }
}