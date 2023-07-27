#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
const int MAX_N = 101;
const int INF = 987654321;
int adj[MAX_N][MAX_N];

void floyd() {
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>adj[i][j];
            if(adj[i][j]==0) adj[i][j] = INF;
        }
    }
    floyd();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(adj[i][j]==INF) cout<<0<<' ';
            else cout<<1<<' ';
        }
        cout<<endl;
    }
}