#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 98765432;
int N;
int adj[126][126];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int dijkstra(int src_x, int src_y) {
    int dist[126][126];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            dist[j][i] = INF;
    }
    dist[src_x][src_y] = adj[src_x][src_y];
    //pq : (dist, (x, y));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(-dist[src_x][src_y], make_pair(src_x, src_y)));
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
            if((0<=new_x && new_x<N) && (0<=new_y && new_y<N) && dist[new_x][new_y] > nextDist) {
                dist[new_x][new_y] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(new_x, new_y)));
            }
        }
    }
    return dist[N-1][N-1];
}

int main() {
    int cnt = 0;
    while(1) {
        cnt++;
        cin>>N;
        if(N==0) break;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++)
                cin>>adj[j][i];
        }
        int answer = dijkstra(0, 0);
        cout<<"Problem "<<cnt<<": "<<answer<<endl;
    }
}