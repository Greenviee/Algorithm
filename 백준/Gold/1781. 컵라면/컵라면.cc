#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
using namespace std;

int N;
int deadline[200001], cupnoodle[200001];

int solve() {
    int ret = 0;
    vector<pair<int, int>> cup;
    for(int i=0;i<N;i++) cup.push_back(make_pair(-deadline[i], i));
    priority_queue<int> pq;
    sort(cup.begin(), cup.end());
    
    int idx = 0;
    int max_deadline = -cup[0].first;
    for(int i=max_deadline;i>0;i--) {
        while(idx<N && -cup[idx].first>=i) {
            pq.push(cupnoodle[cup[idx].second]);
            idx++;
        }
        
        if(!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>deadline[i]>>cupnoodle[i];
    cout<<solve();
}
