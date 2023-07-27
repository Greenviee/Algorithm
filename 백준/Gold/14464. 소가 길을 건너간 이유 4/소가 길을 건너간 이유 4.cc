#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int C, N;
vector<int> chicken;
vector<pair<int, int>> cows;

int crossing() {
    //먼저 출발하는 순서로 정렬
    sort(chicken.begin(), chicken.end());
    sort(cows.begin(), cows.end());
    
    int ret = 0;
    //끝나는 시간을 저장하는 우선순위 큐
    priority_queue<int> pq;
    int idx = 0;
    for(int i=0;i<C;i++) {
        int timing = chicken[i];
        while(idx<N && cows[idx].first<=timing) {
            //닭이 지나는 시간 전에 건넌 소 제외
            if(cows[idx].second<timing) idx++;
            //닭이랑 같이 건널 수 있는 소 우선순위 큐에 추가
            else {
                pq.push(-cows[idx].second);
                idx++;
            }
        }
        //닭이 지나는 시간 전에 건넌 소들 우선순위 큐에서 제거 후 건너기
        while(!pq.empty() && -pq.top()<timing) pq.pop();
        
        if(!pq.empty()) {
            ret++;
            pq.pop();
        }
    }
    return ret;
}

int main() {
    cin>>C>>N;
    int n;
    for(int i=0;i<C;i++) {
        cin>>n;
        chicken.push_back(n);
    }
    int n1, n2;
    for(int i=0;i<N;i++) {
        cin>>n1>>n2;
        cows.push_back(make_pair(n1, n2));
    }
    cout<<crossing();
}