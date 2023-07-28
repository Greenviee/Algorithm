#include <stdio.h>

int main()
{
    int m, n, i, j, sum, x, min;
    sum = 0;
    min = 10000;
    scanf("%d %d", &m, &n);
    int count = 0;
    for(i=m;i<=n;i++){
        if(i!=1){
        	for(j=2;j<=i;j++){
            	if(i%j==0&&i==j){
            		count += 1;
            		if(i<min)
            			min = i;
            		sum += i;
				}
				else if(i%j==0&&i!=j)
					break;
        	}
    	}
    }
	if(sum==0){
		printf("-1");
		exit(0);
	}
    printf("%d \n%d", sum, min);
}