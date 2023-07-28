#include <iostream>
#include <cstring>
using namespace std;

const long long MOD = 1000000000;
long long cache[101][10];
int n;

//len = 길이, num = 수
long long stairnum(int len, int num) {
    if(len==n-1) return 1;
    long long& ret = cache[len][num];
    if(ret!=-1) return ret;
    
    ret = 0;
    if(num==0) ret += stairnum(len+1, num+1);
    else if(num==9) ret += stairnum(len+1, num-1);
    else {
        ret += stairnum(len+1, num-1);
        ret += stairnum(len+1, num+1);
    }
    ret %= MOD;
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin>>n;
    long long answer = 0;
    for(int i=1;i<10;i++) {
        answer += stairnum(0, i);
        answer %= MOD;
    }
    cout<<answer<<endl;
}