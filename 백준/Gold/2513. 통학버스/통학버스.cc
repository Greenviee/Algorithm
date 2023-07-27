#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K, S;
int apart[30001], students[30001];
priority_queue<pair<int, int>> rightside;
priority_queue<pair<int, int>> leftside;

int schoolbus() {
    int ret = 0;
    
    int capacity = 0;
    while(!leftside.empty()) {
        if(capacity==K) {
            capacity = 0;
            continue;
        }
        int dist = leftside.top().first;
        int cnt = leftside.top().second;
        leftside.pop();
        if(capacity==0) {
            ret += dist*2;
            if(cnt+capacity<=K) capacity += cnt;
            else leftside.push(make_pair(dist, cnt-K));
        }
        else {
            if(cnt+capacity<=K) capacity += cnt;
            else {
                leftside.push(make_pair(dist, cnt-(K-capacity)));
                capacity = K;
            }
        }
    }
    
    capacity = 0;
    while(!rightside.empty()) {
        if(capacity==K) {
            capacity = 0;
            continue;
        }
        int dist = rightside.top().first;
        int cnt = rightside.top().second;
        rightside.pop();
        if(capacity==0) {
            ret += dist*2;
            if(cnt+capacity<=K) capacity += cnt;
            else rightside.push(make_pair(dist, cnt-K));
        }
        else {
            if(cnt+capacity<=K) capacity += cnt;
            else {
                rightside.push(make_pair(dist, cnt-(K-capacity)));
                capacity = K;
            }
        }
    }
    return ret;
}

int main() {
    cin>>N>>K>>S;
    for(int i=0;i<N;i++) {
        cin>>apart[i]>>students[i];
        if(apart[i]<S) leftside.push(make_pair(S-apart[i], students[i]));
        else rightside.push(make_pair(apart[i]-S, students[i]));
    }
    cout<<schoolbus();
}