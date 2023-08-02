#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

enum Alphabet {
    A, E, I, O, U,
};

int N;
int cache[1<<16][5];
string words[16];

int wordchain(int state, int here) {
    //마지막 글자
    char tail = words[here][words[here].length()-1];
    
    int& ret = cache[state][Alphabet(tail)];
    if(ret!=-1) return ret;
    ret = 0;
    
    //뒤에 연결할 수 있는 단어들 찾기
    int canUse = state^((1<<N)-1);
    for(int i=0;i<N;i++) {
        if(canUse&(1<<i)) {
            if(tail!=words[i][0]) canUse^=(1<<i);
        }
    }
    //뒤에 연결할 수 있는 단어가 없는 경우
    if(canUse==0) return ret;
    //단어 연결
    for(int i=0;i<N;i++) {
        if(canUse&(1<<i)) {
            int len = words[i].length();
            ret = max(ret, len + wordchain(state|(1<<i), i));
        }
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>words[i];
    memset(cache, -1, sizeof(cache));
    int answer = 0;
    for(int i=0;i<N;i++) {
        int len = words[i].length();
        answer = max(answer, len + wordchain(1<<i, i));
    }
    cout<<answer;
}
