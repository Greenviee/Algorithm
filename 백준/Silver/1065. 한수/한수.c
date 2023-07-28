#include <stdio.h>

int arith(int num);

int main()
{
    int n, i, count;
    count = 0;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        if(i<100)
            count += 1;
        else{
            if(arith(i)==1)
                count += 1;
        }
    }
    printf("%d", count);
}

int arith(int num)
{
    int a, b, c;
    a = num%10;
    b = (num%100)/10;
    c = num/100;
    if(2*b-a-c==0)
        return 1;
    else
        return 0;
}