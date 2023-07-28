#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> DFS;

void dfs(int here) {
    visited[here] = true;
    DFS.push_back(here);
    sort(adj[here].begin(), adj[here].end());
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(!visited[there]) dfs(there);
    }
}

vector<int> bfs(int start) {
    vector<bool> discovered(adj.size(), false);
    queue<int> q;
    vector<int> order;
    discovered[start] = true;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        order.push_back(here);
        sort(adj[here].begin(), adj[here].end());
        for(int i=0;i<adj[here].size();i++) {
            int there = adj[here][i];
            if(!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    return order;
}

int main() {
    int N, M, V;
    cin>>N>>M>>V;
    adj = vector<vector<int>>(N, vector<int>());
    visited = vector<bool>(N, 0);
    int n1, n2;
    for(int i=0;i<M;i++) {
        cin>>n1>>n2;
        adj[n1-1].push_back(n2-1);
        adj[n2-1].push_back(n1-1);
    }
    dfs(V-1);
    vector<int> BFS = bfs(V-1);
    for(int i=0;i<DFS.size();i++) 
        cout<<DFS[i]+1<<" ";
    cout<<endl;
    for(int i=0;i<BFS.size();i++) 
        cout<<BFS[i]+1<<" ";
}