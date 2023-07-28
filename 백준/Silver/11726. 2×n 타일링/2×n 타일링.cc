#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long cnt[10001];
int n;

long long solve(int x) {
    if(cnt[x]!=-1) return cnt[x];
    if(x==n) return 1;
    if(x>n) return 0;
    
    long long k = 0;
    k += solve(x+1) % 10007;
    k += solve(x+2) % 10007;
    cnt[x] = k;
    return k;
}

int main() {
    cin>>n;
    memset(cnt, -1, sizeof(cnt));
    long long answer = solve(0) % 10007;
    cout<<answer<<endl;
}