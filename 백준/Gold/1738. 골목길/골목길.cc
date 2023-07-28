#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int MAX_N = 101;
const int INF = 98765432;
vector<pair<int, int>> adj[MAX_N];
vector<int> cycle;
vector<int> route(101, -11);

bool bfs(int src, int end) {
    int visited[MAX_N];
    memset(visited, -1, sizeof(visited));
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=0;i<adj[here].size();i++) {
            int there = adj[here][i].first;
            if(visited[there]==-1) {
                if(there==end) return true;
                q.push(there);
                visited[there] = 1;
            }
        }
    }
    return false;
}

bool cycleconnected() {
    for(int i=0;i<cycle.size();i++) {
        if(bfs(0, cycle[i]) && bfs(cycle[i], N-1)) {
            return true;
        }
    }
    return false;
}

vector<int> bellmanFord(int src) {
    vector<int> lower(N, -INF);
    lower[src] = 0;
    route[src] = -1;
    bool updated;
    for(int iter = 0;iter<N;iter++) {
        updated = false;
        for(int here = 0;here<N;here++) {
            for(int i=0;i<adj[here].size();i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(lower[there] < lower[here] + cost) {
                    lower[there] = lower[here] + cost;
                    updated = true;
                    route[there] = here;
                    if(iter==N-1) cycle.push_back(here);
                }
            }
        }
        if(!updated) break;
    }
    if(updated && cycleconnected()) lower.clear();
    return lower;
}

int main() {
    int u, v, w;
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>u>>v>>w;
        adj[u-1].push_back(make_pair(v-1, w));
    }
    vector<int> bel = bellmanFord(0);

    if(!bfs(0, N-1)) cout<<-1<<endl;
    else if(bel.empty()) cout<<-1<<endl;
    else {
        vector<int> path;
        int temp = N-1;
        path.push_back(temp+1);
        while(temp!=-1) {
            path.push_back(route[temp]+1);
            temp = route[temp];
        }
        reverse(path.begin(), path.end());

        for(int i=1;i<path.size();i++) {
            cout<<path[i]<<' ';
        }
    }
}