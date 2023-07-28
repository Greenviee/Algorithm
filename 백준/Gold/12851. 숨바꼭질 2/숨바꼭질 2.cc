#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, k;
bool first = true;
int visit[100003] = { 0 };
int result = 100003;
int result2 = 0;
void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    visit[a] = true;
 
    while(!q.empty()){ 
        int x = q.front().first; 
        int cnt = q.front().second;
        q.pop();
 
        visit[x] = true;
        if(!first && result == cnt && x == k)
            result2++;
        if(first && x == k){ 
            result = cnt; 
            first = false; 
            result2++;
        }
 
        if(x+1 < 100001 && x+1 >= 0 && !visit[x+1]){
            q.push(make_pair(x + 1, cnt + 1)); 
        }
        if(x-1 < 100001 && x-1 >= 0 && !visit[x-1]){
            q.push(make_pair(x - 1, cnt + 1));
        }
        if(x*2 < 100001 && x*2 >= 0 && !visit[x*2]){
            q.push(make_pair(x * 2, cnt + 1));
        }
    }
}
int main(){
    cin >> n >> k;
 
    bfs(n, 0);
    cout << result << endl; 
    cout << result2 << endl; 
    return 0;
}