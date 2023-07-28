#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
long long price;
vector<int> division;

void divide(long long p) {
    division.clear();
    while(p!=0) {
        division.push_back(p%100);
        p /= 100;
    }
}

int pay() {
    int ret = 0;
    for(int i=0;i<division.size();i++) {
        int num = division[i];
        int cnt = INF;
        for(int j=0;j<=num/25;j++) {
            int a = j;
            int p = num;
            p -= 25*j;
            a += p/10;
            a += p%10;
            cnt = min(cnt, a);
        }
        ret += cnt;
    }
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>price;
        divide(price);
        cout<<pay()<<endl;
    }
}