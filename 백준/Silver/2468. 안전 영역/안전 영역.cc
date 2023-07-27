#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int water_level;
int N;
int map[101][101]; //map[x][y]
int visited[101][101];
queue<pair<int, int>> q;

int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void bfs(int start_x, int start_y) {
    visited[start_x][start_y] = 1;
    q.push(make_pair(start_x, start_y));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            if((0<=new_x && new_x<N) && (0<=new_y && new_y<N) && map[new_x][new_y] > water_level && visited[new_x][new_y]!=1) {
                visited[new_x][new_y] = 1;
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int solution() {
    water_level = -1;
    int answer = 0;
    while(1) {
        memset(visited, -1, sizeof(visited));
        int cnt = 0;
        water_level++;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(map[j][i]>water_level && visited[j][i]!=1) {
                    bfs(j, i);
                    cnt++;
                }
            }
        }
        if(cnt==0) break;
        answer = max(answer, cnt);
    } 
    return answer;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) 
            cin>>map[j][i];
    }
    int answer = solution();
    cout<<answer;
}