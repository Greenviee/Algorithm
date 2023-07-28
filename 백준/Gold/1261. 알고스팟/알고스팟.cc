#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 98765432;
int N, M;
int adj[101][101];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int dijkstra(int src_x, int src_y) {
    int dist[101][101];
    for(int i=0;i<=N;i++) {
        for(int j=0;j<=M;j++)
            dist[j][i] = INF;
    }
    dist[src_x][src_y] = 0;
    //pq : (dist, (x, y));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(src_x, src_y)));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(dist[x][y] < cost) continue;
        for(int i=0;i<4;i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            int nextDist = cost + adj[new_x][new_y];
            if((0<new_x && new_x<=M) && (0<new_y && new_y<=N) && dist[new_x][new_y] > nextDist) {
                dist[new_x][new_y] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(new_x, new_y)));
            }
        }
    }
    return dist[M][N];
}

int main() {
    cin>>M>>N;
    for(int i=1;i<=N;i++) {
        string s;
        cin>>s;
        for(int j=1;j<=M;j++)
            adj[j][i] = s[j-1] - '0';
    }
    int answer = dijkstra(1, 1);
    cout<<answer;
}