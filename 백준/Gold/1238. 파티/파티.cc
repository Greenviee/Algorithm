#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 98765432;
int N, M, X;
vector<pair<int, int>> adj[1001];

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

int total_dist(int N) {
    if(N==X) return 0;
    vector<int> dist = dijkstra(N);
    int answer = dist[X];
    dist = dijkstra(X);
    answer += dist[N];
    return answer;
}

int main() {
    cin>>N>>M>>X;
    int a, b, t;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>t;
        adj[a].push_back(make_pair(b, t));
    }
    int answer = 0;
    for(int i=1;i<=N;i++) {
        answer = max(answer, total_dist(i));
    }
    cout<<answer;
}