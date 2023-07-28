#include <stdio.h>

int main()
{
    int n;
    double max;
    max = 0;
    scanf("%d", &n);
    int grade[n], i;
    double f_grade[n], sum;
    sum = 0;
    for(i=0;i<n;i++)
        scanf("%d", &grade[i]);
    for(i=0;i<n;i++){
        if(max < grade[i])
            max = grade[i];
    }
    for(i=0;i<n;i++){
        if(grade[i]==max)
            f_grade[i]=100;
        else
            f_grade[i]=(double)grade[i]/max*100;
    }
    for(i=0;i<n;i++)
        sum += f_grade[i];
    double avg = sum/(double)n;
    printf("%.2f", avg);
}