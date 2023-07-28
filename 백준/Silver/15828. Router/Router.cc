#include <iostream>
#include <queue>
using namespace std;

int main() {
    int size;
    cin>>size;
    queue<int> router;
    int put;
    while(1) {
        cin>>put;
        if(put==-1) break;
        else if(put==0) router.pop();
        else {
                if(router.size()<size) router.push(put);
        }
    }

    if(router.empty()) cout<<"empty"<<endl;
    else {
        while(!router.empty()) {
            cout<<router.front()<<" ";
            router.pop();
        }
    }
}