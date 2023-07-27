#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(b>=c){
    	printf("-1");
    	exit(0);
    }
	double x = (double)a/(double)(c-b);
	int point;
	point = x/1 + 1;
	printf("%d", point);
}