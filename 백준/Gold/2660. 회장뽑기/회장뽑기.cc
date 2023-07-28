#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 51
#define INF 987654321
int N;
int adj[MAX_N][MAX_N];

void floyd() {
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            adj[i][j] = INF;
    
    int a, b;
    while(1) {
        cin>>a>>b;
        if(a==-1) break;
        adj[a-1][b-1] = 1;
        adj[b-1][a-1] = 1;
    }
    
    floyd();
    int point[N];
    int president = INF;
    for(int i=0;i<N;i++) {
        int p = 0;
        for(int j=0;j<N;j++) {
            if(i!=j) p = max(p, adj[i][j]);
        }
        point[i] = p;
        president = min(president, p);
    }
    
    vector<int> answer;
    for(int i=0;i<N;i++) 
        if(point[i]==president) answer.push_back(i+1);
        
    cout<<president<<' '<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<' ';
}