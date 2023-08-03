#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N;
vector<int> ph;

void solution() {
    int head = 0, tail = N-1;
    int n1 = head, n2 = tail;
    int dif = abs(ph[head]+ph[tail]);
    while(head<tail-1) {
        if(ph[head]+ph[tail]==0) {
            n1 = head, n2 = tail;
            break;
        }
        else if(ph[head]+ph[tail]>0) {
            tail--;
            if(dif>abs(ph[head]+ph[tail])) {
                n1 = head, n2 = tail;
                dif = abs(ph[head]+ph[tail]);
            }
        }
       else {
            head++;
            if(dif>abs(ph[head]+ph[tail])) {
                n1 = head, n2 = tail;
                dif = abs(ph[head]+ph[tail]);
            }
        }
    }
    cout<<ph[n1]<<' '<<ph[n2]<<endl;
    return;
}

int main() {
    cin>>N;
    int a;
    for(int i=0;i<N;i++) {
        cin>>a;
        ph.push_back(a);
    }
    sort(ph.begin(), ph.end());
    solution();
}