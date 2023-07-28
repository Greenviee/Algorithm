#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[100001];
bool check[100001] = {false};
int result[100001];

int main() {
    queue<int> q;
    int N, u, v, x, y;
    cin>>N;
    for(int i=0;i<N-1;i++) {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    //bfs
    q.push(1);
    check[1] = true;
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(int i=0;i<a[x].size();i++) {
            y = a[x][i];
            if(!check[y]) {
                q.push(y);
                check[y] = true;
                result[y] = x;
            }
        }
    }
    for(int i=2;i<=N;i++) 
        cout<<result[i]<<"\n";
    
}