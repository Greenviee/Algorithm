#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
string antic[50];
int learned[26];

int howmanyread() {
    int answer = 0;
    for(int i=0;i<N;i++) {
        bool ok = true;
        for(int j=4;j<antic[i].length()-4;j++) {
            if(learned[antic[i][j] - 'a']==0) {
                ok = false;
                break;
            }
        }
        if(ok) answer++;
    }
    return answer;
}

int teach(int N, int b) {
    //가르칠 수 있는 횟수 종료
    if(N<0) return 0;
    if(N==0) return howmanyread();
    
    int ret = 0;
    for(int i=b+1;i<26;i++) {
        if(learned[i]==0) {
            learned[i] = 1;
            ret = max(ret, teach(N-1, i));
            learned[i] = 0;
        }
    }
    return ret;
}

int main() {
    cin>>N>>K;
    for(int i=0;i<N;i++) 
        cin>>antic[i];
    
    //5개 미만일 경우 남극언어에 포함되는 기본 글자(a, n, t, i, c) 보다 적기 때문에 읽을 수 있는 단어가 없음.
    //a, c, i, n, t 
    learned[0] = learned[2] = learned[8] = learned[13] = learned[19] = 1;
    
    int answer = teach(K-5, -1);
    cout<<answer;
}