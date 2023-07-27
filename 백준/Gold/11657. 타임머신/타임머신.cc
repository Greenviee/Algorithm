#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

int N, M;
const int MAX_N = 501;
const long long INF = numeric_limits<long long>::max();
vector<pair<int, int>> adj[MAX_N];

vector<long long> bellmanFord(int src) {
    vector<long long> upper(N, INF);
    upper[src] = 0;
    bool updated;
    for(int iter = 0;iter<N;iter++) {
        updated = false;
        for(int here = 0;here<N;here++) {
            if(upper[here]==INF) continue;
            for(int i=0;i<adj[here].size();i++) {
                int there = adj[here][i].first;
                long long cost = adj[here][i].second;
                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    if(updated) upper.clear();
    return upper;
}

int main() {
    cin>>N>>M;
    int a, b, t;
    for(int i=0;i<M;i++) {
        cin>>a>>b>>t;
        adj[a-1].push_back(make_pair(b-1, t));
    }
    vector<long long> T = bellmanFord(0);
    if(T.empty()) cout<<"-1";
    else for(int i=1;i<N;i++) {
        if(T[i]==INF) cout<<"-1"<<endl;
        else cout<<T[i]<<endl;
    }
}