#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

const int INF = 987654321;
const int MAX_N = 20;
int N;
int cost[MAX_N][MAX_N];
int cache[1<<20][20];

//employee : 일을 하고 있는 직원 비트마스킹
//work : work번째 일을 할 차례(work 이전의 일들은 완료) , total : 이전 작업들 비용
int solution(int employee, int work) {
    if(work==N) return 0;
    
    int& ret = cache[employee][work];
    if(ret!=-1) return ret;
    ret = INF;
    
    //일을 하고 있지 않은 직원
    int notWorking = ~employee;
    for(int i=0;i<N;i++) {
        if(notWorking & (1<<i)) 
            ret = min(ret, cost[i][work] + solution((employee|(1<<i)), work+1));
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>cost[i][j];
    memset(cache, -1, sizeof(cache));
    
    int answer = solution(0, 0);
    cout<<answer<<endl;
}