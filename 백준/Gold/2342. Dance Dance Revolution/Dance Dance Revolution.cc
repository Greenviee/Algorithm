#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int pattern[100001];
int cache[5][5][100001];

//energy(현 위치, 이동할 곳)
int energy(int here, int togo) {
    if(here==0) return 2;
    else if(abs(here-togo)==2) return 4;
    else if(here==togo) return 1;
    else return 3;
}

//move(두 발 위치, 시작점), n1<n2
int move(int n1, int n2, int start) {
    //종료
    if(pattern[start]==0) return 0;
    //불변조건
    if(n1>n2) swap(n1, n2);
    //초기 상태가 아닌데 두 발이 같은 위치에 있는 경우
    if(n1==n2 && n1!=0 && n2!=0) return INF;
    
    int& ret = cache[n1][n2][start];
    if(ret!=-1) return ret;
    ret = 0;
    
    ret = min(energy(n1, pattern[start]) + move(pattern[start], n2, start+1), energy(n2, pattern[start]) + move(n1, pattern[start], start+1));
    return ret;
}

int main() {
    int n;
    int idx = 0;
    while(1) {
        cin>>n;
        if(n==0) break;
        pattern[idx] = n;
        idx++;
    }
    memset(cache, -1, sizeof(cache));
    int answer = move(0, 0, 0);
    cout<<answer;
}