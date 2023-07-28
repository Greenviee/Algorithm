#include <stdio.h>

int main()
{
	int t, i, n, j, k, s, p, half;
	int num1, num2, n_1, n_2;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n);
		half = n/2;
		int a[n];
		s = 0;
		p = 0;
		num1 = num2 = 0;
		for(j=2;j<=n;j++){
			for(k=2;k*k<=j;k++){
				if(j%k==0){
					s = 1;
					break;
				}
			}
			if(s==0){
				a[p] = j;
				p++;
			}
			s = 0;
		}
		while(a[k]<half)
			k++;
		n_1 = k;
		num1  = a[k];
		half = n/2;
		k = p-1;
		while(a[k]>half)
			k--;
		n_2 = k;
		num2 = a[k];
		while(num1+num2!=n){
			if(num1+num2>n){
				num1 = a[n_1-1];
				n_1--;
			}
			else{
				num2 = a[n_2+1];
				n_2++;
			}
		}
		if(num1>=num2)
			printf("%d %d\n", num2, num1);
		else
			printf("%d %d\n", num1, num2);
	}
}