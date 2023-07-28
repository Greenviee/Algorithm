#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K;
int presenter[100001], t[100001];
//N번 출제자가 출제한 문제 개수
int used[100001];

void question() {
    memset(used, 0, sizeof(used));
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<N;i++) {
        pq.push(make_pair(-used[presenter[i]], -t[i]));
        used[presenter[i]]++;
    }

    long long sum = 0;
    priority_queue<int> answer;
    //L이 1부터 N까지일때 출력
    for(int i=1;i<=N;i++) {
        while(!pq.empty() && -pq.top().first<i) {
            answer.push(-pq.top().second);
            sum += -pq.top().second;
            pq.pop();
        }
            
        if(answer.size()<K) {
            cout<<-1<<' ';
            continue;
        }
        while(answer.size()>K) {
            sum -= answer.top();
            answer.pop();
        }
        cout<<sum<<' ';
    }
}

int main() {
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>presenter[i];
    for(int i=0;i<N;i++) cin>>t[i];
    question();
}