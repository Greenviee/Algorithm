#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X, a, b;
    int total = 0;
    cin>>X;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>a>>b;
        total += a*b;
    }
    if(X==total) cout<<"Yes";
    else cout<<"No";
}