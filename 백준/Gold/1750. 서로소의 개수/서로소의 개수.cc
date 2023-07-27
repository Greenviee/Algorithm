#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int MOD = 10000003;
int N, arr[51];
long long cache[51][100002];

int gcd(int p, int q) {
    if(p==-1) return q;
    if(q==0) return p;
    return gcd(q, p%q);
}

long long solve(int start, int GCD) {
    if(GCD==1) return pow(2, N-start);
    if(start==N) return 0;
    
    long long& ret = cache[start][GCD+1];
    if(ret!=-1) return ret;
    ret = 0;
    
    ret += solve(start+1, gcd(GCD, arr[start]))%MOD;
    ret += solve(start+1, GCD)%MOD;
    ret %= MOD;
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    memset(cache, -1, sizeof(cache));
    cout<<solve(0, -1);
}