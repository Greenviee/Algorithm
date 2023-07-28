#include <stdio.h>

int main()
{
    int x, y, i, n;
    scanf("%d", &n);
    int num;
    num = 1;
    i = 1;
    while(num<n){
    	num = num + 1 + i;
		i++;
	}
	int sum = i + 1;  // x+y=sum
	int count = num - n;
	if(sum%2==1){
		x = sum - 1 - count;
		y = 1 + count;
	} 
	else{
		x = 1 + count;
		y = sum - 1 - count;
	}
    printf("%d/%d", x, y);
}