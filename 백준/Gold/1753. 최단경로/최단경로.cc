#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_V = 20001;
const int INF = 987654321;
int V, E, K;
vector<pair<int, int>> adj[MAX_V];

vector<int> dijkstra(int src) {
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    //pair : 가중치, 연결점
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        for(int i=0;i<adj[here].size();i++) {
            int there = adj[here][i].first;
            int nextDist = adj[here][i].second + cost;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    int u, v, w;
    cin>>V>>E>>K;
    for(int i=0;i<E;i++) {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
    }
    vector<int> dist = dijkstra(K);
    for(int i=1;i<V+1;i++) {
       int a = dist[i];
       if(a==INF) cout<<"INF"<<"\n";
       else cout<<a<<"\n";
    }
}