#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K;
string num;

string solve() {
    string answer;
    priority_queue<pair<char, int>> pq;
    //이전에 사용한 숫자가 몇번째 숫자인가
    int before = -1;
    for(int i=0;i<K;i++) pq.push(make_pair(num[i], -i));
    for(int i=K;i<N;i++) {
        pq.push(make_pair(num[i], -i));
        while(1) {
            if(-pq.top().second>before) {
                answer += pq.top().first;
                before = -pq.top().second;
                pq.pop();
                break;
            }
            else pq.pop();
        }
    }
    return answer;
}

int main() {
    cin>>N>>K>>num;
    cout<<solve();
}