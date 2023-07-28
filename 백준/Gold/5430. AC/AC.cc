#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int T, n;
    string p, arr;
    cin>>T;
    for(int t=0;t<T;t++) {
        cin>>p>>n>>arr;
        deque<int> ac;
        bool rev = false;
        bool ch = true;
        for(int i=0;i<arr.length();i++) 
            if(arr[i]>='0' && arr[i]<='9') {
                if(arr[i+1]>='0' && arr[i+1]<='9') {
                    if(arr[i+2]>='0' && arr[i+2]<='9') {
                        i+=2;
                        ac.push_back(100);
                    }
                    else {
                        int num = (arr[i] - '0')*10 + (arr[i+1] - '0');
                        ac.push_back(num);
                        i++;
                    }
                }
                else ac.push_back(arr[i]-'0');
            }
        for(int i=0;i<p.length();i++) {
            if(p[i]=='R') {
                if(rev) rev = false;
                else rev = true;
            }
            else if(p[i]=='D') {
                if(ac.empty()) {
                    cout<<"error"<<endl;
                    ch = false;
                    break;
                }
                else {
                    if(rev) ac.pop_back();
                    else ac.pop_front();
                }
            }
        }
        if(!ac.empty()) {
            int cnt;
            if(rev) reverse(ac.begin(), ac.end());
            cout<<'[';
            while(!ac.empty()) {
                if(ac.size()!=1) {
                    cout<<ac.front()<<",";
                    ac.pop_front(); 
                }
                else {
                    cout<<ac.front()<<']'<<endl;
                    ac.pop_front();
                }
            }
        }
        else {
            if(ch) cout<<"[]"<<endl;
        }
    }
}