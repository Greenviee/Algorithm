#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int M, L[100001], R[100001];
int N;

int cover() {
    int ret = 0;
    vector<pair<int, int>> lines;
    for(int i=0;i<N;i++) lines.push_back(make_pair(L[i], i));
    sort(lines.begin(), lines.end());
    priority_queue<int> pq;
    int end = 0, idx = 0;
    while(end<M) {
        while(idx<N && lines[idx].first<=end) {
            pq.push(R[lines[idx].second]);
            idx++;
        }
        if(pq.empty()) return 0;
        end = pq.top();
        pq.pop();
        ret++;
    }
    return ret;
}

int main() {
    cin>>M;
    int i = 0;
    while(1) {
        cin>>L[i]>>R[i];
        if(L[i]==0 && R[i]==0) break;
        i++;
    }
    N = i;
    cout<<cover();
}