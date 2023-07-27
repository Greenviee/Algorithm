#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

ll A, B;
const int MAX_N = 2000000;
bool prime[MAX_N+1];
vector<ll> pnum;


void eratosthenes() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    int sqrtn = sqrt(MAX_N);
    for(int i=2;i<=sqrtn;i++) 
        if(prime[i])
            for(int j=i*i;j<=MAX_N;j+=i) prime[j] =false;
    for(int i=2;i<=MAX_N;i++) 
        if(prime[i]) pnum.push_back(i);
}

bool isPrime(ll N) {
    int idx = 0;
    while(idx<pnum.size() && pnum[idx]<=sqrt(N)) {
        if(N%pnum[idx]==0) return false;
        idx++;
    }
    return true;
}

bool solve(ll A, ll B) {
    if(A+B<4) return false;
    if((A+B)%2==0) return true;
    else {
        if(isPrime(A+B-2)) return true;
        else return false;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int C; cin>>C;
    eratosthenes();
    while(C--) {
        cin>>A>>B;
        if(solve(A, B)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}