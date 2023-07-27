#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
vector<int> arr, LtoR, RtoL;

int gcd(int p, int q) {
    if(q==0) return p;
    return gcd(q, p%q);
}

vector<int> solve() {
    vector<int> ret;
    //LtoR
    int GCD = arr[0];
    LtoR.push_back(GCD);
    for(int i=1;i<N;i++) {
        GCD = gcd(GCD, arr[i]);
        LtoR.push_back(GCD);
    }
    //RtoL
    GCD = arr[N-1];
    RtoL.push_back(GCD);
    for(int i=N-2;i>=0;i--) {
        GCD = gcd(GCD, arr[i]);
        RtoL.push_back(GCD);
    }
    reverse(RtoL.begin(), RtoL.end());
    ret.push_back(-1);
    ret.push_back(-1);
    int maximum = -1;
    if(arr[0]%RtoL[1]!=0) {
        maximum = RtoL[1];
        ret[0] = maximum;
        ret[1] = arr[0];
    }
    if(arr[N-1]%LtoR[N-2]!=0) {
        maximum = max(maximum, LtoR[N-2]);
        if(maximum==LtoR[N-2]) {
            ret[0] = maximum;
            ret[1] = arr[N-1];
        }
    }
    for(int i=1;i<N-1;i++) {
        int n = gcd(LtoR[i-1], RtoL[i+1]);
        if(arr[i]%n!=0) maximum = max(maximum, n);
        if(maximum==n) {
            ret[0] = maximum;
            ret[1] = arr[i];
        }
    }
    return ret;
}

int main() {
    cin>>N;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        arr.push_back(a);
    }
    vector<int> answer = solve();
    if(answer[0]==-1) cout<<answer[0]<<endl;
    else cout<<answer[0]<<' '<<answer[1]<<endl;
}