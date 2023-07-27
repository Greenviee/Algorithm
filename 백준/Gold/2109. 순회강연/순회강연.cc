#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, day[10001], pay[10001];

int earn() {
    if(N==0) return 0;
    int ret = 0;
    vector<pair<int, int>> speech;
    for(int i=0;i<N;i++) speech.push_back(make_pair(-day[i], i));
    priority_queue<int> pq;
    sort(speech.begin(), speech.end());
    
    int idx = 0, max_day = -speech[0].first;
    for(int i=max_day;i>0;i--) {
        while(idx<N && -speech[idx].first>=i) {
            pq.push(pay[speech[idx].second]);
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
    for(int i=0;i<N;i++) cin>>pay[i]>>day[i];
    int answer = earn();
    cout<<answer;
}