#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, M;
int plumb[30], marble[7];
int cache[30][80001];

int check(int start, int left, int right) {
    if(left==right) return true;
    if(start==N) return false;
    
    int& ret = cache[start][abs(left-right)];
    if(ret!=-1) return ret;
    
    int a = 0;
    a += check(start+1, left+plumb[start], right) + check(start+1, left, right+plumb[start]) + check(start+1, left, right);
    if(a>0) ret = 1;
    else ret = 0;
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>plumb[i];
    cin>>M;
    for(int i=0;i<M;i++) cin>>marble[i];
    memset(cache, -1, sizeof(cache));
    for(int i=0;i<M;i++) {
        if(check(0, marble[i], 0)) cout<<"Y ";
        else cout<<"N ";
    }
}