#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int n, k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>k;
        if(maxheap.size()==minheap.size()) maxheap.push(k);
        else minheap.push(k);
        if(!maxheap.empty() && !minheap.empty() && maxheap.top()>minheap.top()) {
            int a = maxheap.top();
            int b = minheap.top();
            maxheap.pop(); minheap.pop();
            maxheap.push(b); minheap.push(a);
        }
        cout<<maxheap.top()<<"\n";
    }
}