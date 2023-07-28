#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int MOD = 1000000003;
int N, K;
//cache[시작][선택해야 하는 색 개수][0번 선택 여부]
long long cache[1001][1001][2];

long long color(int start, int pick, bool pickfirst) {
    if(pick==0) return 1;
    if(start>=N || (N-start)/2<pick) return 0;
    
    long long& ret = cache[start][pick][pickfirst];
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=start;i<N;i++) {
        if(i==0) ret += color(i+2, pick-1, 1)%MOD;
        else {
            if(start==N-1) {
                if(!pickfirst && pick==1) ret += 1; 
            }
            else ret += color(i+2, pick-1, pickfirst)%MOD;
        }
        ret%MOD;
    }
    
    return ret%MOD;
}

int main() {
    cin>>N>>K;
    memset(cache, -1, sizeof(cache));
    long long answer = color(0, K, 0);
    cout<<answer;
}