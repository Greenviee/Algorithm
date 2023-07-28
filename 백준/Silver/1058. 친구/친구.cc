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
    
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        for(int j=0;j<N;j++) 
            if(s[j]=='Y') adj[i][j] = 1; 
    }
    floyd();
    int answer = 0;
    for(int i=0;i<N;i++) {
        int two_friends = 0;
        for(int j=0;j<N;j++) 
            if(i!=j && adj[i][j]<=2) two_friends++;
        answer = max(answer, two_friends);
    }
    cout<<answer;
}