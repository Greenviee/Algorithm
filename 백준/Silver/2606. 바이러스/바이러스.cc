#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int answer = 0;

void dfs(int here) {
    visited[here] = true;
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(!visited[there]) {
            dfs(there);
            answer++;
        }
    }
}

int main() {
    int N, C;
    cin>>C>>N;
    adj = vector<vector<int>>(C+1, vector<int>(C+1, 0));
    int c1, c2;
    for(int i=0;i<N;i++) {
        cin>>c1>>c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    visited = vector<bool>(C+1, 0);
    dfs(1);
    cout<<answer-1;
}