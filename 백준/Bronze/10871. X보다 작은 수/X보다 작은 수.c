#include <stdio.h>
int main ()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n], i;
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
        if(a[i]<x)
            printf("%d ", a[i]);}
}