#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> adj;
vector<vector<bool>> visited;
int answer = 0;

void dfs(int x, int y) {
    visited[x][y] = true;
    char color = adj[x][y];
    //상하좌우만 순회
    if(y-1>=0 && adj[x][y-1] == color && !visited[x][y-1]) {
            visited[x][y-1] = true;
            dfs(x, y-1);
    }
    if(y+1<adj.size() && adj[x][y+1] == color && !visited[x][y+1]) {
            visited[x][y+1] = true;
            dfs(x, y+1);
    }
    if(x-1>=0 && adj[x-1][y] == color && !visited[x-1][y]) {
            visited[x-1][y] = true;
            dfs(x-1, y);
    }
    if(x+1<adj.size() && adj[x+1][y] == color && !visited[x+1][y]) {
            visited[x+1][y] = true;
            dfs(x+1, y);
    }
}

void dfsAll() {
    for(int i=0;i<adj.size();i++) {
        for(int j=0;j<adj.size();j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                answer++;
            }
        }
    }
}

int main() {
    int N;
    cin>>N;
    char color;
    adj = vector<vector<char>>(N, vector<char>(N, 0));
    visited = vector<vector<bool>>(N, vector<bool>(N, 0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>color;
            adj[i][j] = color;
        }
    }
    dfsAll();
    int a1 = answer;
    answer = 0;
    visited = vector<vector<bool>>(N, vector<bool>(N, 0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(adj[i][j]=='G') adj[i][j] = 'R';
        }
    }
    dfsAll();
    int a2 = answer;
    cout<<a1<<' '<<a2;
}