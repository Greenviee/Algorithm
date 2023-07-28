#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, n, put;
    cin>>N>>M;
    vector<int> num;
    for(int i=0;i<N;i++) {
        cin>>n;
        if(i==0) put = n;
        else put = n+num[i-1];
        num.push_back(put);
    }
    int h, t;
    vector<int> answer;
    for(int i=0;i<M;i++) {
        cin>>h>>t;
        int a = num[t-1] - num[h-2];
        answer.push_back(a);
    }
    for(int i=0;i<answer.size();i++) {
        cout<<answer[i]<<"\n";
    }
}
