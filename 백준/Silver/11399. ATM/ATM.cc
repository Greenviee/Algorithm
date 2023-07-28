#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, t;
    cin>>N;
    vector<int> Time;
    int total = 0;
    for(int i=0;i<N;i++) {
        cin>>t;
        Time.push_back(t);
    }
    sort(Time.begin(), Time.end());
    for(int i=0;i<N;i++) 
        total += Time[i]*(N-i);
    cout<<total;
}