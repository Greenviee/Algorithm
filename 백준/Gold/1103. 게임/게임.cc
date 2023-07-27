#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N, M;
char board[51][51];
int cache[51][51];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int move(int y, int x, int cnt) {
    if(cnt>100000) return INF;
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    int movecount = 1;
    
    for(int i=0;i<4;i++) {
        int new_y = y + dir_y[i]*(board[y][x]-'0');
        int new_x = x + dir_x[i]*(board[y][x]-'0');
        if((0<=new_y && new_y<N) && (0<=new_x && new_x<M) && board[new_y][new_x]!='H') {
            movecount = max(movecount, 1 + move(new_y, new_x, cnt+1));
        }
    }
    ret = movecount;
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];
    memset(cache, -1, sizeof(cache));
    int answer = move(0, 0, 0);
    if(answer>INF) cout<<-1;
    else cout<<answer;
}