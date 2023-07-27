#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n;
long long histogram[100001];

long long solve(int lo, int hi) {
    if(lo==hi) return histogram[lo]; 
    int mid = (lo+hi)/2;
    long long ret = -1;
    //좌측만
    ret = max(ret, solve(lo, mid));
    //우측만
    ret = max(ret, solve(mid+1, hi));
    //mid를 포함하는 사각형
    long long height = histogram[mid];
    ret = max(ret, height);
    int left = mid-1, right = mid+1;
    while(left>=lo || right<=hi) {
        long long k;
        if(left>=lo && right<=hi) k = max(histogram[left], histogram[right]);
        else if(left>=lo) k = histogram[left];
        else if(right<=hi) k = histogram[right];
        
        if(left>=lo && k==histogram[left]) left--;
        else right++;
        height = min(height, k);
        ret = max(ret, height*(right-left-1));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1) {
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++) cin>>histogram[i];
        long long answer = solve(0, n-1);
        cout<<answer<<"\n";
    }
}