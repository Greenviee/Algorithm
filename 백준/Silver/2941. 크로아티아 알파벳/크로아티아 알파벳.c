#include <stdio.h>
#include <string.h>

int main()
{
    char c[100];
    scanf("%s", &c);
    int i, count, len;
    count = 0;
    len = strlen(c);
    for(i=0;i<len;i++){
        if(c[i]=='c'){
        	if(c[i+1]=='='||c[i+1]=='-'){
        		count += 1;
        		i++;
			}
			else
				count += 1;
        }
        else if(c[i]=='d'){
            if(c[i+1]=='z'){
                if(c[i+2]=='='){
                	count += 1;
                	i += 2;
				}
				else{
					count += 1;
				}
            }
            else if(c[i+1]=='-'){
            	count += 1;
            	i++;
			}
			else
				count += 1;
        }
        else if(c[i]=='l'||c[i]=='n'){
        	if(c[i+1]=='j'){
        		count += 1;
        		i++;
			}
			else
				count += 1;
		}
		else if(c[i]=='s'||c[i]=='z'){
        	if(c[i+1]=='='){
        		count += 1;
        		i++;
			}
			else
				count += 1;
		}
		else
			count += 1;
    }
    printf("%d", count);
}