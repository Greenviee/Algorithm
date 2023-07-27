#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    int N, x, k;
    cin>>N;
    priority_queue<int> pq;
    for(int i=0;i<N;i++) {
        cin>>x;
        if(x==0) {
            if(pq.empty()) cout<<"0"<<"\n";
            else {
                k = pq.top();
                pq.pop();
                cout<<k<<"\n";
            }
        }
        else {
            pq.push(x);
        }
    }
}