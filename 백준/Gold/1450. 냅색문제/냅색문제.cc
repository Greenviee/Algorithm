#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, C;
vector<int> things[2];
vector<long long> v1, v2;

void push_v1(int start, long long cur) {
    if(start==things[0].size()) {
        v1.push_back(cur);
        return;
    }
    push_v1(start+1, cur+things[0][start]);
    push_v1(start+1, cur);
}

void push_v2(int start, long long cur) {
    if(start==things[1].size()) {
        v2.push_back(cur);
        return;
    }
    push_v2(start+1, cur+things[1][start]);
    push_v2(start+1, cur);
}

long long solve() {
    long long ret = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i=0;i<v1.size();i++) {
        long long n1 = v1[i];
        ret += upper_bound(v2.begin(), v2.end(), C-n1) - v2.begin();
    }
    return ret;
}

int main() {
    cin>>N>>C;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        things[i%2].push_back(a);
    }
    push_v1(0, 0);
    push_v2(0, 0);
    cout<<solve();
}