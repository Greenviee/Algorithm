#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N;
vector<vector<int>> pre(501);
int cost[501];
int cache[501];

int build(int start) {
    if(pre[start].empty()) cache[start] = cost[start];
    
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=0;i<pre[start].size();i++) 
        ret = max(ret, cost[start] + build(pre[start][i]));
    return ret;
}

int main() {
    cin>>N;
    int a;
    memset(cache, -1, sizeof(cache));
    for(int i=0;i<N;i++) {
        cin>>cost[i];
        while(1) {
            cin>>a;
            if(a==-1) break;
            pre[i].push_back(a-1);
        }
    }
    for(int i=N-1;i>=0;i--) int k = build(i);
    for(int i=0;i<N;i++) cout<<cache[i]<<endl;
}