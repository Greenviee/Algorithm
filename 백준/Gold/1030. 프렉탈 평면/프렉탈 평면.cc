#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int s, N, K, R1, R2, C1, C2;

void fractile(int i, int j, int num) {
    int nx = j, ny = i;
    for(int k=0;k<num-1;k++) {
        nx /= N;
        ny /= N;
    }
    if(((((N-K)/2)<=nx%N) && (nx%N<((N+K)/2))) && ((((N-K)/2)<=ny%N) && (ny%N<((N+K)/2))))
        cout<<'1';
    else {
        if(num==1) cout<<'0';
        else fractile(i, j, num-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>s>>N>>K>>R1>>R2>>C1>>C2;
    if(s==0) cout<<'0';
    else {
        for(int i=R1;i<=R2;i++) {
            for(int j=C1;j<=C2;j++) 
                fractile(i, j, s);
            cout<<"\n";
        }
    }
}