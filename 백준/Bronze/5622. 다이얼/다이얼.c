#include <stdio.h>
#include <string.h>

int main()
{
    char word[15];
    scanf("%s", &word);
    int i, time;
    time = 0;
    for(i=0;i<strlen(word);i++){
        if(word[i]<='C')
            time += 3;
        else if(word[i]<='F')
            time += 4;
        else if(word[i]<='I')
            time += 5;
        else if(word[i]<='L')
            time += 6;
        else if(word[i]<='O')
            time += 7;
        else if(word[i]<='S')
            time += 8;
        else if(word[i]<='V')
            time += 9;
        else if(word[i]<='Z')
            time += 10;
    }
    printf("%d", time);
}