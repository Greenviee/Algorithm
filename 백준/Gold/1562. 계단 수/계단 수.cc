#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = 1000000000;
int N;
ll cache[10][1<<10][101];

int solution(int start, int state, int len) {
    if(len==N) {
        if((state|((1<<10)-1))==state) return 1;
        else return 0;
    }
    
    ll& ret = cache[start][state][len];
    if(ret!=-1) return ret;
    ret = 0;
    
    if(start>0) 
        ret += solution(start-1, state|(1<<(start-1)), len+1) % MOD;
        
    if(start<9)
        ret += solution(start+1, state|(1<<(start+1)), len+1) % MOD;
    
    ret %= MOD;
    return ret;
}

int main() {
    cin>>N;
    memset(cache, -1, sizeof(cache));
    ll answer = 0;
    for(int i=1;i<10;i++) {
        answer += solution(i, 1<<i, 1);
        answer %= MOD;
    }
    cout<<answer;
}