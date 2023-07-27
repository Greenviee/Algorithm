#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

//n개로 만들 수 있는 수 중 가장 작은 수
string minimum[8];
int N;
string cache[101];

void precalc() {
    minimum[2] = "1";
    minimum[3] = "7";
    minimum[4] = "4";
    minimum[5] = "2";
    minimum[6] = "0";
    minimum[7] = "8";
}

string matches_max(int N) {
    string s = "";
    if(N%2==1) {
        s += '7';
        N -= 3;
    }
    for(int i=0;i<N/2;i++) s += '1';
    return s;
}

string matches_min(int N, bool isfirst) {
    if(N<2) return "------------";
    else if(N<=7) {
        if(isfirst && N==6) return "6";
        else return minimum[N];
    }
    
    string& ret = cache[N];
    if(cache[N]!="**********************************************") return ret;
    
    for(int i=2;i<=7;i++) {
        string new_s;
        if(isfirst && i==6) new_s = '6' + matches_min(N-i, 0);
        else new_s = minimum[i] + matches_min(N-i, 0);
        if(new_s.length()<ret.length()) ret = new_s;
        else if(new_s.length()==ret.length()) ret = min(ret, new_s);
    }
    
    return ret;
}

int main() {
    precalc();
    int C;
    cin>>C;
    while(C--) {
        cin>>N;
        for(int i=0;i<=N;i++) cache[i] = "**********************************************";
        cout<<matches_min(N, 1)<<' '<<matches_max(N)<<endl;
    }
}