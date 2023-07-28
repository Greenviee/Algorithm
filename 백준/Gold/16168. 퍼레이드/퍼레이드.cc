#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> degree;
vector<bool> visited;
vector<int> circuit;

void dfs(int here) {
    visited[here] = true;
    for(int i=0;i<adj[here].size();i++) {
        int n = adj[here][i];
        if(n!=0 && !visited[i]) 
            dfs(i);
    }
    circuit.push_back(here);
}

bool isEuler() {
    dfs(1);
    if(circuit.size() != V) return false;
    
    int a = 0;
    for(int i=1;i<adj.size();i++) 
        if(degree[i]%2==1) a++;
    if(a==0 || a==2) return true;
    else return false;
}

int main() {
    cin>>V>>E;
    int n1, n2;
    adj = vector<vector<int>>(V+1, vector<int>(V+1, 0));
    degree = vector<int>(V+1, 0);
    visited = vector<bool>(V+1, 0);
    for(int i=0;i<E;i++) {
        cin>>n1>>n2;
        adj[n1][n2]++; degree[n1]++;
        adj[n2][n1]++; degree[n2]++;
    }
    if(isEuler()) cout<<"YES";
    else cout<<"NO";
}