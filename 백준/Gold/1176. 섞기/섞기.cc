#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

const int MAX_N = 16;
int N, K;
int height[MAX_N];
long long cache[1<<16][16];

int cntone(int n) {
    int ret = 0;
    int i = 1;
    while(i<(1<<N)) {
        if(n&i) ret++;
        i<<=1;
    }
    return ret;
}

//punishment(배열한 학생들, 옆에 새로운 학생을 세울 학생)
long long punishment(int state, int before) {
    //모든 학생을 세운 경우
    if(state==((1<<N)-1)) return 1;
    long long& ret = cache[state][before];
    if(ret!=-1) return ret;
    ret = 0;
    
    //옆에 설 수 있는 학생들 찾기
    int canstand = state^((1<<N)-1);
    for(int i=0;i<N;i++) {
        if(canstand&(1<<i)) {
            //두 학생의 키 차이가 K보다 작거나 같을 경우
            if(abs(height[before]-height[i])<=K)
                canstand^=(1<<i);
        }
    }
    //옆에 설 수 있는 학생이 없는 경우
    if(canstand==0) return ret;
    
    for(int i=0;i<N;i++) {
        if(canstand&(1<<i))
            ret += punishment(state|(1<<i), i);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>height[i];
    long long answer = 0;
    for(int i=0;i<N;i++) 
        answer += punishment(1<<i, i);
    cout<<answer<<endl;
}