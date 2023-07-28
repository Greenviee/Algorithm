#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K;
int W[101], V[101];
//cache[capacity][value] : capacity의 용량이 남았을 때 value번째 물건부터 마지막 물건까지의 최대 가치 합
int cache[100001][1001];

int solve(int capacity, int start) {
    if(start==N) return 0;
    
    int& ret = cache[capacity][start];
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=start;i<N;i++) {
        if(capacity>=W[i]) 
            ret = max(ret, V[i] + solve(capacity-W[i], i+1));
    }
    return ret;
}

int main() {
    cin>>N>>K;
    for(int i=0;i<N;i++) 
        cin>>W[i]>>V[i];
    memset(cache, -1, sizeof(cache));
    int answer = solve(K, 0);
    cout<<answer;
}