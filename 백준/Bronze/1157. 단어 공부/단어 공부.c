#include <stdio.h>
#include <string.h>

int main()
{
    char word[1000000];
    int count[26] = {0};
    int num[26];
    int i, j;
    for(i=0;i<26;i++)
        num[i] = i;
    scanf("%s", &word);
    int len = strlen(word);
    for(i=0;i<len;i++){
        for(j=0;j<26;j++){
            if(word[i]==num[j]+65||word[i]==num[j]+97){
                count[j] += 1;
                break;
            }
        }
    }
	int max = 0;
	int x;
	for(i=0;i<26;i++){
		if(max<count[i]){
			max = count[i];
			x = i;
		}
	}
	for(i=0;i<26;i++){
		if(count[x]==count[i]&&x!=i){
			printf("?");
			exit(0);
		}
	}
	printf("%c", x+65);
}
