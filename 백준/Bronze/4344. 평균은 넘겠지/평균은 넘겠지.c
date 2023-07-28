#include <stdio.h>

int main()
{
    int c, i, j, count;
    scanf("%d", &c);
    int num, sum, grade[1000];
    double average, percent;
    
    for(i=0;i<c;i++){
        scanf("%d", &num);
        sum = 0;
        count = 0;
        for(j=0;j<num;j++){
            scanf("%d", &grade[j]);
            sum += grade[j];
        }
        average = (double)sum/(double)num;
        for(j=0;j<num;j++){
            if(grade[j]>average)
                count += 1;
        }
        percent = (double)count/(double)num*100;
        printf("%.3f%%\n", percent);
    }
}