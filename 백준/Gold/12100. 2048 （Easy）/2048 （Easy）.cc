//move함수에서 같은 수가 0으로 2칸 이상 떨어져 있으면 합쳐지지 않음

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
//map[i] = i번 이동한 상태
int map[6][20][20];
int a;

void mapview(int num) {
    cout<<endl;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout<<map[num][i][j]<<' ';
        cout<<endl;
    }
}

void move_up(int mapnum) {
    //map[mapnum] 초기화
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) 
            map[mapnum][i][j] = map[mapnum-1][i][j];
     
    for(int x=0;x<N;x++) {
        for(int y=0;y<N-1;y++) {
            if(map[mapnum][y][x]!=0 && map[mapnum][y][x]==map[mapnum][y+1][x]) {
                map[mapnum][y][x] *= 2;
                map[mapnum][y+1][x] = 0;
            }
            else if(map[mapnum][y][x]!=0 && map[mapnum][y+1][x]==0) {
                int new_y = y+1;
                while(new_y<N-1) {
                    new_y++;
                    if(map[mapnum][new_y][x]!=0) break;
                }
                if(map[mapnum][y][x]==map[mapnum][new_y][x]) {
                    map[mapnum][y][x] *= 2;
                    map[mapnum][new_y][x] = 0;
                }
            }
        }
    }
    
    for(int x=0;x<N;x++) {
        for(int y=0;y<N-1;y++) {
            if(map[mapnum][y][x]==0 && map[mapnum][y+1][x]!=0) {
                map[mapnum][y][x] = map[mapnum][y+1][x];
                map[mapnum][y+1][x] = 0;
                y-=2;
                if(y<0) y = -1;
            }
        }
    }
    
    // cin>>a;
    // cout<<endl;
    // cout<<"mapnum: "<<mapnum<<endl;
    // mapview(mapnum);
}

void move_down(int mapnum) {
    //map[mapnum] 초기화
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) 
            map[mapnum][i][j] = map[mapnum-1][i][j];
    
    for(int x=0;x<N;x++) {
        for(int y=N-1;y>0;y--) {
            if(map[mapnum][y][x]!=0 && map[mapnum][y][x]==map[mapnum][y-1][x]) {
                map[mapnum][y][x] *= 2;
                map[mapnum][y-1][x] = 0;
            }
            else if(map[mapnum][y][x]!=0 && map[mapnum][y-1][x]==0) {
                int new_y = y-1;
                while(new_y>0) {
                    new_y--;
                    if(map[mapnum][new_y][x]!=0) break;
                }
                if(map[mapnum][y][x]==map[mapnum][new_y][x]) {
                    map[mapnum][y][x] *= 2;
                    map[mapnum][new_y][x] = 0;
                }
            }
        }
    }
    
    for(int x=0;x<N;x++) {
        for(int y=N-1;y>0;y--) {
            if(map[mapnum][y][x]==0 && map[mapnum][y-1][x]!=0) {
                map[mapnum][y][x] = map[mapnum][y-1][x];
                map[mapnum][y-1][x] = 0;
                y+=2;
                if(y>N-1) y = N;
            }
        }
    }
    
    // cin>>a;
    // cout<<endl;
    // cout<<"mapnum: "<<mapnum<<endl;
    // mapview(mapnum);
}

void move_left(int mapnum) {
    //map[mapnum] 초기화
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) 
            map[mapnum][i][j] = map[mapnum-1][i][j];
    
    for(int y=0;y<N;y++) {
        for(int x=0;x<N-1;x++) {
            if(map[mapnum][y][x]!=0 && map[mapnum][y][x]==map[mapnum][y][x+1]) {
                map[mapnum][y][x] *= 2;
                map[mapnum][y][x+1] = 0;
            }
            else if(map[mapnum][y][x]!=0 && map[mapnum][y][x+1]==0) {
                int new_x = x+1;
                while(new_x<N-1) {
                    new_x++;
                    if(map[mapnum][y][new_x]!=0) break;
                }
                if(map[mapnum][y][x]==map[mapnum][y][new_x]) {
                    map[mapnum][y][x] *= 2;
                    map[mapnum][y][new_x] = 0;
                }
            }
        }
    }
    
    for(int y=0;y<N;y++) {
        for(int x=0;x<N-1;x++) {
            if(map[mapnum][y][x]==0 && map[mapnum][y][x+1]!=0) {
                map[mapnum][y][x] = map[mapnum][y][x+1];
                map[mapnum][y][x+1] = 0;
                x-=2;
                if(x<0) x = -1;
            }
        }
    }
    
    // cin>>a;
    // cout<<endl;
    // cout<<"mapnum: "<<mapnum<<endl;
    // mapview(mapnum);
}

void move_right(int mapnum) {
    //map[mapnum] 초기화
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) 
            map[mapnum][i][j] = map[mapnum-1][i][j];
     
    for(int y=0;y<N;y++) {
        for(int x=N-1;x>0;x--) {
            if(map[mapnum][y][x]!=0 && map[mapnum][y][x]==map[mapnum][y][x-1]) {
                map[mapnum][y][x] *= 2;
                map[mapnum][y][x-1] = 0;
            }
            else if(map[mapnum][y][x]!=0 && map[mapnum][y][x-1]==0) {
                int new_x = x-1;
                while(new_x>0) {
                    new_x--;
                    if(map[mapnum][y][new_x]!=0) break;
                }
                if(map[mapnum][y][x]==map[mapnum][y][new_x]) {
                    map[mapnum][y][x] *= 2;
                    map[mapnum][y][new_x] = 0;
                }
            }
        }
    }
    
    for(int y=0;y<N;y++) {
        for(int x=N-1;x>0;x--) {
            if(map[mapnum][y][x]==0 && map[mapnum][y][x-1]!=0) {
                map[mapnum][y][x] = map[mapnum][y][x-1];
                map[mapnum][y][x-1] = 0;
                x+=2;
                if(x>N-1) x = N;
            }
        }
    }
    
    // cin>>a;
    // cout<<endl;
    // cout<<"mapnum: "<<mapnum<<endl;
    // mapview(mapnum);
}

int maximum() {
    int num = 0;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++)
            num = max(num, map[5][i][j]);
    return num;
}

int solve(int N) {
    if(N==5) return maximum();
    
    int ret = 0;
    move_up(N+1);
    ret = max(ret, solve(N+1));
    move_down(N+1);
    ret = max(ret, solve(N+1));
    move_right(N+1);
    ret = max(ret, solve(N+1));
    move_left(N+1);
    ret = max(ret, solve(N+1));
    
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[0][i][j];
    
    int answer = solve(0);
    cout<<answer<<endl;
}
