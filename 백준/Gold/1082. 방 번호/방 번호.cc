#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
    
int N, M;
int cost[10];
string cache[51];

string roomnum(int money) {
    if(money==0) return "";
    
    string& ret = cache[money];
    if(ret!="") return ret;
    
    for(int i=0;i<N;i++) {
        if(money==M && i==0) continue;
        if(money>=cost[i]) {
            string new_s = to_string(i) + roomnum(money-cost[i]);
            if(ret.length()<new_s.length()) ret = new_s;
            else if(ret.length()==new_s.length()) ret = max(ret, new_s);
        }
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>cost[i];
    cin>>M;
    for(int i=0;i<51;i++) cache[i] = "";
    string answer = roomnum(M);
    if(answer=="") cout<<'0';
    else cout<<answer;
}