#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int INF = 987654321;
int map[8][8];
int dir_x[8] = {0, 1, 0, -1, 0, 1, 0, -1};
int dir_y[8] = {-1, 0, 1, 0, -1, 0, 1, 0};

void viewmap() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

//sign==-1이면 사각지대 표시, sign==1이면 해제
void checkcctv(int y, int x, int dir, int sign) {
    if(map[y][x]==1) {
        for(int k=0;k<10;k++) {
            x += dir_x[dir];
            y += dir_y[dir];
            if((x>=M || x<0) || (y>=N || y<0)) break;
            if(map[y][x]==6) break;
            else if(map[y][x]<=0) map[y][x]+=sign;
        }
    }
    
    else if(map[y][x]==2) {
        int x1 = x, x2 = x;
        int y1 = y, y2 = y;
        while(1) {
            x1 += dir_x[dir];
            y1 += dir_y[dir];
            if((x1>=M || x1<0) || (y1>=N || y1<0)) break;
            if(map[y1][x1]==6) break;
            else if(map[y1][x1]<=0) map[y1][x1]+=sign;
        }
        while(1) {
            x2 += dir_x[dir+2];
            y2 += dir_y[dir+2];
            if((x2>=M || x2<0) || (y2>=N || y2<0)) break;
            if(map[y2][x2]==6) break;
            else if(map[y2][x2]<=0) map[y2][x2]+=sign;
        }
    }
    
    else if(map[y][x]==3) {
        int x1 = x, x2 = x;
        int y1 = y, y2 = y;
        while(1) {
            x1 += dir_x[dir];
            y1 += dir_y[dir];
            if((x1>=M || x1<0) || (y1>=N || y1<0)) break;
            if(map[y1][x1]==6) break;
            else if(map[y1][x1]<=0) map[y1][x1]+=sign;
        }
        while(1) {
            x2 += dir_x[dir+1];
            y2 += dir_y[dir+1];
            if((x2>=M || x2<0) || (y2>=N || y2<0)) break;
            if(map[y2][x2]==6) break;
            else if(map[y2][x2]<=0) map[y2][x2]+=sign;
        }
    }
    
    else if(map[y][x]==4) {
        for(int i=0;i<3;i++) {
            int new_x = x, new_y = y;
            while(1) {
                new_x += dir_x[dir+i];
                new_y += dir_y[dir+i];
                if((new_x>=M || new_x<0) || (new_y>=N || new_y<0)) break;
                if(map[new_y][new_x]==6) break;
                else if(map[new_y][new_x]<=0) map[new_y][new_x]+=sign;
            }
        }
    }
    
    else if(map[y][x]==5) {
        for(int i=0;i<4;i++) {
            int new_x = x, new_y = y;
            while(1) {
                new_x += dir_x[dir+i];
                new_y += dir_y[dir+i];
                if((new_x>=M || new_x<0) || (new_y>=N || new_y<0)) break;
                if(map[new_y][new_x]==6) break;
                else if(map[new_y][new_x]<=0) map[new_y][new_x]+=sign;
            }
        }
    }
}

int findblindspot() {
    int blind = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(map[i][j]==0) blind++;
    return blind;
}

int cctv() {
    int x = -1, y = -1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j]>0 && map[i][j]<100 && map[i][j]!=6) {
                x = j;
                y = i;
                break;
            }
        }
        if(x!=-1) break;
    }
    
    if(x==-1) return findblindspot();
    
    int ret = INF;
    for(int i=0;i<4;i++) {
        checkcctv(y, x, i, -1);
        map[y][x] += 1000;
        ret = min(ret, cctv());
        map[y][x] -= 1000;
        checkcctv(y, x, i, 1);
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    
    int answer = cctv();
    cout<<answer;
}