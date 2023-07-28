#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int M;
string messi = "Messi Gimossi Messi";

char solve(int n) {
    if(n<20) return messi[n-1];
    //len1 = len(messi(N-2)), len2 = len(messi(N-1)), len3 = len(messi(N))
    int len1 = 5;
    int len2 = 13;
    int len3 = 19;
    while(len3<n) {
        int save = len3;
        len3 = len3 + len2 + 1;
        len1 = len2;
        len2 = save;
    }
    if(n==len2+1) return ' ';
    else return solve(n-len2-1);
}

int main() {
    cin>>M;
    char answer = solve(M);
    if(answer==' ') cout<<"Messi Messi Gimossi";
    else cout<<answer;
}
