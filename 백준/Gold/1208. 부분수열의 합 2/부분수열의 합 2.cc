#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, S;
int arr[2][21];
vector<int> v1, v2;

void push_v1(int start, int cur) {
    if(start==(N/2+N%2)) {
        v1.push_back(cur);
        return;
    }
    push_v1(start+1, cur+arr[0][start]);
    push_v1(start+1, cur);
    return;
}

void push_v2(int start, int cur) {
    if(start==(N/2)) {
        v2.push_back(cur);
        return;
    }
    push_v2(start+1, cur+arr[1][start]);
    push_v2(start+1, cur);
    return;
}

long long solve() {
    long long ret = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i=0;i<v1.size();i++) {
        int n1 = v1[i];
        ret += upper_bound(v2.begin(), v2.end(), S-n1) - lower_bound(v2.begin(), v2.end(), S-n1);
    }
    
    return ret;
}

int main() {
    cin>>N>>S;
    for(int i=0;i<N;i++) cin>>arr[i%2][i/2];
    push_v1(0, 0);
    push_v2(0, 0);
    long long answer = solve();
    //S==0일 경우 공집합 1개 제외
    if(S==0) cout<<answer-1;
    else cout<<answer;
}
