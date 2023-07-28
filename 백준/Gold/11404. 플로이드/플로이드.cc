#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int INF = 987654321;
const int MAX_N = 101;
int adj[MAX_N][MAX_N];

void floyd() {
    for(int i=0;i<N;i++) adj[i][i] = 0;
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) 
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) adj[i][j] = INF;
    int a, b, c;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>c;
        if(adj[a-1][b-1]>c) 
            adj[a-1][b-1] = c;
    }
    floyd();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(adj[i][j]==INF) cout<<0<<' ';
            else cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
}