#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> visited;
int answer = 0;

void dfs(int x, int y) {
    visited[y][x] = true;
    //상하좌우만 순회
    if(y-1>=0 && adj[y-1][x] == 1 && !visited[y-1][x]) {
            visited[y-1][x] = true;
            dfs(x, y-1);
    }
    if(y+1<adj.size() && adj[y+1][x] == 1 && !visited[y+1][x]) {
            visited[y+1][x] = true;
            dfs(x, y+1);
    }
    if(x-1>=0 && adj[y][x-1] == 1 && !visited[y][x-1]) {
            visited[y][x-1] = true;
            dfs(x-1, y);
    }
    if(x+1<adj[0].size() && adj[y][x+1] == 1 && !visited[y][x+1]) {
            visited[y][x+1] = true;
            dfs(x+1, y);
    }
}

void dfsAll() {
    for(int i=0;i<adj.size();i++) {
        for(int j=0;j<adj[i].size();j++) {
            if(!visited[i][j] && adj[i][j]==1) {
                answer++;
                dfs(j, i);
            }
        }
    }
}

int main() {
    int C, M, N, K;
    cin>>C;
    for(int c=0;c<C;c++) {
        cin>>M>>N>>K;
        answer = 0;
        adj = vector<vector<int>>(N, vector<int>(M, 0));
        visited = vector<vector<int>>(N, vector<int>(M, 0));
        int x, y;
        for(int i=0;i<K;i++) {
            cin>>x>>y;
            adj[y][x] = 1;
        }
        dfsAll();
        cout<<answer<<endl;
    }
}