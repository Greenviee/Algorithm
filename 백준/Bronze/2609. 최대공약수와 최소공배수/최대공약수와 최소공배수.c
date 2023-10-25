#include <stdio.h>

int gcd(int a, int b) {
	if (a == b)
		return a;
	else if (a > b)
		return gcd(b, a);
	else
		return gcd(a, b-a);
}

int main() {
	int a, b;
	int GCD, LCM;
	scanf("%d %d", &a, &b);
	GCD = gcd(a, b);
	LCM = a * b / GCD;
	printf("%d\n%d", GCD, LCM);
}