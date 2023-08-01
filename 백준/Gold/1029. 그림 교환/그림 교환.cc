#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

const int MAX_N = 15;
int N;
int sell[MAX_N][MAX_N];
int cache[1<<15][15][10];

int cntone(int n) {
    int ret = 0;
    int i = 1;
    while(i<(1<<N)) {
        if(n&i) ret++;
        i<<=1;
    }
    return ret;
}

//sellpicture(소유했던 사람들, 현 소유자, 현 소유자가 구매해온 가격)
int sellpicture(int state, int seller, int cost) {
    int& ret = cache[state][seller][cost];
    if(ret!=-1) return ret;
    ret = 0;
    
    //cansell : 팔 수 있는 사람 목록
    int cansell = state^((1<<N)-1);
    //cansell에서 사온 가격보다 판매 가격이 작아서 못파는 경우 제외
    for(int i=0;i<N;i++) {
        if(cansell&(1<<i)) {
            if(cost>sell[seller][i])
                cansell^=(1<<i);
        }
    }
    //팔 수 있는 사람이 0명인 경우
    if(cntone(cansell)==0) return ret = cntone(state);
    //판매
    for(int i=0;i<N;i++) {
        if(cansell&(1<<i)) 
            ret = max(ret, sellpicture(state|(1<<i), i, sell[seller][i]));
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        for(int j=0;j<N;j++)
            sell[i][j] = s[j] - '0';
    }
    memset(cache, -1, sizeof(cache));
    int answer = sellpicture(1, 0, 0);
    cout<<answer;
}