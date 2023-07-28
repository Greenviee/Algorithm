#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> a[100001];
bool visited[100001] = {false};

int maxNode;
int maxlength = 0;

void DFS(int cur, int len) {
    visited[cur] = true;
    for(int i=0;i<a[cur].size();i++) {
        int next = a[cur][i].first;
        if(!visited[next]) {
            len += a[cur][i].second;
            maxlength = max(maxlength, len);
            if(maxlength==len) maxNode = next;
            DFS(next, len);
            len -= a[cur][i].second;
        }
    }
}

int main() {
    int N, u, v, dist;
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>u;
        while(1) {
            cin>>v;
            if(v==-1) break;
            cin>>dist;
            a[u].push_back(make_pair(v, dist));
            a[v].push_back(make_pair(u, dist));
        }
    }
    DFS(1, 0);
    maxlength = 0;
    memset(visited, 0, sizeof(visited));
    DFS(maxNode, 0);
    cout<<maxlength<<endl;
}