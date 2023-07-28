#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
//cache[num] : num개의 칸을 채울 수 있는 경우의 수
int cache[31];

int solve(int N) {
    if(N==0) return 1;
    else if(N<0) return 0;
    int& ret = cache[N];
    if(ret!=-1) return ret;
    ret = 0;
    
    //2칸을 다 채우는 경우 : 3가지
    ret += solve(N-2) * 3;
    
    //L자 형태로 2칸이 채워져 있는 경우
    for(int i=N-4;i>=0;i-=2) 
        ret += solve(i)*2;
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin>>N;
    int answer = solve(N);
    cout<<answer;
}