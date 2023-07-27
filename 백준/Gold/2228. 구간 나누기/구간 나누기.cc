#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N, M;
int arr[101];
int cache[101][51];

//start번째 수 부터 section개의 부분으로 나눌 때 합 최대
int divide(int start, int section) {
    if(section==0) return 0;
    if(start>=N) return -INF;
    
    int& ret = cache[start][section];
    if(ret>-INF-1000) return ret;
    ret = -INF;
    
    int sum = 0;
    //start부터 i까지 한 부분
    for(int i=start;i<N;i++) {
        sum += arr[i];
        for(int j=i+2;j<N+2;j++) {
            ret = max(ret, sum + divide(j, section-1));
        }
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<=M;j++)
            cache[i][j] = -INF*2;
    for(int i=0;i<N;i++) cin>>arr[i];
    int answer = -INF;
    for(int i=0;i<N;i++) answer = max(answer, divide(i, M));
    cout<<answer;
}