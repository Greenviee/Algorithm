#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N;
int cost[1001][3];
int cache[3][3][1001];

//paint(첫 집 색깔, 바로 이전 집 색깔, 현 위치)
int paint(int start, int before, int here) {
    //기저조건
    if(here==N-1) {
        int n = INF;
        bool canUse[3] = {1, 1, 1};
        canUse[start] = false;
        canUse[before] = false;
        for(int i=0;i<3;i++)
            if(canUse[i])
                n = min(n, cost[N-1][i]);
        return n;
    }
    
    int& ret = cache[start][before][here];
    if(ret!=-1) return ret;
    ret = INF;
    
    for(int i=0;i<3;i++) 
        if(i!=before) ret = min(ret, cost[here][i] + paint(start, i, here+1));
    
    return ret;
}

int solution() {
    int ret = INF;
    //첫 집 색칠
    for(int i=0;i<3;i++)
        ret = min(ret, cost[0][i] + paint(i, i, 1));
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) 
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    memset(cache, -1, sizeof(cache));
    int answer = solution();
    cout<<answer;
}