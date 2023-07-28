#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin>>N;
    stack<int> money;
    int put;
    for(int i=0;i<N;i++) {
        cin>>put;
        if(put==0) money.pop();
        else money.push(put);
    }
    int sum = 0;
    while(!money.empty()) {
        sum += money.top();
        money.pop();
    }
    cout<<sum;
}