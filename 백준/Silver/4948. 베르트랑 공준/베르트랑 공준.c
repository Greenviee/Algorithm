#include <stdio.h>

int main()
{
    int n, x;
    int i, j, count;
    x = 0;
    while(1){
    scanf("%d", &n);
    if(n==0)
    	exit(0);
	for(i=n+1;i<=2*n;i++){                
		for(j=2;j*j<=i;j++){
			if(i%j==0){
                x = 1;
				break;
			}
		}
        if(x==0&&i!=1)
            count += 1;
        x = 0;
	}  
	printf("%d\n", count);
	count = 0;
}
}