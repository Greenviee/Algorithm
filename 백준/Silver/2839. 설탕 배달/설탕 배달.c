#include <stdio.h>

int main()
{
	int three, five, kg, i, x, num;
	i = 0;
	x = 0;
	num = 0;
	scanf("%d", &kg);
	while(kg>=0){
		if((kg%5)%3==0){
			five = kg/5;
			three = (kg%5)/3;
			num = three + five + x;
		}
		else if(kg%3==0){
			three = kg/3;
			num = three + x;
		}
		kg -= 5;
		x += 1;
	}
	if(num!=0)
		printf("%d", num);
	else
		printf("%d", -1);

}