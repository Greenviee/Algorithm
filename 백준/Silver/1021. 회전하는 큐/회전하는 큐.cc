#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    deque<int> d;
    for(int i=0;i<N;i++) d.push_back(i+1);
    int x, s;
    int answer = 0;
    for(int i=0;i<M;i++) {
        cin>>x;
        if(x==d.front()) d.pop_front();
        else {
            int cnt = 0;
            while(x!=d.front()) {
                s = d.front();
                d.pop_front();
                d.push_back(s);
                cnt++;
            }
            if(cnt<d.size()-cnt) answer += cnt;
            else answer += (d.size()-cnt);
            d.pop_front();
        }
    }
    cout<<answer<<endl;
}