#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int maze[101][101];
int visited[101][101];
int dist[101][101];

int x_dir[4] = {1, 0, -1, 0};
int y_dir[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void bfs(int start_x, int start_y) {
    visited[start_x][start_y] = 1;
    q.push(make_pair(start_x, start_y));
    dist[start_x][start_y]++;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];
            if((x_new>=0 && x_new<N) && (y_new>=0 && y_new<M) && visited[x_new][y_new]!=1 && maze[x_new][y_new]==1) {
                visited[x_new][y_new] = 1;
                q.push(make_pair(x_new, y_new));
                dist[x_new][y_new] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        string row;
        cin>>row;
        for(int j=0;j<M;j++) {
            maze[i][j] = row[j] - '0';
        }
    }
    bfs(0, 0);
    cout<<dist[N-1][M-1];
}