#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int h, w, n, i, room, floor;
    for(i=0;i<t;i++){
        scanf("%d %d %d", &h, &w, &n);
        floor = n%h;
        room = n/h+1;
        if(floor==0){
        	floor = h;
        	room = n/h;
        }
        printf("%d\n", 100*floor+room);
		}
        
}