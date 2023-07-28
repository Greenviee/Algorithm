#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M, start, goal;
const int MAX_N = 501;
const long long INF = 9876543210000000;
vector<pair<int, int>> adj[MAX_N];
vector<int> cycle;



bool bfs(int src, int end) {
    int visited[501];
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
                visited[there] = 1;
                q.push(there);
            }
        }
    }
    if(visited[end]==1) return true;
    else return false;
}

bool cycleconnect() {
    for(int i=0;i<cycle.size();i++) {
        if(bfs(cycle[i], goal) && bfs(start, cycle[i])) {
            return true;
            break;
        }
    }
    return false;
}

vector<long long> bellmanFord(int src) {
    vector<long long> lower(N, -INF);
    lower[src] = 0;
    bool updated;
    for(int iter=0;iter<N;iter++) {
        updated = false;
        for(int here=0;here<N;here++) {
            for(int i=0;i<adj[here].size();i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(lower[there] < lower[here] + cost) {
                    lower[there] = lower[here] + cost;
                    if(iter==N-1) cycle.push_back(here);
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(cycleconnect() && updated) lower.clear();
    return lower;
}

int main() {
    cin>>N>>start>>goal>>M;
    vector<int> earn;
    vector<int> sp;
    vector<int> ep;
    vector<int> cost;
    int a, b, t;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>t;
        sp.push_back(a);
        ep.push_back(b);
        cost.push_back(t);
    }
    for(int i=0;i<N;i++) {
        cin>>t;
        earn.push_back(t);
    }
    for(int i=0;i<M;i++) {
        adj[sp[i]].push_back(make_pair(ep[i], earn[ep[i]] - cost[i]));
    }
    vector<long long> v = bellmanFord(start);
    
    if(!bfs(start, goal)) cout<<"gg"<<endl;
    else if(v.empty()) cout<<"Gee"<<endl;
    else cout<<v[goal]+earn[start]<<endl;
}
