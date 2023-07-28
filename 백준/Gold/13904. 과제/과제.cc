#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int deadline[1001], score[1001];

int maxscore() {
    int ret = 0;
    vector<pair<int, int>> problem;
    for(int i=0;i<N;i++) problem.push_back(make_pair(-deadline[i], i));
    sort(problem.begin(), problem.end());
    priority_queue<int> pq;
    
    int idx = 0, max_deadline = -problem[0].first;
    for(int i=max_deadline;i>0;i--) {
        while(idx<N && -problem[idx].first>=i) {
            pq.push(score[problem[idx].second]);
            idx++;
        }
        if(!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>deadline[i]>>score[i];
    cout<<maxscore();
}