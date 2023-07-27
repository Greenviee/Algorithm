#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, C, M;
priority_queue<pair<int, int>> box[2001];
//goal[end] : end로 가는 택배 개수
int goal[2001];

int delivery() {
    int ret = 0;
    int capacity = 0;
    int farthest = 0;
    
    for(int i=1;i<=N;i++) {
        //택배 내리기
        ret += goal[i];
        capacity -= goal[i];
        // cout<<"내리는 마을: "<<i<<" 개수: "<<goal[i]<<endl;
        
        //택배 싣기
        while(!box[i].empty()) {
            int d = -box[i].top().first;
            int cnt = box[i].top().second;
            box[i].pop();
            //택배를 차에 다 실을 수 있는 경우
            if(capacity+cnt<=C) {
                goal[d] += cnt;
                capacity += cnt;
                farthest = max(farthest, d);
                // cout<<"실은 택배 목적지: "<<d<<" 개수: "<<cnt<<endl;
            }
            //택배를 차에 다 싣지 못하는 경우
            else {
                //빈 공간부터 채우기
                int left = C - capacity;
                goal[d] += left;
                capacity += left;
                farthest = max(farthest, d);
                // cout<<"실은 택배 목적지: "<<d<<" 개수: "<<left<<endl;
                
                //남은 택배의 목적지보다 멀리 있는 택배 내리기
                while(d<farthest) {
                    if(goal[farthest]>=left) {
                        goal[farthest] -= left;
                        goal[d] += left;
                        if(goal[farthest]==0) farthest--;
                        break;
                    }
                    else {
                        left -= goal[farthest];
                        goal[d] += goal[farthest];
                        goal[farthest] = 0;;
                        farthest--;
                    }
                }
            }
        }
    }
    return ret;
}

int main() {
    cin>>N>>C>>M;
    int n1, n2, count;
    for(int i=0;i<M;i++) {
        cin>>n1>>n2>>count;
        box[n1].push(make_pair(-n2, count));
    }
    cout<<delivery();
}