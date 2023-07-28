#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> degree;
int N, M;
int oddpt = 0; int answer = 0;

void dfs(int here) {
    visited[here] = true;
    if(degree[here]%2==1) oddpt++;
    if(degree[here]==0) 
        answer--;
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(!visited[there]) 
            dfs(there);
    }
}

void dfsAll() {
    for(int i=1;i<adj.size();i++) {
        oddpt = 0;
        if(!visited[i]) {
            dfs(i);
            if(oddpt==0) answer++;
            else answer += oddpt/2;
        }
    }
}

int main() {
    cin>>N>>M;
    adj = vector<vector<int>>(N+1, vector<int>(0, 0));
    visited = vector<bool>(N+1, false);
    degree = vector<int>(N+1, 0);
    int u, v;
    for(int i=0;i<M;i++) {
        cin>>u>>v;
        adj[u].push_back(v); degree[u]++;
        adj[v].push_back(u); degree[v]++;
    }
    dfsAll();
    cout<<answer<<endl;
}