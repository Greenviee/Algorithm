#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int garden[1001][1001];
int dist[1001][1001];
int visited[1001][1001];

int x_dir[4] = {1, -1, 0, 0};
int y_dir[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(vector<int>& riped_x, vector<int>& riped_y) {
    for(int i=0;i<riped_x.size();i++) {
        visited[riped_x[i]][riped_y[i]] = 1;
        q.push(make_pair(riped_x[i], riped_y[i]));
        dist[riped_x[i]][riped_y[i]] = 0;
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int new_x = x + x_dir[i];
            int new_y = y + y_dir[i];
            if((new_x>=0 && new_x<M) && (new_y>=0 && new_y<N) && visited[new_x][new_y]!=1 && garden[new_x][new_y]==0) {
                visited[new_x][new_y] = 1;
                q.push(make_pair(new_x, new_y));
                garden[new_x][new_y] = 1;
                if(dist[new_x][new_y]!=-1) dist[new_x][new_y] = min(dist[new_x][new_y], dist[x][y] + 1);
                else dist[new_x][new_y] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
    vector<int> riped_x;
    vector<int> riped_y;
    cin>>M>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin>>garden[j][i];
            if(garden[j][i]==1) {
                riped_x.push_back(j);
                riped_y.push_back(i);
            }
            else if(garden[j][i]==-1) {
                dist[j][i] = -11;
            }
        }
    }
    bfs(riped_x, riped_y);
    int days = 0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(dist[j][i]==-1) {
                days = -1;
                break;
            }
            days = max(days, dist[j][i]);
        }
        if(days==-1) break;
    }
    
    cout<<days;
}
