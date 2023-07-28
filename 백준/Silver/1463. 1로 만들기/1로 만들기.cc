#include <iostream>
#include <cstring>
using namespace std;

int cache[1000001];
int N;
const int INF = 98765432;

int makeone(int N) {
    if(N==1) return 0;
    int& ret = cache[N];
    if(ret!=-1) return ret;
    
    ret = INF;
    if(N%2==0) ret = min(ret, makeone(N/2));
    if(N%3==0) ret = min(ret, makeone(N/3));
    ret = min(ret, makeone(N-1));
    ret+=1;
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin>>N;
    int answer = makeone(N);
    cout<<answer<<endl;
}