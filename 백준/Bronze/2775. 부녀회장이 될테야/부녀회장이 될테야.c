#include <stdio.h>

int main()
{
	int t, k, n, i, j, l;
	int person[100][15];
	for(i=1;i<15;i++){
		person[0][i] = i;
		person[i][0] = 0;
	}
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d", &k, &n);
		for(j=1;j<=k;j++){
			for(l=1;l<=n;l++){
				person[j][l] = person[j-1][l] + person[j][l-1];
			}
		}
		printf("%d\n", person[k][n]);
	}
}