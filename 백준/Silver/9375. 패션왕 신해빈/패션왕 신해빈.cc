#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int C, n;
    string name, kind;
    cin>>C;
    for(int c=0;c<C;c++) {
        cin>>n;
        vector<string> kinds;
        vector<int> num;
        for(int i=0;i<n;i++) {
            cin>>name>>kind;
            bool b = false;
            if(kinds.empty()) {
                kinds.push_back(kind);
                num.push_back(1);
            }
            else {
                for(int i=0;i<kinds.size();i++) {
                    if(kinds[i]==kind) {
                        num[i]++;
                        b = true;
                        break;
                    }
                }
                if(!b) {
                    kinds.push_back(kind);
                    num.push_back(1);
                }
            }
        }
        int answer = 1;
        if(kinds.size()==1) answer = num[0];
        else {
            for(int i=0;i<kinds.size();i++) 
                answer *= num[i]+1;
            answer--;
        }
        cout<<answer<<endl;
    }
}