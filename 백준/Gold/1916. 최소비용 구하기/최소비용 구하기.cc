#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 1001;
const int INF = 987654321;
int N, M;
vector<pair<int, int>> adj[MAX_N];

vector<int> dijkstra(int src) {
    vector<int> dist(N+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0;i<adj[here].size();i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    cin>>N>>M;
    int a, b, t;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>t;
        adj[a].push_back(make_pair(b, t));
    }
    int start, end;
    cin>>start>>end;
    vector<int> dist = dijkstra(start);
    cout<<dist[end]<<endl;
}