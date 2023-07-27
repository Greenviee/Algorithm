#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, A, B;
int K[1000], dist_A[1001], dist_B[1001];

int balloon() {
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<N;i++) pq.push(make_pair(abs(dist_A[i]-dist_B[i]), i));
    int use_A = 0, use_B = 0, ret = 0;
    while(!pq.empty()) {
        int team = pq.top().second;
        pq.pop();
        //한 쪽의 풍선이 없는 경우
        if(use_A==A || use_B==B) {
            if(use_A==A) ret += dist_B[team]*K[team];
            else ret += dist_A[team]*K[team];
            continue;
        }
        
        if(dist_A[team]>dist_B[team]) {
            //가까운 쪽에서 모든 풍선을 받을 수 있는 경우
            if(K[team]+use_B<=B) {
                use_B += K[team];
                ret += dist_B[team]*K[team];
            }
            //가까운 쪽에서 모든 풍선을 못 받는 경우
            else {
                ret += dist_B[team]*(B-use_B);
                //가까운 쪽에서 못받은 풍선 수
                int left = K[team] - (B-use_B);
                use_B = B;
                ret += dist_A[team]*left;
                use_A += left;
            }
        }
        else {
            //가까운 쪽에서 모든 풍선을 받을 수 있는 경우
            if(K[team]+use_A<=A) {
                use_A += K[team];
                ret += dist_A[team]*K[team];
            }
            //가까운 쪽에서 모든 풍선을 못 받는 경우
            else {
                ret += dist_A[team]*(A-use_A);
                //가까운 쪽에서 못받은 풍선 수
                int left = K[team] - (A-use_A);
                use_A = A;
                ret += dist_B[team]*left;
                use_B += left;
            }
        }
    }
    return ret;
}

int main() {
    while(1) {
        cin>>N>>A>>B;
        if(N==0) break;
        for(int i=0;i<N;i++) cin>>K[i]>>dist_A[i]>>dist_B[i];
        cout<<balloon()<<endl;
    }
}