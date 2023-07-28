#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <tuple>
using namespace std;

int N;
vector<tuple<int, int, int>> flowering;
vector<pair<int, int>> falling;

int solve() {
    int cnt = 0;
    int fall_month = 3;
    int fall_day = 1;
    sort(flowering.begin(), flowering.end());
    priority_queue<pair<int, int>> pq;
    int idx = 0;
    while(idx<=N) {
        if(idx==N) {
            if(pq.empty()) return 0;
            pair<int, int> last = pq.top();
            if(last.first>11 || (last.first==11 && last.second>30)) {
                return cnt+1;
            }
            else return 0;
        }
        
        int month = get<0>(flowering[idx]);
        int day = get<1>(flowering[idx]);
        if(month<fall_month || (month==fall_month && day<=fall_day)) {
            pq.push(falling[get<2>(flowering[idx])]);
            idx++;
        }
        else {
            if(pq.empty()) return 0;
            pair<int, int> new_day = pq.top();
            pq.pop();
            //불가능한 경우
            if(new_day.first<fall_month || (new_day.first==fall_month && new_day.second<fall_day)) return 0;
            fall_month = new_day.first;
            fall_day = new_day.second;
            cnt++;
            if(fall_month>11 || (fall_month==11 && fall_day>30)) return cnt;
        }
    }
    return cnt;
}

int main() {
    cin>>N;
    int m1, m2, d1, d2;
    for(int i=0;i<N;i++) {
        cin>>m1>>d1>>m2>>d2;
        flowering.push_back(make_tuple(m1, d1, i));
        falling.push_back(make_pair(m2, d2));
    }
    cout<<solve();
}