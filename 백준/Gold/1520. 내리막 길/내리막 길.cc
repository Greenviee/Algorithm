#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int M, N;
int map[501][501];
//cache[y][x] = (x, y)에서 목적지까지 갈 수 있는 경로 개수
int cache[501][501];

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int route(int y, int x) {
    if(y==M-1 && x==N-1) return 1;
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=0;i<4;i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        if((new_x>=0 && new_x<N) && (new_y>=0 && new_y<M) && map[y][x] > map[new_y][new_x]) {
            ret += route(new_y, new_x);
        }
    }
    return ret;
}

int main() {
    cin>>M>>N;
    for(int i=0;i<M;i++) 
        for(int j=0;j<N;j++) 
            cin>>map[i][j];
    memset(cache, -1, sizeof(cache));
    int answer = route(0, 0);
    cout<<answer;
}