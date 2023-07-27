#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt[20];
int N;

int solve(int n) {
    if(cnt[n]!=-1) return cnt[n];
    if(n==N) return 1;
    if(n>N) return 0;
    int answer = 0;
    answer += solve(n+1);
    answer += solve(n+2);
    answer += solve(n+3);
    cnt[n] = answer;
    return answer;
}

int main() {
    int C;
    cin>>C;
    for(int c=0;c<C;c++) {
        memset(cnt, -1, sizeof(cnt));
        cin>>N;
        int answer = solve(0);
        cout<<answer<<endl;
    }
}