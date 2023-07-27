#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
string numbers[51];
long long numbercnt[10];
bool notzero[10];
//A~J까지 숫자
int match[10];

void counting(int n) {
    string num = numbers[n];
    reverse(num.begin(), num.end());
    int x = 0;
    for(int i=0;i<num.length();i++) {
        int new_num = num[i] - 'A';
        numbercnt[new_num] += pow(10, x);
        x++;
    }
}

bool existzero() {
    for(int i=0;i<10;i++) if(numbercnt[i]==0) return false;
    return true;
}

long long solve() {
    //0 정하기
    if(existzero()) {
        long long zero = 100000000000000;
        int a = -1;
        for(int i=0;i<10;i++) {
            if(!notzero[i] && numbercnt[i]!=0) {
                zero = min(zero, numbercnt[i]);
                if(zero==numbercnt[i]) a = i;
            }
        }
        match[a] = 0;
    }

    priority_queue<pair<long long, int>> pq;
    for(int i=0;i<10;i++) 
        if(numbercnt[i]!=0 && match[i]!=0) pq.push(make_pair(numbercnt[i], i));
    int numbering = 9;
    while(!pq.empty()) {
        match[pq.top().second] = numbering;
        numbering--;
        pq.pop();
    }
    
    long long ret = 0;
    for(int i=0;i<10;i++) ret += numbercnt[i]*match[i];
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>numbers[i];
        notzero[numbers[i][0]-'A'] = true;
        counting(i);
    }
    memset(match, -1, sizeof(match));
    long long answer = solve();
    cout<<answer;
}

