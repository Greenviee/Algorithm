#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, a, b;

void solve() {
    if(N<a+b-1) {
        cout<<-1;
        return;
    }
    if(a==1) {
        cout<<b<<' ';
        for(int i=0;i<N-b;i++) cout<<1<<' ';
        for(int i=b-1;i>0;i--) cout<<i<<' ';
        return;
    }
    int top = max(a, b);
    int cntone = N - (a+b-1);
    for(int i=0;i<=cntone;i++) cout<<1<<' ';
    for(int i=2;i<a;i++) cout<<i<<' ';
    if(top!=1) cout<<top<<' ';
    for(int i=b-1;i>=1;i--) cout<<i<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>a>>b;
    solve();
}