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
int N;
double xpos[MAX_N], ypos[MAX_N];
double dist[MAX_N][MAX_N];
double cache[1<<16][MAX_N];

//마을 간 거리를 배열로 저장
void precalc() {
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dist[i][j] = sqrt((xpos[i]-xpos[j])*(xpos[i]-xpos[j]) + (ypos[i]-ypos[j])*(ypos[i]-ypos[j]));
}

//모든 마을을 방문하였는가?
bool allVisited(int state) {
    int i = 1;
    while(i<(1<<N)) {
        //방문하지 않은 마을일 경우
        if(!(state&i)) return false;
        i<<=1;
    }
    return true;
}

double TSP(int visited, int here) {
    //기저조건 : 모든 마을을 다 돈 경우 (언제나 시작은 0번 마을)
    if(allVisited(visited)) return dist[0][here];
    double& ret = cache[visited][here];
    if(ret!=-1) {
        return ret;
    }
    ret = INF;
    
    //방문하지 않은 마을들
    int notVisit = ~visited;
    for(int i=0;i<N;i++) {
        if(notVisit & (1<<i)) 
            ret = min(ret, dist[here][i] + TSP(visited|(1<<i), i));
    }
    return ret;
}
        

int main() {
    cout<<fixed; cout.precision(6);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>xpos[i]>>ypos[i];
    
    for(int i=0;i<(1<<16);i++) 
        for(int j=0;j<N;j++)
            cache[i][j] = -1;
    precalc();
    
    double answer = TSP(1, 0);
    cout<<answer;
}