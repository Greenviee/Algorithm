#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int n, k;
int coins[101];
int cache[10001];

int solve(int sum) {
    if(sum==0) return 0;
    else if(sum<0) return INF;
    
    int& ret = cache[sum];
    if(ret!=-1) return ret;
    
    ret = INF;
    for(int i=0;i<n;i++) {
        ret = min(ret, 1+solve(sum-coins[i]));
    }
    return ret;
}

int main() {
    cin>>n>>k;
    memset(cache, -1, sizeof(cache));
    for(int i=0;i<n;i++) cin>>coins[i];
    int answer = solve(k);
    if(answer==INF) cout<<-1;
    else cout<<answer;
}