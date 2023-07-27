#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int A[4001], B[4001], C[4001], D[4001];
vector<int> v1, v2;

void precalc() {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v1.push_back(A[i]+B[j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v2.push_back(C[i]+D[j]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}

long long solve() {
    long long ret = 0;
    for(int i=0;i<v1.size();i++) {
        int n1 = v1[i];
        //불변조건 : n1+lo<=0, n1+hi>0
        int lo = 0, hi = v2.size()-1;
        if(n1+v2[lo]>0) continue;
        if(n1+v2[hi]<0) continue;
        if(n1+v2[lo]==0) ret++;
        if(n1+v2[hi]==0) ret++;
        int head, tail;
        while(lo+1<hi) {
            int mid = (lo+hi)/2;
            if(n1+v2[mid]>0)
                hi = mid;
            else
                lo = mid;
        }
        tail = lo;
        if(n1+v2[tail]!=0) continue;
        lo = 0, hi = v2.size()-1;
        while(lo+1<hi) {
            int mid = (lo+hi)/2;
            if(n1+v2[mid]>=0) 
                hi = mid;
            else
                lo = mid;
        }
        head = hi;
        ret += (tail-head+1);
    }
    return ret;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i]>>B[i]>>C[i]>>D[i];
    precalc();
    cout<<solve();
}