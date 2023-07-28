#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int T, N, M;
int A[1001], B[1001];
vector<int> v1, v2;
int sum_A[1001], sum_B[1001];

void precalc() {
    sum_A[0] = A[0];
    for(int i=1;i<N;i++) sum_A[i] = A[i] + sum_A[i-1];
    sum_B[0] = B[0];
    for(int i=1;i<M;i++) sum_B[i] = B[i] + sum_B[i-1];
}

void push_v1() {
    for(int i=0;i<N;i++) {
        v1.push_back(sum_A[i]);
        for(int j=0;j<i;j++) 
            v1.push_back(sum_A[i]-sum_A[j]);
    }
    sort(v1.begin(), v1.end());
}

void push_v2() {
    for(int i=0;i<M;i++) {
        v2.push_back(sum_B[i]);
        for(int j=0;j<i;j++) 
            v2.push_back(sum_B[i]-sum_B[j]);
    }
    sort(v2.begin(), v2.end());
}

long long solve() {
    long long ret = 0;
    for(int i=0;i<v1.size();i++) {
        int n1 = v1[i];
        ret += upper_bound(v2.begin(), v2.end(), T-n1) - lower_bound(v2.begin(), v2.end(), T-n1);
    }
    return ret;
}

int main() {
    cin>>T>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    cin>>M;
    for(int i=0;i<M;i++) cin>>B[i];
    precalc();
    push_v1(); push_v2();
    cout<<solve();
}