#include <iostream>
#include <stack>
using namespace std;

int main() {
    while(1) {
        string s;
        getline(cin, s);
        if(s==".") break;
        stack<char> ps;
        bool check = true;
        for(int i=0;i<s.length();i++) {
            switch(s[i]) {
                case '(' :
                    ps.push('(');
                    break;
                case '{' :
                    ps.push('{');
                    break;
                case '[' :
                    ps.push('[');
                    break;
                case ')' :
                    if(ps.empty() || ps.top()!='(') {
                        check = false;
                        break;
                    }
                    else {
                        ps.pop();
                        break;
                    }
                case '}' :
                    if(ps.empty() || ps.top()!='{') {
                        check = false;
                        break;
                    }
                    else {
                        ps.pop();
                        break;
                    }
                case ']' :
                    if(ps.empty() || ps.top()!='[') {
                        check = false;
                        break;
                    }
                    else {
                        ps.pop();
                        break;
                    }
            }
        }
        if(!ps.empty()) check = false;
        if(check) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}