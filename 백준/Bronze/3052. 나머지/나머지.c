#include <stdio.h>

int main()
{
    int num[10], i, j, remain[10], type;
    type = 0;
    for(i=0;i<10;i++)
        scanf("%d", &num[i]);
    for(i=0;i<10;i++)
        remain[i]=num[i]%42;
    for(i=0;i<10;i++){
        for(j=0;j<i;j++){
            if(remain[i]==remain[j]){
                type -= 1;
                break;
            }
        }
        type += 1;
    }
    printf("%d", type);
}