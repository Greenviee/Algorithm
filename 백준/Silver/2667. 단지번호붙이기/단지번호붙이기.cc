#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> visited;
int answer = 0;
vector<int> housecnt;

void dfs(int x, int y) {
    visited[x][y] = true;
    answer++;
    //상하좌우만 순회
    if(y-1>=0 && adj[x][y-1] == 1 && !visited[x][y-1]) {
            visited[x][y-1] = true;
            dfs(x, y-1);
    }
    if(y+1<adj.size() && adj[x][y+1] == 1 && !visited[x][y+1]) {
            visited[x][y+1] = true;
            dfs(x, y+1);
    }
    if(x-1>=0 && adj[x-1][y] == 1 && !visited[x-1][y]) {
            visited[x-1][y] = true;
            dfs(x-1, y);
    }
    if(x+1<adj.size() && adj[x+1][y] == 1 && !visited[x+1][y]) {
            visited[x+1][y] = true;
            dfs(x+1, y);
    }
}

void dfsAll() {
    for(int i=0;i<adj.size();i++) {
        for(int j=0;j<adj.size();j++) {
            if(!visited[i][j] && adj[i][j]==1) {
                answer = 0;
                dfs(i, j);
                if(answer!=0) housecnt.push_back(answer);
            }
        }
    }
}

int main() {
    int N;
    string num;
    cin>>N;
    adj = vector<vector<int>>(N, vector<int>(N, 0));
    visited = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i=0;i<N;i++) {
        cin>>num;
        for(int j=0;j<N;j++) {
            int n = num[j] - '0';
            adj[i][j] = n;
        }
    }
    dfsAll();
    sort(housecnt.begin(), housecnt.end());
    cout<<housecnt.size()<<endl;
    for(int i=0;i<housecnt.size();i++) {
        cout<<housecnt[i]<<endl;
    }
}