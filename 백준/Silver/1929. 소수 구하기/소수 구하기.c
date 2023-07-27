#include <stdio.h>
#include <math.h>

int main()
{
    int m, n, x;
    scanf("%d %d", &m, &n);
    int i, j;
    x = 0;
	for(i=m;i<=n;i++){                
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				x = 1;
				break;
			}
		}
		if(x==0&&i!=1)
		printf("%d\n", i);
		x = 0;
	}
}