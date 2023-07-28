#include <stdio.h>

int self(int a);

int main()
{
	int num[10000];
	int i, x;
	x = 1;
	for(i=1;i<=10000;i++){
		num[i] = i;
	}
	num[1] = 0;
	printf("1\n");
	while(x<9993){
		for(i=1;i<=10000;i++){
			if(self(x)==num[i]){
				num[i] = 0;
				x = self(x);
			}
		}
		for(i=1;i<=10000;i++){
			if(num[i]!=0){
				printf("%d\n", num[i]);
				x = num[i];
				num[i] = 0;
				break;
			}
		}
	}	
}

int self(int a)
{
    int num, sum;
    num = a;
    sum = 0;
    do
    {
        sum += num%10;
        num = num/10;
    } while(num>0);
    return sum+a;
}