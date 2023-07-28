#include <stdio.h>

int main()
{
    int num, cycle;
    scanf("%d", &num);
    int a = num;
    cycle = 0;
    do{
        if(num<10){
            num = num*11;
            cycle += 1;}
        else{
            num = (num%10)*10+(num/10+num%10)%10;
            cycle += 1;}
    } while(a != num);
    printf("%d\n", cycle);
}