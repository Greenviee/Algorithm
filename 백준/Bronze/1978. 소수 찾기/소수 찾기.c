#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int count = n;
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
        if(a[i]==1)
            count -= 1;
        for(j=2;j<a[i];j++){
            if(a[i]%j==0){
                count -= 1;
                break;
            }
        }
    }
    printf("%d", count);
}