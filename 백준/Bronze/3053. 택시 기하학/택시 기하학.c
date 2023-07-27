#include <stdio.h>

int main()
{
	int r;
	double s;
	scanf("%d", &r);
	double pi = 3.141592653589;
	printf("%.6f\n", r*r*pi);
	printf("%.6f", (double)r*(double)r*2);
}