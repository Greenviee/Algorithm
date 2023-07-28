#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int MOD = 1000000;
string code;
int cache[5001];

int decode(int start) {
    if(start==code.length()) return 1;
    if(code[start]<'1' || code[start]>'9') return 0;
    
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = 0;
    
    if(code[start]=='1') {
        if(start+1<code.length()) {
            ret += decode(start+1);
            ret += decode(start+2);
        }
        else ret += decode(start+1);
    }
    else if(code[start]=='2') {
        if(start+1<code.length() && code[start+1]>='0' && code[start+1]<='6') {
            ret += decode(start+1);
            ret += decode(start+2);
        }
        else ret += decode(start+1);
    }
    else ret += decode(start+1);
    return ret%MOD;
}

int main() {
    cin>>code;
    memset(cache, -1, sizeof(cache));
    int answer = decode(0)%MOD;
    cout<<answer;
}