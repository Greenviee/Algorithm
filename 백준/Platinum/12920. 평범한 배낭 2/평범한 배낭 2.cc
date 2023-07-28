#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
    
int N, M;
int weight[101], satisfy[101], cnt[101];
int cache[2001][10001];
//(weight, satisfy)
vector<pair<int, int>> new_things;

void bundle() {
    for(int i=0;i<N;i++) {
        int k = -1;
        while(1) {
            k++;
            if(cnt[i]>=pow(2, k)) {
                new_things.push_back(make_pair(weight[i]*pow(2, k), satisfy[i]*pow(2, k)));
                cnt[i] -= pow(2, k);
                if(cnt[i]==0) break;
            }
            else if(cnt[i]!=0) {
                new_things.push_back(make_pair(weight[i]*cnt[i], satisfy[i]*cnt[i]));
                cnt[i] = 0;
                break;
            }
        }
    }
}

int solve(int start, int bag) {
    if(start==new_things.size()) return 0;
    
    int& ret = cache[start][bag];
    if(ret!=-1) return ret;
    
    if(new_things[start].first<=bag) 
        ret = max(new_things[start].second+solve(start+1, bag-new_things[start].first), solve(start+1, bag));
    else ret = solve(start+1, bag);
    
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) 
        cin>>weight[i]>>satisfy[i]>>cnt[i];
    memset(cache, -1, sizeof(cache));
    bundle();
    int answer = solve(0, M);
    cout<<answer;
}