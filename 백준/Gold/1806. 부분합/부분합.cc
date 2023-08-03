#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, S;
int arr[100001];
ll psum[100001];

void precalc() {
    psum[0] = 0;
    for(int i=1;i<=N;i++)
        psum[i] = psum[i-1] + arr[i];
}

int solution() {
    int ret = INF;
    int head = 1, tail = 1;
    if(psum[N]<S) return 0;
    
    while(tail<=N) {
        if(psum[tail]-psum[head-1]<S) tail++;
        else {
            ret = min(ret, tail-head+1);
            head++;
        }
    }
    
    return ret;
}

int main() {
    cin>>N>>S;
    for(int i=1;i<=N;i++) cin>>arr[i];
    precalc();
    cout<<solution();
}