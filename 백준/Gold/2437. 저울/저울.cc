#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
vector<int> weight;

int solve() {
    sort(weight.begin(), weight.end());
    int sum = 0;
    for(int i=0;i<N;i++) {
        if(weight[i]==1) sum++;
        else {
            if(sum<weight[i]-1) return sum+1;
            else sum += weight[i];
        }
    }
    return sum+1;
}

int main() {
    cin>>N;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        weight.push_back(a);
    }
    int answer = solve();
    cout<<answer;
}