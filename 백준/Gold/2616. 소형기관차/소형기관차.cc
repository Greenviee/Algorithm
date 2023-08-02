#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, M;
int trail[50001];
vector<int> psum;

void precalc() {
    psum.push_back(0);
    psum.push_back(trail[0]);
    for(int i=1;i<=N;i++) {
        int s = psum.back() + trail[i];
        psum.push_back(s);
    }
}


int solution() {
    int ret;
    int cache[4][50001];
    for(int i=1;i<=3;i++) {
        for(int j=i*M;j<=N;j++) {
            cache[i][j] = max(cache[i][j-1], cache[i-1][j-M] + (psum[j] - psum[j-M]));
        }
    }
    ret = cache[3][N];
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>trail[i];
    cin>>M;
    precalc();
    cout<<solution();
}
