#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
string map[50];
int dist[50][50];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int bfs(int _y, int _x) {
    dist[_y][_x] = 0;
    int len = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(_y, _x));
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int new_y = y + dir_y[i];
            int new_x = x + dir_x[i];
            if((0<=new_y && new_y<N) && (0<=new_x && new_x<M) && map[new_y][new_x]=='L' && dist[new_y][new_x]==-1) {
                dist[new_y][new_x] = dist[y][x] + 1;
                len = max(len, dist[new_y][new_x]);
                q.push(make_pair(new_y, new_x));
            }
        }
    }
    return len;
}

int treasure() {
    int answer = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j]=='L') {
                memset(dist, -1 ,sizeof(dist));
                answer = max(answer, bfs(i, j));
            }
        }
    }
    return answer;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>map[i];
        
    int answer = treasure();
    cout<<answer;
}