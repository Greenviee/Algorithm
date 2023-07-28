#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, sum;
    sum = 0;
    scanf("%d", &n);
    char num[n];
    scanf("%s", &num);
    for(i=0;i<n;i++)
		sum += num[i] - '0';
    printf("%d", sum);
}