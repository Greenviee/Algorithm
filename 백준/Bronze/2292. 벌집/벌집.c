#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int time, i, num;
    time = 1;
    num = 1;
    for(i=0;i<n;i++){
        if(n<=6*i+num)
            break;
        else{
            time++;
            num = 6*i+num;
        }
    }
    printf("%d", time);
}