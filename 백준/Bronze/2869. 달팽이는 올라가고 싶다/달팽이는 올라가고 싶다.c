#include <stdio.h>

int main()
{
    int a, b, v, i;
    int velocity, time;
    i = 0;
    time = 0;		
    scanf("%d %d %d", &a, &b, &v);
    velocity = a - b;
    time = (v-a)/velocity;
    if((v-a)%velocity!=0)
    	time += 1;
    if((v-a)<velocity)
    	time = 1;
	if(v==a)
		time = 0;
    printf("%d", time+1);
}
