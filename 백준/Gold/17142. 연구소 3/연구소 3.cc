#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[50][50];
int dist[50][50];
const int INF = 987654321;
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int infection() {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> virus;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j]==3) {
                virus.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    int t = 0;
    while(!virus.empty()) {
        int y = virus.front().first;
        int x = virus.front().second;
        virus.pop();
        for(int i=0;i<4;i++) {
            int new_y = y + dir_y[i];
            int new_x = x + dir_x[i];
            if((0<=new_y && new_y<N) && (0<=new_x && new_x<N) && (map[new_y][new_x]==0 || map[new_y][new_x]==2) && dist[new_y][new_x]==-1) {
                dist[new_y][new_x] = dist[y][x] + 1;
                if(map[new_y][new_x]==0) t = max(t, dist[new_y][new_x]);
                virus.push(make_pair(new_y, new_x));
            }
        }
    }
    
    bool done = true;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j]==0 && dist[i][j]==-1) {
                done = false;
                break;
            }
        }
        if(!done) break;
    }
    if(!done) return INF;
    else return t;
}

int lab(int y, int x, int cnt) {
    if(cnt==M) return infection();
    
    int ret = INF;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if((i>y || (i==y && j>x)) && map[i][j]==2) {
                //활성 바이러스는 3으로 표시
                map[i][j] = 3;
                ret = min(ret, lab(i, j, cnt+1));
                map[i][j] = 2;
            }
        }
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
    
    int answer = lab(-1, -1, 0);
    if(answer==INF) cout<<-1;
    else cout<<answer;
}