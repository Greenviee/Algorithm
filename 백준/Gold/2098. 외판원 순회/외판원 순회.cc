#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 987654321;
int N;
int cost[16][16], cache[16][1<<16];

int travel(int here, int visit) {
    if((visit | ((1<<N)-1))==visit) {
        if(cost[here][0]==0) return INF;
        else return cost[here][0];
    }
    int& ret = cache[here][visit];
    if(ret!=-1) return ret;
    ret = INF;
    
    visit |= (1<<here);
    int canVisit = ~visit;
    for(int i=0;i<N;i++) {
        if((canVisit & (1<<i)) && cost[here][i]!=0) 
            ret = min(ret, cost[here][i] + travel(i, visit|(1<<i)));
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>cost[i][j];
    memset(cache, -1, sizeof(cache));
    int answer = travel(0, 0);
    cout<<answer<<endl;
}