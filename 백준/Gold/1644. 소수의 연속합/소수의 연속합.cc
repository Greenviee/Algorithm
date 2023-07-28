#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 4000000;
int N;
vector<int> prime;
bool isPrime[MAX_N+1];

void eratothenes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    int sqrtn = sqrt(N);
    for(int i=2;i<=sqrtn;i++) {
        if(isPrime[i]) 
            for(int j=i*i;j<=N;j+=i)
                isPrime[j] = false;
        
    }
    for(int i=2;i<=N;i++) 
        if(isPrime[i]) prime.push_back(i);
}

int solve() {
    int ret = 0;
    int sum = 0;
    queue<int> q;
    for(int i=0;i<prime.size();i++) {
        sum += prime[i];
        q.push(prime[i]);
        if(sum==N) {
            ret++;
            sum -= q.front();
            q.pop();
        }
        while(sum>N) {
            sum -= q.front();
            q.pop();
            if(sum==N) ret++;
        }
    }
    return ret;
}

int main() {
    cin>>N;
    eratothenes();
    cout<<solve();
}
