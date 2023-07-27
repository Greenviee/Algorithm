#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        stack<char> ps;
        bool check = true;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(') ps.push('(');
            else {
                if(ps.empty()) {
                    check = false;
                    break;
                }
                else ps.pop();
            }
        }
        if(!ps.empty()) check = false;
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}