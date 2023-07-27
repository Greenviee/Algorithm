#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int K, N, M;
int A[1001], B[1001], sum_A[1001], sum_B[1001];
vector<int> v1, v2;

void precalc() {
    sum_A[0] = A[0];
    for(int i=1;i<N;i++) sum_A[i] = A[i] + sum_A[i-1];
    sum_B[0] = B[0];
    for(int i=1;i<M;i++) sum_B[i] = B[i] + sum_B[i-1];
    
    v1.push_back(0);
    for(int i=0;i<N;i++) {
        v1.push_back(sum_A[i]);
        for(int j=0;j<i;j++) {
            v1.push_back(sum_A[i] - sum_A[j]);
            if(i==N-1) {
                for(int k=0;k<j;k++)
                    v1.push_back(sum_A[i] - sum_A[j] + sum_A[k]);
            }
        }
    }
    v2.push_back(0);
    for(int i=0;i<M;i++) {
        v2.push_back(sum_B[i]);
        for(int j=0;j<i;j++) {
            v2.push_back(sum_B[i] - sum_B[j]);
            if(i==M-1) {
                for(int k=0;k<j;k++)
                    v2.push_back(sum_B[i] - sum_B[j] + sum_B[k]);
            }
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}

int pizza() {
    int ret = 0;
    for(int i=0;i<v1.size();i++) {
        int n = v1[i];
        ret += upper_bound(v2.begin(), v2.end(), K-n) - lower_bound(v2.begin(), v2.end(), K-n);
    }
    return ret;
}

int main() {
    cin>>K>>N>>M;
    for(int i=0;i<N;i++) cin>>A[i];
    for(int i=0;i<M;i++) cin>>B[i];
    precalc();
    cout<<pizza();   
}