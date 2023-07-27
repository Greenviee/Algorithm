#include <stdio.h>

int main()
{
    int i, a[9], max, count;
    for(i=0;i<9;i++){
        scanf("%d", &a[i]);
    }
    max = a[0], count = 1;
    for(i=0;i<9;i++){
        if(max < a[i])
            max = a[i];
    }
    for(i=0;i<9;i++){
        if(a[i]==max)
            break;
        else
            count += 1;
    }
    printf("%d\n", max);
    printf("%d", count);
}