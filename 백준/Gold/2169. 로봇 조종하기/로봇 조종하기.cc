#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 987654321;
int N, M;
int map[1001][1001];
int cache[1001][1001][3];
int dir_x[3] = {-1, 1, 0};
int dir_y[3] = {0, 0, 1};

int mars(int y, int x, int dir) {
    if(y==N && x==M) return map[y][x];
    int& ret = cache[y][x][dir];
    if(ret!=INF) return ret;
    ret = -INF;
    
    for(int i=0;i<3;i++) {
        if(dir==0 && i==1 || dir==1 && i==0) continue;
        int new_y = y + dir_y[i];
        int new_x = x + dir_x[i];
        if((1<=new_y && new_y<=N) && (1<=new_x && new_x<=M)) 
            ret = max(ret, map[y][x] + mars(new_y, new_x, i));
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=1;i<=N;i++)  
        for(int j=1;j<=M;j++)
            for(int k=0;k<3;k++)
                cache[i][j][k] = INF;
            
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>map[i][j];
    int answer = mars(1, 1, 2);
    cout<<answer;
}