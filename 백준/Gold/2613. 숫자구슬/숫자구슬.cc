#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N, M;
int marble[301];
//N번째 구슬부터 M개의 그룹을 만들 때 최댓값의 최소
int cache[301][301];
int sum[301];
int bestpick[301][301];

//N번 구슬까지 합
void precalc() {
    sum[0] = 0;
    sum[1] = marble[1];
    for(int i=2;i<=N;i++) sum[i] = sum[i-1] +marble[i]; 
}

int grouping(int start, int groups) {
    if(groups==1) {
        bestpick[start][groups] = N - start + 1;
        return sum[N] - sum[start-1];
    }
    if(start>N) return INF;
    
    int& ret = cache[start][groups];
    if(ret!=-1) return ret;
    ret = INF;
    
    for(int i=start;i<=N-groups+1;i++) {
        int m;
        m = max(sum[i]-sum[start-1], grouping(i+1, groups-1));
        ret = min(m, ret);
        if(ret==m) bestpick[start][groups] = i-start+1;
    }
    return ret;
}

void answer(int start, int groups) {
    if(bestpick[start][groups]==-1) return;
    cout<<bestpick[start][groups]<<' ';
    answer(start+bestpick[start][groups], groups-1);
}

int main() {
    memset(cache, -1, sizeof(cache));
    memset(bestpick, -1, sizeof(bestpick));
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>marble[i+1];
    precalc();
    cout<<grouping(1, M)<<endl;
    answer(1, M);
}