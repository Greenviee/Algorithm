#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];
    int i, j;
    scanf("%s", &word);
    char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int count[26];
    for(i=0;i<27;i++)
        count[i] = -1;
    for(i=0;i<strlen(word);i++){
        for(j=0;j<27;j++){
            if(word[i]==alpha[j]){
            	if(count[j]==-1)
            		count[j] = i;
			}
        }
    }
    for(i=0;i<26;i++)
        printf("%d ", count[i]);
}