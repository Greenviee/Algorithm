#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
bool isPrime[1000001];
vector<int> answer;

void eratosthenes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<=1000;i++) {
        if(isPrime[i])
            for(int j=i*i;j<=N;j+=i)
                isPrime[j] =false;
    }
}

void solve() {
    if(N<8) {
        answer.push_back(-1);
        return;
    }
    
    if(N%2==1) {
        answer.push_back(2);
        answer.push_back(3);
        N-=5;
    }
    else {
        answer.push_back(2);
        answer.push_back(2);
        N-=4;
    }
    
    for(int i=2;i<=N;i++) {
        if(isPrime[N-i]) {
            answer.push_back(i);
            answer.push_back(N-i);
            break;
        }
    }
}

int main() {
    cin>>N;
    eratosthenes();
    solve();
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<' ';
}