#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int map[51][51];
int visited[51][51];
queue<pair<int, int>> q;

void bfs(int start_y, int start_x) {
    visited[start_y][start_x] = 1;
    q.push(make_pair(start_y, start_x));
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(x-1>=0) {
            if(y-1>=0 && map[y-1][x-1]==1 && visited[y-1][x-1]!=1) {
                visited[y-1][x-1] = 1;
                q.push(make_pair(y-1, x-1));
            }
            if(y+1<h && map[y+1][x-1]==1 && visited[y+1][x-1]!=1) {
                visited[y+1][x-1] = 1;
                q.push(make_pair(y+1, x-1));
            }
            if(map[y][x-1]==1 && visited[y][x-1]!=1) {
                visited[y][x-1] = 1;
                q.push(make_pair(y, x-1));
            }
        }
        if(x+1<w) {
            if(y-1>=0 && map[y-1][x+1]==1 && visited[y-1][x+1]!=1) {
                visited[y-1][x+1] = 1;
                q.push(make_pair(y-1, x+1));
            }
            if(y+1<h && map[y+1][x+1]==1 && visited[y+1][x+1]!=1) {
                visited[y+1][x+1] = 1;
                q.push(make_pair(y+1, x+1));
            }
            if(map[y][x+1]==1 && visited[y][x+1]!=1) {
                visited[y][x+1] = 1;
                q.push(make_pair(y, x+1));
            }
        }
        if(y-1>=0 && map[y-1][x]==1 && visited[y-1][x]!=1) {
            visited[y-1][x] = 1;
            q.push(make_pair(y-1, x));
        }
        if(y+1<h && map[y+1][x]==1 && visited[y+1][x]!=1) {
            visited[y+1][x] = 1;
            q.push(make_pair(y+1, x));
        }
    }
}

int bfsAll() {
    int cnt = 0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(map[i][j]==1 && visited[i][j]!=1) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    while(1) {
        cin>>w>>h;
        if(w==0 && h==0) break;
        memset(visited, -1, sizeof(visited));
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) 
                cin>>map[i][j];
        }
        int answer = bfsAll();
        cout<<answer<<endl;
    }
}