#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
    
int N, M;
char map[501][501];
int cache[501][501];

bool escape(int y, int x) {
    if(y<0 || y>=N || x<0 || x>=M) return true;
    return false;
}

int move(int y, int x);

int canEscape(int y, int x) {
    if(escape(y, x)) return 1;
    
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    ret = 0;
    
    ret = move(y, x);
    return ret;
}

int move(int y, int x) {
    char dir = map[y][x];
    if(dir=='U') return canEscape(y-1, x);
    if(dir=='D') return canEscape(y+1, x);
    if(dir=='R') return canEscape(y, x+1);
    if(dir=='L') return canEscape(y, x-1);
    
    return -100;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)    
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    memset(cache, -1, sizeof(cache));
    int cnt = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(canEscape(i, j)==1) cnt++;
    
    cout<<cnt;
}