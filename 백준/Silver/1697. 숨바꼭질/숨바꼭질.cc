#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
queue<int> q;
int dist[300000];
int visited[300000];

int bfs(int start) {
    visited[start] = 1;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int x = q.front();
        if(x==K) return dist[x];
        q.pop();
        if(x>0 && visited[x-1]!=1) {
            visited[x-1] = 1;
            q.push(x-1);
            dist[x-1] = dist[x] + 1;
        }
        if(x<K && visited[x+1]!=1) {
            visited[x+1] = 1;
            q.push(x+1);
            dist[x+1] = dist[x] + 1;
        }
        if(x<K && visited[2*x]!=1) {
            visited[2*x] = 1;
            q.push(2*x);
            dist[2*x] = dist[x] + 1;
        }
    }
}

int main() {
    cin>>N>>K;
    memset(visited, -1, sizeof(visited));
    cout<<bfs(N);
}