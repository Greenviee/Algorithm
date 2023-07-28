#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, W;
const int MAX_N = 501;
const int INF = 98765432;
vector<pair<int, int>> adj[MAX_N];

vector<int> bellmanFord(int src) {
    vector<int> upper(N, INF);
    upper[src] = 0;
    bool updated;
    for(int iter=0;iter<N;iter++) {
        updated = false;
        for(int here=0;here<N;here++) {
            for(int i=0;i<adj[here].size();i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
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
    int C;
    cin>>C;
    while(C--) {
        cin>>N>>M>>W;
        int a, b, t;
        for(int i=0;i<N;i++) adj[i].clear();
        for(int i=0;i<M;i++) {
            cin>>a>>b>>t;
            adj[a-1].push_back(make_pair(b-1, t));
            adj[b-1].push_back(make_pair(a-1, t));
        }
        for(int i=0;i<W;i++) {
            cin>>a>>b>>t;
            adj[a-1].push_back(make_pair(b-1, -t));
        }
        vector<int> T = bellmanFord(0);
        if(T.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}