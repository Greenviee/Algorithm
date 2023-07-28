#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K, W;
int T[1001];
//adj[num] : num번 건물을 짓기 위해 필요한 건물의 종류
vector<vector<int>> adj;
//cache[num] : num번째 건물을 짓는데 걸리는 시간
int cache[1001];

int construction(int num) {
    if(adj[num].empty()) return T[num-1];
    
    int& ret = cache[num];
    if(ret!=-1) return ret;
    ret = T[num-1];
    
    for(int i=0;i<adj[num].size();i++) {
        ret = max(ret, T[num-1] + construction(adj[num][i]));
    }
    
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>N>>K;
        adj = vector<vector<int>>(1001);
        for(int i=0;i<N;i++) cin>>T[i];
        int x, y;
        for(int i=0;i<K;i++) {
            cin>>x>>y;
            adj[y].push_back(x);
        }
        cin>>W;
        memset(cache, -1, sizeof(cache));
        int answer = construction(W);
        cout<<answer<<endl;
    }
}