#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int V, E;
const int MAX_V = 401;
const int INF = 987654321;
int adj[MAX_V][MAX_V];

void floyd() {
    for(int k=0;k<V;k++) 
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++) 
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
    cin>>V>>E;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j] = INF;
            
    int a, b, t;
    for(int i=0;i<E;i++) {
        cin>>a>>b>>t;
        adj[a-1][b-1] = t;
    }
    floyd();
    int cycle = INF;
    for(int i=0;i<V;i++) 
        cycle = min(cycle, adj[i][i]);
        
    if(cycle==INF) cout<<-1<<endl;
    else cout<<cycle<<endl;
}