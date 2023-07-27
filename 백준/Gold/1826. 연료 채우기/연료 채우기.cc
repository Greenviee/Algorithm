#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, dist[10001], fuel[10001];
int goal, oil;

int solve() {
    int ret = 0;
    vector<pair<int, int>> station;
    for(int i=0;i<N;i++) station.push_back(make_pair(dist[i], i));
    priority_queue<int> pq;
    sort(station.begin(), station.end());
    
    int idx = 0;
    while(oil<goal) {
        while(idx<N && station[idx].first<=oil) {
            pq.push(fuel[station[idx].second]);
            idx++;
        }
        if(pq.empty()) return -1;
        oil += pq.top();
        pq.pop();
        ret++;
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>dist[i]>>fuel[i];
    cin>>goal>>oil;
    cout<<solve();
}