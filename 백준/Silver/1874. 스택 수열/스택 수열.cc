#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    bool can = true;
    stack<int> arr;
    string answer;
    int toput = 1;
    arr.push(toput);
    answer += '+';
    for(int i=0;i<n;i++) {
        cin>>k;
        if(arr.empty()) {
            toput++;
            arr.push(toput);
            answer += '+';
        }
        if(k<arr.top()) {
            can = false;
        }
        if(k>arr.top()) {
            while(k>arr.top()) {
                toput++;
                arr.push(toput);
                answer += '+';
            }
        }
        if(k==arr.top()) {
            arr.pop();
            answer += '-';
        }
    }
    if(can) for(int i=0;i<answer.length();i++) cout<<answer[i]<<"\n";
    else cout<<"NO";
}