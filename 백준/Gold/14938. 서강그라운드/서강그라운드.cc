#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, r;
const int MAX_N = 501;
const int INF = 987654321;
int adj[MAX_N][MAX_N];

void floyd() {
    for(int i=0;i<N;i++) adj[i][i] = 0;
    for(int k=0;k<N;k++) 
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}

int main() {
    cin>>N>>r>>M;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            adj[i][j] = INF;
            
    vector<int> items;
    int n;
    for(int i=0;i<N;i++) {
        cin>>n;
        items.push_back(n);
    }
    int a, b, t;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>t;
        adj[a-1][b-1] = t;
        adj[b-1][a-1] = t;
    }
    floyd();
    int answer = 0;
    
    for(int i=0;i<N;i++) {
        int item = 0;
        for(int j=0;j<N;j++) {
            if(adj[i][j] <= r) item += items[j];
        }
        answer = max(answer, item);
    }
    cout<<answer;
}