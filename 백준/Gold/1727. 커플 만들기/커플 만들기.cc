#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N, M;
vector<int> man, woman;
int cache[1001][1001];
int max_couple;

int couple(int m, int w, int cnt) {
    if(cnt==max_couple) return 0;
    if(m==N || w==M) return INF;
    
    int& ret = cache[m][w];
    if(ret!=-1) return ret;
    ret = INF;
    
    if((N-m)>(M-w)) {
        for(int i=m;i<=N-M+w;i++) 
            ret = min(ret, abs(man[i]-woman[w])+couple(i+1, w+1, cnt+1));
    }
    else {
        for(int i=w;i<=M-N+m;i++)
            ret = min(ret, abs(man[m]-woman[i])+couple(m+1, i+1, cnt+1));
    }
    return ret;
}

int main() {
    cin>>N>>M;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        man.push_back(a);
    }
    for(int i=0;i<M;i++) {
        cin>>a;
        woman.push_back(a);
    }
    sort(man.begin(), man.end());
    sort(woman.begin(), woman.end());
    memset(cache, -1, sizeof(cache));
    max_couple = min(N, M);
    cout<<couple(0, 0, 0);
}