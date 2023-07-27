#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, x;
    cin>>N;
    vector<int> v;
    for(int i=0;i<N;i++) {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) cout<<v[i]<<"\n";
}