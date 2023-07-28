#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;

string name;

int updown() {
    int ret = 0;
    for(int i=0;i<name.length();i++) 
        ret += min(abs('A'-name[i]), 26-abs('A'-name[i]));
    return ret;
}

int side() {
    int ret = 0;
    int len = name.length();
    deque<int> q;
    for(int i=1;i<name.length();i++) 
        if(name[i]!='A') q.push_back(i);
    
    if(q.empty()) return 0;
    
    int start = 0;
    //q의 front()와 back()중 가까운 쪽을 골라 이동
    int left = 0, right = 0;
    //오른쪽 먼저 움직임
    right += q.front();
    start = q.front();
    q.pop_front();
    while(!q.empty()) {
        int n1 = q.front();
        int n2 = q.back();
        int d1 = min(abs(start-n1), len-abs(start-n1));
        int d2 = min(abs(start-n2), len-abs(start-n2));
        if(d1<=d2) {
            start = n1;
            q.pop_front();
            right += d1;
        }
        else {
            start = n2;
            q.pop_back();
            right += d2;
        }
    }
    //왼부터 움직임
    for(int i=1;i<name.length();i++) 
        if(name[i]!='A') q.push_back(i);
    left += name.length() - q.back();
    start = q.back();
    q.pop_back();
    while(!q.empty()) {
        int n1 = q.front();
        int n2 = q.back();
        int d1 = min(abs(start-n1), len-abs(start-n1));
        int d2 = min(abs(start-n2), len-abs(start-n2));
        if(d1<=d2) {
            start = n1;
            q.pop_front();
            left += d1;
        }
        else {
            start = n2;
            q.pop_back();
            left += d2;
        }
    }
    ret = min(left, right);
    return ret;
}

int main() {
    int C;
    cin>>C;
    while(C--) {
        cin>>name;
        int answer = updown() + side();
        cout<<answer<<endl;
    }
}