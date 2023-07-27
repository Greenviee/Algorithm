#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K;
int weight[300001], value[300001], bag[300001];

long long solve() {
    long long total_value = 0, cnt = 0;;
    vector<pair<int, int>> jewel;
    for(int i=0;i<N;i++) jewel.push_back(make_pair(weight[i], value[i]));
    vector<int> capacity;
    for(int i=0;i<K;i++) capacity.push_back(bag[i]);
    //가치가 큰 보석이 맨 앞
    sort(capacity.begin(), capacity.end());
    sort(jewel.begin(), jewel.end());
    priority_queue<int> pq;
    
    int idx = 0;
    for(int i=0;i<K;i++) {
        while(idx<N && capacity[i]>=jewel[idx].first) {
            pq.push(jewel[idx].second);
            idx++;
        }
        if(!pq.empty()) {
            total_value += pq.top();
            pq.pop();
        }
    }
    
    return total_value;
}

int main() {
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>weight[i]>>value[i];
    for(int i=0;i<K;i++) cin>>bag[i];
    cout<<solve();
}