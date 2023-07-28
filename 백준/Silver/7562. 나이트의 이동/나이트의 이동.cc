#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int I;
int dist[301][301];
queue<pair<int, int>> q;
int dir_x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dir_y[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(int start_x, int start_y, int goal_x, int goal_y) {
    dist[start_x][start_y] = 0;
    q.push(make_pair(start_x, start_y));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if(x==goal_x && y==goal_y) {
            while(!q.empty()) q.pop();
            return dist[x][y];
        }
        q.pop();
        for(int i=0;i<8;i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if((0<=new_x && new_x<I) && (0<=new_y && new_y<I) && dist[new_x][new_y]==-1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int main() {
    int kx, ky, goal_x, goal_y;
    int C;
    cin>>C;
    for(int c=0;c<C;c++) {
        memset(dist, -1, sizeof(dist));
        cin>>I>>kx>>ky>>goal_x>>goal_y;
        int answer = bfs(kx, ky, goal_x, goal_y);
        cout<<answer<<endl;
    }
}