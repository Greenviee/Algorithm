#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 987654321;
int k, n;
int c[4][1001];
vector<int> v1, v2;

//1, 2반을 합친 v1, 3, 4반을 합친 v2 계산 후 정렬
void precalc() {
    v1.clear(); v2.clear();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            v1.push_back(c[0][i]+c[1][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            v2.push_back(c[2][i]+c[3][j]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}

int solve() {
    int diff = INF;
    for(int i=0;i<v1.size();i++) {
        //v1[i]와 v2의 원소를 순차적으로 비교 후 가장 k와 가까운 값 구하기 (이분탐색)
        int n1 = v1[i];
        //불변조건 : v2[lo]는 k-n1보다 작거나 같다 & v2[hi]는 k-n1보다 크다
        int lo = 0, hi = v2.size()-1;
        if(n1+v2[lo]>k) {
            if(abs(diff)>abs(v2[lo]+n1-k)) diff = v2[lo]+n1-k;
            else if(abs(diff)==abs(v2[lo]+n1-k)) diff = min(diff, v2[lo]+n1-k);
            continue;
        }
        if(n1+v2[hi]<=k) {
            if(abs(diff)>abs(v2[hi]+n1-k)) diff = v2[hi]+n1-k;
            else if(abs(diff)==abs(v2[hi]+n1-k)) diff = min(diff, v2[hi]+n1-k);
            continue;
        }
        
        while(lo+1<hi) {
            int mid = (lo+hi)/2;
            if(n1+v2[mid]>k) 
                hi = mid;
            else
                lo = mid;
        }
        if(abs(diff)>abs(v2[lo]+n1-k)) diff = v2[lo]+n1-k;
        else if(abs(diff)==abs(v2[lo]+n1-k)) diff = min(diff, v2[lo]+n1-k);
        if(abs(diff)>abs(v2[hi]+n1-k)) diff = v2[hi]+n1-k;
        else if(abs(diff)==abs(v2[hi]+n1-k)) diff = min(diff, v2[hi]+n1-k);
    }
    return k+diff;
}

int main() {
    int C; cin>>C;
    while(C--) {
        cin>>k>>n;
        for(int i=0;i<4;i++) 
            for(int j=0;j<n;j++)
                cin>>c[i][j];
        precalc();
        int answer = solve();
        cout<<answer<<endl;
    }
}
