#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int arr[1001], cache[1001];
int x[1001];

int getlis(int start) {
    if(start==N) return 1;
    
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 1;
    
    int bestnext = -1;
    for(int i=start+1;i<=N;i++) {
        int s = ret;
        if(arr[i]>arr[start]) ret = max(ret, 1+getlis(i));
        if(ret!=s) bestnext = i;
    }
    if(bestnext!=-1) x[start] = bestnext;
    return ret;
}

void route(int start) {
    if(x[start]==-1) return;
    cout<<arr[x[start]]<<' ';
    route(x[start]);
}

int main() {
    cin>>N;
    arr[0] = -1;
    for(int i=1;i<=N;i++) cin>>arr[i];
    memset(cache, -1, sizeof(cache));
    memset(x, -1, sizeof(x));
    int answer = getlis(0);
    cout<<answer-1<<endl; 
    route(0);
}