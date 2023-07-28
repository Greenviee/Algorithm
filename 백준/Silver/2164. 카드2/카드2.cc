#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin>>N;
    deque<int> cards;
    for(int i=1;i<=N;i++) cards.push_back(i);
    while(cards.size()!=1) {
        cards.pop_front();
        cards.push_back(cards.front());
        cards.pop_front();
    }
    
    cout<<cards.front()<<endl;
}