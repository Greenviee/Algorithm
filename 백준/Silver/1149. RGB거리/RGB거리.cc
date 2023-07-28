#include <iostream>
#include <cstring>
using namespace std;

const int INF = 98765432;
int cache[1001][3];
int cost[1001][3];
int Num;

//N번째, 색상 color일 때 최솟값
int coloring(int N, int color) {
    if(N==Num) return 0;
    int& ret = cache[N][color];
    if(ret!=-1) return ret;
    ret = INF;
    for(int i=0;i<3;i++) {
        if(color!=i) 
            ret = min(ret, coloring(N+1, i));
    }
    ret += cost[N][color];
    return ret;
}

int main() {
    cin>>Num;
    memset(cache, -1, sizeof(cache));
    memset(cost, 0, sizeof(cost));
    for(int i=0;i<Num;i++) {
        for(int j=0;j<3;j++)
            cin>>cost[i][j];
    }
    int answer = INF;
    for(int i=0;i<3;i++) 
        answer = min(answer, coloring(0, i));
    
    cout<<answer<<endl;
}