#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int MAX_N = 501;
const int INF = 987654321;
int adj[MAX_N][MAX_N];

void floyd() {
    for(int k=0;k<N;k++) 
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            adj[i][j] = INF;
    int a, b;
    for(int i=0;i<M;i++) {
        cin>>a>>b;
        adj[a-1][b-1] = 1;
    }
    floyd();
    int cnt = 0;
    for(int i=0;i<N;i++) {
        bool ok = true;
        for(int j=0;j<N;j++) {
            if(i!=j && (adj[i][j]==INF && adj[j][i]==INF)) ok = false;
            if(!ok) break;
        }
        if(ok) cnt++;
    }
    cout<<cnt;
}