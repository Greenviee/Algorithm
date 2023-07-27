#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

long long minimum, maximum;
const int MAX_N = 1000001;
bool isPrime[MAX_N+1];
vector<long long> squarenum;

void eratosthenes() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    int sqrtn = sqrt(MAX_N);
    for(int i=2;i<=sqrtn;i++) {
        if(isPrime[i])
            for(int j=i*i;j<=MAX_N;j+=i)
                isPrime[j] = false;
    }
    //maximum이하인 소수의 제곱수 구하기
    for(long long i=2;i<=MAX_N;i++) {
        if(isPrime[i]) {
            if(i*i<=maximum) squarenum.push_back(i*i);
            else break;
        }
    }
}

long long square() {
    long long ret = 0;
    bool isAnswer[1000001];
    memset(isAnswer, 1, sizeof(isAnswer));
    for(int i=0;i<squarenum.size();i++) {
        long long n = squarenum[i];
        long long start = (minimum/n)*n;
        if(start<minimum) start += n;
        for(long long j=start;j<=maximum;j+=n) {
            isAnswer[j-minimum] = false;
        }
    }
    for(long long i=minimum;i<=maximum;i++)
        if(isAnswer[i-minimum]) ret++;
    return ret;
}

int main() {
    cin>>minimum>>maximum;
    eratosthenes();
    cout<<square();
}