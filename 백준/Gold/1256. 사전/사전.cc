#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N, M, K;
//len[N][M] : N, M개 남았을 때 문자열의 모든 경우의 수
int len[101][101];
//오버플로 방지
const int MAX = 1000000000;

int bino[201][201];
//필요한 이항계수 미리 계산
void calcBino() {
    memset(bino, 0, sizeof(bino));
    for(int i=0;i<=200;i++) {
        bino[i][0] = bino[i][i] = 1;
        for(int j=1;j<i;j++) {
            //파스칼의 삼각형
            bino[i][j] = min(MAX, bino[i-1][j-1] + bino[i-1][j]);
        }
    }
}

void precalc() {
    for(int i=0;i<=N;i++) 
        for(int j=0;j<=M;j++) 
            len[i][j] = bino[i+j][i];    
}

//a개의 a, z개의 z가 있을 경우skip번째 단어 구하기
string dict(int a, int z, int skip) {
    string answer;
    //기저조건
    if(a==0) {
        for(int i=0;i<z;i++) answer += 'z';
        return answer;
    }
    //시작이 z인 경우
    if(skip>len[a-1][z]) {
        answer = 'z' + dict(a, z-1, skip-len[a-1][z]);
    }
    else answer = 'a' + dict(a-1, z, skip);
    return answer;
}

int main() {
    cin>>N>>M>>K;
    calcBino();
    precalc();
    if(K>len[N][M]) cout<<-1;
    else {
        string answer = dict(N, M, K);
        cout<<answer;
    }
}