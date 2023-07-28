#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 98765432;
int N, E, v1, v2;
vector<pair<int, int>> adj[801];

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

int total_dist() {
    vector<int> dist = dijkstra(1);
    int a1 = dist[v1];
    int a2 = dist[v2];
    dist = dijkstra(v1);
    a1 += dist[v2];
    dist = dijkstra(v2);
    a1 += dist[N];
    a2 += dist[v1];
    dist = dijkstra(v1);
    a2 += dist[N];
    
    return min(a1, a2);
}

int main() {
    cin>>N>>E;
    int a, b, t;
    for(int i=0;i<E;i++) {
        cin>>a>>b>>t;
        adj[a].push_back(make_pair(b, t));
        adj[b].push_back(make_pair(a, t));
    }
    cin>>v1>>v2;
    int answer = total_dist();
    if(answer>=INF) cout<<"-1"; 
    else cout<<answer;
}