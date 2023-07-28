#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i, j, k, len;
	k = 0;
	if(n==1)
		exit(0);
	else if(n==2){
		a[0]=2;
		k++;
	}
	else if(n==3){
		a[0]=2;
		a[1]=3;
		k+=2;
	}
	for(i=2;i*i<=n;i++){                //sqrt(n) 이전 소수 구하기  
		for(j=2;j*j<=n;j++){
			if(i%j==0&&i==j){
				a[k] = i;
				k++;
				break;
			}
			else if(i%j==0&&i!=j)
				break;
		}
	}
	for(i=0;i<k;i++){
		if(n%a[i]==0&&n!=a[i]){
			n = n/a[i];
			printf("%d\n", a[i]);
			i = -1;
		}
		else if(n%a[i]==0&&n==a[i]){
			printf("%d\n", a[i]);
			exit(0);
		}
		else if(i==k-1){
		printf("%d\n", n);
			exit(0);
		}
	}
}
