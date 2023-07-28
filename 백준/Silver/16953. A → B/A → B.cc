#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define INF 987654321000
long long A, B;

long long solve(long long x, long long cnt) {
    if(x==B) return cnt;
    bool okay = false;
    long long num1 = INF, num2 = INF;
    if(x*2<=B) num1 = solve(x*2, cnt+1);
    if(x*10+1<=B) num2 = solve(x*10+1, cnt+1);
    return min(num1, num2);
}

int main() {
    cin>>A>>B;
    long long answer = solve(A, 1);
    if(answer==INF) cout<<-1<<endl;
    else cout<<answer<<endl;
}