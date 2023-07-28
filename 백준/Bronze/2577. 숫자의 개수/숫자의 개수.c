#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c, i, temp;
    char s1[20];
    int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    scanf("%d %d %d", &a, &b, &c);
    int result = a*b*c;
    temp = result;
    sprintf(s1, "%d", result);
    for(i=0;i<strlen(s1);i++){
        num[temp%10] += 1;
        temp = temp/10;
    }
    for(i=0;i<10;i++)
        printf("%d\n", num[i]);
}