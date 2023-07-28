#include <stdio.h>
#include <string.h>

int main()
{
    int t, i, repeat, j, k;
    scanf("%d", &t);
    char s[20];
    for(i=0;i<t;i++){
        scanf("%d", &repeat);
        scanf("%s", &s);
        for(j=0;j<strlen(s);j++){
            for(k=0;k<repeat;k++)
                printf("%c", s[j]);
        }
        printf("\n");
    }
}