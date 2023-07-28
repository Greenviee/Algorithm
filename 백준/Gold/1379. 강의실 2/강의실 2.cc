#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int start[100001], endtime[100001];
//배정된 교실
int room[100001];

int solve() {
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<N;i++) pq.push(make_pair(-start[i], i));
    priority_queue<pair<int, int>> classroom;
    
    //강의실 번호
    int idx = 1;
    for(int i=0;i<N;i++) {
        if(classroom.empty()) {
            classroom.push(make_pair(-endtime[pq.top().second], idx));
            room[pq.top().second] = idx;
            idx++;
        }
        else {
            //들어갈 수 있는 강의실이 있는 경우
            if(-classroom.top().first<=-pq.top().first) {
                room[pq.top().second] = classroom.top().second;
                classroom.push(make_pair(-endtime[pq.top().second], classroom.top().second));
                classroom.pop();
            }
            else {
                classroom.push(make_pair(-endtime[pq.top().second], idx));
                room[pq.top().second] = idx;
                idx++;
            }
        }
        pq.pop();
    }
    return idx-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        cin>>start[a-1]>>endtime[a-1];
    }
    cout<<solve()<<"\n";
    for(int i=0;i<N;i++) cout<<room[i]<<"\n";
}