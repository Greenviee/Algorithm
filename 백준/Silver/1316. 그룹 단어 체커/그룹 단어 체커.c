#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k, count, temp;
    count = 0;
    temp = 0;
    scanf("%d", &n);
    char word[100];
    for(i=0;i<n;i++){
        scanf("%s", &word);
        int len = strlen(word);
        for(j=0;j<len;j++){
            if(word[j]!=word[j+1]){
                for(k=j+1;k<len;k++){
                    if(word[j]==word[k]&&temp==0){
                    	count -= 1;
                    	temp = 1;
					}
                }
            }
        }
        count += 1;
        temp = 0;
    }
    printf("%d", count);
}