#include <stdio.h>

int main()
{
	int x, y, w, h, distance_x, distance_y;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	if(x<=w-x)
		distance_x = x;
	else
		distance_x = w - x;
	
	if(y<=h-y)
		distance_y = y;
	else
		distance_y = h - y;
	
	if(distance_x<=distance_y)
		printf("%d", distance_x);
	else
		printf("%d", distance_y);		
}