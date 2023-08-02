#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, M;
ll arr[1000001];
vector<ll> psum;
ll cnt[1001];

void precalc() {
    psum.push_back(0);
    cnt[0]++;
    for(int i=0;i<N;i++) {
        ll sum = (psum.back() + arr[i])%M;
        psum.push_back(sum);
        cnt[sum]++;
    }
}

ll solution() {
    ll ret = 0;
    for(int i=0;i<M;i++) {
        if(cnt[i]>=2)
            ret += (cnt[i]*(cnt[i]-1))/2;
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    precalc();
    ll answer = solution();
    cout<<answer;
}