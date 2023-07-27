#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

const int INF = 987654321;
int N, cost[16][16], P;
int cache[1<<16];

int bitcount(int n) {
    int ret = 0;
    int i = 1;
    
    while(i<(1<<N)) {
        if(n&i) ret++;
        i<<=1;
    }
    return ret;
} 

//toOn을 킬 경우 최소 비용
int mincost(int state, int toOn) {
    int ret = INF;
    int i = 1, idx = 0;
    while(i<(1<<N)) {
        if(toOn!=idx && (state&i)) ret = min(ret, cost[idx][toOn]);
        i<<=1;
        idx++;
    }
    return ret;
}

int solution(int state, int total) {
    if(bitcount(state)>=P) return total;
    int& ret = cache[state];
    if(ret!=-1) return total+ret;
    ret = INF;
    int canOn = ~state;
    for(int i=0;i<N;i++) {
        //꺼져있는 발전기인 경우
        if(canOn & (1<<i)) {
            ret = min(ret, solution((state|(1<<i)), mincost(state, i)));
        }
    }
    return total+ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>cost[i][j];
    string s;
    int state = 0;
    cin>>s;
    for(int i=0;i<N;i++) 
        if(s[i]=='Y') state|=(1<<i);
    cin>>P;
    
    if(state==0 && P>0) cout<<-1;
    else {
        int answer = solution(state, 0);
        cout<<answer<<endl;
    }
}