#include <iostream>
#include <string.h>
using namespace std;

long long cache[1000001];


long long zeroone(int n) {
    long long& ret = cache[n];
    if(ret!=-1) return ret;
    if(n==1) return ret = 1;
    else if(n==0) return ret = 1;

    ret = 0;
    ret += zeroone(n-1);
    ret += zeroone(n-2);
    return ret % 15746;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    int num;
    cin>>num;
    long long answer = zeroone(num) % 15746;
    if(num==0) cout<<0;
    else cout<<answer;
}