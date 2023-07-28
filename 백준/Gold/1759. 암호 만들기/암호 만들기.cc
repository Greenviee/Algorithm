#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int L, C;
vector<char> c;
char pw[15];

bool isvowel(char c) {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    return false;
}

int password(int level, int b) {
    //암호 완성
    if(level==L) {
        int vowelcnt = 0;
        for(int i=0;i<L;i++) 
            if(isvowel(pw[i])) vowelcnt++;
        if(vowelcnt>=1 && vowelcnt<=L-2) {
            for(int i=0;i<L;i++) cout<<pw[i];
            cout<<endl;
            return 1;
        }
        else return 0;
    }
    
    int ret = 0;
    
    for(int i=b;i<=(C-L+level);i++) {
        pw[level] = c[i];
        ret += password(level+1, i+1);
        pw[level] = ' ';
    }
    
    return ret;
}

int main() {
    cin>>L>>C;
    for(int i=0;i<C;i++) {
        char x;
        cin>>x;
        c.push_back(x);
    }
    sort(c.begin(), c.end());
    int answer = password(0, 0);
}
