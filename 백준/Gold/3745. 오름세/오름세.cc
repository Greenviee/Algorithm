#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int stock[100001];
vector<int> lis;

int LIS() {
    lis.clear();
    for(int i=0;i<N;i++) {
        if(lis.empty()) {
            lis.push_back(stock[i]);
            continue;
        }
        if(lis.back()<stock[i]) lis.push_back(stock[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), stock[i]) - lis.begin();
            lis[idx] = stock[i];
        }
    }
    return lis.size();
}

int main() {
    while(cin>>N) {
        for(int i=0;i<N;i++) cin>>stock[i];
        int answer = LIS();
        cout<<answer<<endl;
    }
}