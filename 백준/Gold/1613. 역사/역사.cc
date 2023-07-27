#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 401
#define INF 987654321
int N, M;
int adj[MAX_N][MAX_N];

void floyd() {
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
    int s;
    cin>>s;
    vector<int> answer;
    for(int i=0;i<s;i++) {
        cin>>a>>b;
        if(adj[a-1][b-1]!=INF) answer.push_back(-1);
        else if(adj[b-1][a-1]!=INF) answer.push_back(1);
        else answer.push_back(0);
    }
    
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<"\n";
}