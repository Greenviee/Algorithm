#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, v, x;
    vector<int> ve;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>x;
        ve.push_back(x);
    }
    cin>>v;
    int answer = 0;
    for(int i=0;i<N;i++) {
        if(ve[i]==v) answer++;
    }
    cout<<answer<<endl;
}
