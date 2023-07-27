#include <stdio.h>
int main (){
    char sentence[1000000];
    scanf("%[^\n]s", &sentence);
    int blank = 0, i = 1;

    do
    {
        if(sentence[i] == 32)
            if (sentence[i+1] == 0 || sentence[i+1] == 32);
            else
                blank++;
        i++;
    } while (sentence[i] != 0);

    if (strlen(sentence)!=1||sentence[0]!=32)
        blank++;

    printf("%d", blank);
}
