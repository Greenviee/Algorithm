#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 98765432;
int N, K;

vector<int> dijkstra(int src) {
    vector<int> dist(100001, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0 ,src));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here]<cost) continue;
        if(here>0 && dist[here-1] > cost+1) {
            dist[here-1] = cost+1;
            pq.push(make_pair(-dist[here-1], here-1));
        }
        if(here<K && dist[here+1] > cost+1) {
            dist[here+1] = cost+1;
            pq.push(make_pair(-dist[here+1], here+1));
        }
        if(here<50001 && here<K && dist[here*2] > cost) {
            dist[here*2] = cost;
            pq.push(make_pair(-dist[here*2], here*2));
        }
    }
    return dist;
}

int main() {
    cin>>N>>K;
    vector<int> dist = dijkstra(N);
    cout<<dist[K];
}