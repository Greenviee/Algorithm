#include <iostream>
#include <cstring>
using namespace std;

int cache[301][2];
int N;
int stair[302];
int _INF = -98765432;


int solve(int n, bool ok) {
    if(n==N) return stair[n];
    if(n>N) return _INF;
    int& ret = cache[n][ok];
    if(ret!=-1) return ret;
    

    ret = _INF;
    
    if(ok || n==1) 
        ret = solve(n+1, false);
    ret = max(ret, solve(n+2, true));
    ret += stair[n];
    
    return ret;
}

int main() {
    cin>>N;
    memset(cache, -1, sizeof(cache));
    stair[0] = 0;
    for(int i=1;i<=N;i++) cin>>stair[i];
    int answer = solve(0, true);
    cout<<answer<<endl;
}