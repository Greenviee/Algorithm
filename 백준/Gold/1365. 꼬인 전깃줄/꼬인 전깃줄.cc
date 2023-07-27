#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int pole[100001];
vector<int> lis;

int LIS() {
    for(int i=0;i<N;i++) {
        if(lis.empty()) {
            lis.push_back(pole[i]);
            continue;
        }
        if(lis.back()<pole[i]) lis.push_back(pole[i]);
        else {
            int idx = upper_bound(lis.begin(), lis.end(), pole[i]) - lis.begin();
            lis[idx] = pole[i];
        }
    }
    return lis.size();
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>pole[i];
    int answer = N - LIS();
    cout<<answer;
}