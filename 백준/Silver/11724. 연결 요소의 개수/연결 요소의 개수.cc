#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int answer = 0;

void dfs(int here) {
    visited[here] = true;
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(!visited[there]) 
            dfs(there);
    }
}

void dfsAll() {
    for(int i=1;i<adj.size();i++) {
        if(!visited[i]) {
            answer++;
            dfs(i);
        }
    }
}

int main() {
    int N, M, n1, n2;
    cin>>N>>M;
    adj = vector<vector<int>>(N+1, vector<int>(0, 0));
    visited = vector<bool>(N+1, 0);
    for(int i=0;i<M;i++) {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    dfsAll();
    cout<<answer<<endl;
}