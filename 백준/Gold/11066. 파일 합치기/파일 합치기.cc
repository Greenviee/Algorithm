#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int K;
int page[501];
int cache[501][501];
int sum[501];

void precalc() {
    sum[0] = 0;
    for(int i=1;i<=K;i++)
        sum[i] = page[i-1] + sum[i-1];
}

int solve(int left, int right) {
    if(left==right) return 0;
    if(right-left==1) return page[right] + page[left];
    
    int& ret = cache[left][right];
    if(ret!=-1) return ret;
    ret = INF;
    
    for(int m=left+1;m<=right;m++) {
        ret = min(ret, solve(left, m-1) + solve(m, right) + sum[right+1] - sum[left]);
    }
    
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>K;
        memset(cache, -1, sizeof(cache));
        for(int i=0;i<K;i++) cin>>page[i];
        precalc();
        cout<<solve(0, K-1)<<endl;
    }
}
