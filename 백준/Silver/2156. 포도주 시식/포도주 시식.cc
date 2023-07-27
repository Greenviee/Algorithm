#include <iostream>
#include <cstring>
using namespace std;

int cache[10001][2];
int N;
int wine[10002];
int _INF = -98765432;


int solve(int n, bool ok) {
    if(n==N) return wine[n];
    if(n>N) return 0;
    int& ret = cache[n][ok];
    if(ret!=-1) return ret;
    

    ret = _INF;
    
    if(ok || n==1) 
        ret = solve(n+1, false);
    ret = max(ret, solve(n+2, true));
    ret = max(ret, solve(n+3, true));
    ret += wine[n];
    
    return ret;
}

int main() {
    cin>>N;
    memset(cache, -1, sizeof(cache));
    wine[0] = 0;
    for(int i=1;i<=N;i++) cin>>wine[i];
    int answer = solve(0, true);
    cout<<answer<<endl;
}