#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
vector<int> arr;
vector<int> answer;

void LIS() {
    for(int i=0;i<arr.size();i++) {
        int n = arr[i];
        if(answer.empty()) {
            answer.push_back(n);
            continue;
        }
        if(n>answer.back()) answer.push_back(n);
        else {
            int idx = lower_bound(answer.begin(), answer.end(), n) - answer.begin();
            answer[idx] = n;
        }
    }
}

int main() {
    cin>>N;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        arr.push_back(a);
    }
    LIS();
    cout<<answer.size()<<endl;
}