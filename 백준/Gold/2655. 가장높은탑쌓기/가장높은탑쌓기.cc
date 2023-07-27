#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 98765432;
int N;
int weight[101], under[101], height[101];
int cache[101];
int bestpick[101], cnt;
vector<int> answer;

int tower(int start) {
    int& ret = cache[start];
    if(ret!=-1) return ret;
    ret = height[start];
    
    for(int i=1;i<=N;i++) {
        int save = ret;
        if(weight[i]<weight[start] && under[i]<under[start])
            ret = max(ret, height[start] + tower(i));
        if(ret!=save) bestpick[start] = i;
    }
    return ret;
}

void includes(int n) {
    if(n==-1) return;
    answer.push_back(n);
    includes(bestpick[n]);
}

int main() {
    cin>>N;
    for(int i=1;i<=N;i++) cin>>under[i]>>height[i]>>weight[i];
    memset(cache, -1, sizeof(cache));
    memset(bestpick, -1, sizeof(bestpick));
    weight[0] = under[0] = INF, height[0] = 0;
    int a = tower(0);
    includes(0);
    reverse(answer.begin(), answer.end());
    answer.pop_back();
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<endl;
}