#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
char str[3] = {'m','o','o'};

char solve(int N) {
    if(N<=3) {
        if(N==1) return 'm';
        else return 'o';
    }
    
    int len1 = 3;
    int len2 = 0;
    int k = 0;
    while(len2<N) {
        k++;
        len2 = len1*2 + k + 3;
        len1 = len2;
    }
    //len2 = S(k)의 길이, len1 = S(k-1)의 길이
    len1 = (len2-k-3)/2;
    if(N<=len1+k+3) {
        if(N==len1+1) return 'm';
        else return 'o';
    }
    else return solve(N-len1-k-3);
}

int main() {
    cin>>N;
    char answer = solve(N);
    cout<<answer;
}