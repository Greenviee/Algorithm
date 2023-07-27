#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N, M;
int benefit[301][21];
int cache[301][21];
//money만큼의 돈이 있을 때 start번째 기업에 얼마를 투자해야 최대 수익을 얻는가
int bestinvest[301][21];

//start번째 기업부터 투자를 할 경우 money로 얻을 수 있는 최대 수익
int investment(int money, int start) {
    if(money==0) return 0;
    if(start>M) return -INF;
    
    int& ret = cache[money][start];
    if(ret!=-1) return ret;
    ret = -INF;
    
    for(int i=0;i<=money;i++) {
        int back = ret;
        ret = max(ret, benefit[i][start] + investment(money-i, start+1));
        if(ret!=back) bestinvest[money][start] = i;
    }
    
    return ret;
}

void solve() {
    int used = 0;
    for(int i=1;i<=M;i++) {
        int x = bestinvest[N-used][i];
        used += x;
        cout<<x<<' ';
    }
}

int main() {
    cin>>N>>M;
    int n;
    for(int i=1;i<=N;i++) {
        cin>>n;
        for(int j=1;j<=M;j++)
            cin>>benefit[i][j];
    }
    for(int i=1;i<=M;i++) benefit[0][i] = 0;
    memset(cache, -1, sizeof(cache));
    int answer = investment(N, 1);
    cout<<answer<<endl;
    solve();
}