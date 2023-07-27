#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> jose;
    int N, K;
    int s, cnt;
    cnt = 0;
    cin>>N>>K;
    cout<<"<";
    for(int i=1;i<=N;i++) jose.push(i);
    while(!jose.empty()) {
        for(int i=0;i<K-1;i++) {
            s = jose.front();
            jose.pop();
            jose.push(s);
        }
        cnt++;
        if(cnt==N) cout<<jose.front();
        else cout<<jose.front()<<", ";
        jose.pop();
    }
    cout<<">";
}