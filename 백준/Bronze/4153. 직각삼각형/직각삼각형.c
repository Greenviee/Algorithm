#include <stdio.h>

int main()
{
	int a, b, c, max;
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if(a==0&&b==0&&c==0)
			exit(0);
		if(a>=b)
			max = a;
		else
			max = b ;
		if(c>=max)
			max = c;
		if(max==a){
			if(a*a==b*b+c*c)
				printf("right\n");
			else
				printf("wrong\n");
		}
		if(max==b){
			if(b*b==a*a+c*c)
				printf("right\n");
			else
				printf("wrong\n");
		}
		if(max==c){
			if(c*c==a*a+b*b)
				printf("right\n");
			else
				printf("wrong\n");
		}
	}
}