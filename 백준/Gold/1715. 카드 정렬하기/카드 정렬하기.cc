#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>k;
        pq.push(k);
    }
    int a, b;
    int answer = 0;
    for(int i=0;i<n-1;i++) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        pq.push(a+b);
        answer += a+b;
    }
    
    if(n==1) answer = 0;
    cout<<answer;
}