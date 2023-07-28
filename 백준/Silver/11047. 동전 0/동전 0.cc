#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, coin;
    int answer = 0;
    cin>>N>>K;
    vector<int> coins;
    for(int i=0;i<N;i++) {
        cin>>coin;
        coins.push_back(coin);
    }
    while(K!=0) {
        int use = 0;
        for(int i=0;i<N;i++) 
            if(coins[i]>K) {
                use = coins[i-1];
                break;
            }
        if(use==0) use = coins[coins.size()-1];
        answer += K/use;
        K = K%use;
    }
    cout<<answer;
}