#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 1001;
const int INF = 987654321;
int n, m, start, goal;
vector<pair<int, int>> adj[MAX_N];
vector<int> route(1001, -1);

vector<int> dijkstra(int src) {
    vector<int> dist(n+1, INF);
    dist[src] = 0;
    route[src] = 0;
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
                route[there] = here;
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    int u, v, w;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v, w));
    }
    cin>>start>>goal;
    vector<int> dist = dijkstra(start);
    cout<<dist[goal]<<endl;
    int temp = goal;
    vector<int> path;
    path.push_back(temp);
    while(temp!=0) {
        path.push_back(route[temp]);
        temp = route[temp];
    }
    reverse(path.begin(), path.end());
    cout<<path.size()-1<<endl;
    for(int i=1;i<path.size();i++) {
        cout<<path[i]<<' ';
    }
}
