#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, K, order[101];
bool multitab[101];
queue<int> things[101];

int solve() {
    int ret = 0;
    int plugin = 0;
    for(int i=0;i<K;i++) {
        int next = order[i];
        if(multitab[next]) {
            things[next].pop();
            // cout<<"keep: "<<next<<endl;
        }
        else if(plugin<N) {
            multitab[next] = true;
            things[next].pop();
            // cout<<"in: "<<next<<endl;
            plugin++;
        }
        else {
            int off = -1;
            for(int j=1;j<=K;j++) {
                if(multitab[j] && things[j].empty()) {
                    off = j;
                    break;
                }
                if(multitab[j] && (off==-1 || things[off].front()<things[j].front())) off = j;
            }
            multitab[off] = false;
            ret++;
            multitab[next] = true;
            // cout<<"off: "<<off<<endl;
            // cout<<"in: "<<next<<endl;
            things[next].pop();
        }
    }
    return ret;
}

int main() {
    cin>>N>>K;
    for(int i=0;i<K;i++) {
        cin>>order[i];
        things[order[i]].push(i);
    }
    memset(multitab, 0, sizeof(multitab));
    cout<<solve();
}
