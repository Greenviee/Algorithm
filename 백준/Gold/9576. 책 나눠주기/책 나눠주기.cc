#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, M;
int bookstart[1001], bookend[1001];

int give() {
    int ret = 0;
    vector<pair<int, int>> books;
    for(int i=0;i<M;i++) books.push_back(make_pair(bookstart[i], i));
    sort(books.begin(), books.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int idx = 0;
    for(int i=1;i<=N;i++) {
        while(idx<M && books[idx].first<=i) {
            pq.push(bookend[books[idx].second]);
            idx++;
        }
        while(!pq.empty()) {
            if(pq.top()>=i) {
                pq.pop();
                ret++;
                break;
            }
            else pq.pop();
        }
    }
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>N>>M;
        for(int i=0;i<M;i++) cin>>bookstart[i]>>bookend[i];
        int answer = give();
        cout<<answer<<endl;
    }
}