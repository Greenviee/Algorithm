#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
const int MAX_N = 100000000;
bool isPrime[MAX_N+1];
vector<int> answer;

void eratosthenes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<=sqrt(MAX_N);i++) {
        if(isPrime[i])
            for(int j=i*i;j<=MAX_N;j+=i)
                isPrime[j] =false;
    }
}

void solve() {
    answer.clear();
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
    eratosthenes();
    while(cin>>N) {
        solve();
        if(answer.size()==1) cout<<"Impossible.";
        else for(int i=0;i<answer.size();i++) cout<<answer[i]<<' ';
        cout<<endl;
    }
}