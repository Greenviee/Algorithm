#include <stdio.h>
#include <math.h>

int main()
{
	int x1, x2, y1, y2, r1, r2, t, i, small, large;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		double distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(r1>=r2){
			small = r2;
			large = r1;
		}
		else{
			small = r1;
			large = r2;
		}
		if(x1==x2&&y1==y2&&r1==r2)
			printf("-1\n");
		else if(distance>r1+r2||distance+small<large||distance==0)
			printf("0\n");
		else if(distance==r1+r2||distance+small==large)
			printf("1\n");
		else
			printf("2\n");
	}
}