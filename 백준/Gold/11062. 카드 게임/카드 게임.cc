#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int cards[1001];
int cache[1001][1001];
int sum[1001];

void precalc() {
    sum[0] = cards[0];
    for(int i=1;i<N;i++) sum[i] = sum[i-1] + cards[i]; 
}

//turn==0 명우 차례, turn==1 근우 차례
int points(int left, int right) {
    //기저조건
    if(left==right) return cards[left];
    
    int& ret = cache[left][right];
    if(ret!=-1) return ret;
    ret = 0;
    
    int S = sum[right] - sum[left] + cards[left];
    ret = max(S - points(left+1, right), S - points(left, right-1));
    
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        cin>>N;
        for(int i=0;i<N;i++) cin>>cards[i];
        precalc();
        int answer = points(0, N-1);
        cout<<answer<<endl;
    }
}