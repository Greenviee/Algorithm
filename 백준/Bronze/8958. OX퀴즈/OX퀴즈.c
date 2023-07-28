#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, score, f_score;
    scanf("%d", &n);
    char ox[80];
    for(i=0;i<n;i++){
        scanf("%s", &ox);
        score = 0;
        f_score = 0;
        for(j=0;j<strlen(ox);j++){

            if(ox[j]=='O'){
                if(ox[j-1]=='O'){
                    score += 1;
                    f_score += score;
                }
                else{
                    score = 1;
                    f_score += score;
                }
            }
            else
                score = 0;
            
        }
        printf("%d\n", f_score);
    }
}