#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int len;
int currentch;
int answer = 987654321;
bool isbroken[10];

void channel(int push) {
    if(push==len+2) {
        answer = min(answer, push + abs(currentch - N));
        return;
    }
    
    if(push==1) 
        answer = min(answer, abs(100-N));
    
    for(int i=0;i<10;i++) {
        if(!isbroken[i]) {
            currentch = currentch*10 + i;
            answer = min(answer, push + abs(currentch - N));
            channel(push+1);
            currentch = (currentch-i) / 10;
        }
    }
}

int main() {
    cin>>N>>M;
    int n;
    for(int i=0;i<M;i++) {
        cin>>n;
        isbroken[n] = 1;
    }
    string s = to_string(N);
    len = s.length();
    channel(1);
    cout<<answer<<endl;
}