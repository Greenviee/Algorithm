#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
const int INF = 987654321;
int map[50][50];
int dist[50][50];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int totaldist() {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> store;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j]==3) {
                store.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }
    
    while(!store.empty()) {
        int y = store.front().first;
        int x = store.front().second;
        store.pop();
        for(int i=0;i<4;i++) {
            int new_y = y + dir_y[i];
            int new_x = x + dir_x[i];
            if((0<=new_y && new_y<N) && (0<=new_x && new_x<N) && dist[new_y][new_x]==-1) {
                dist[new_y][new_x] = dist[y][x] + 1;
                store.push(make_pair(new_y, new_x));
            }
        }
    }
    
    int sum = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(map[i][j]==1) sum += dist[i][j];
    return sum;
}

//y, x는 바로 이전에 선택한 치킨집
int chicken(int y, int x, int cnt) {
    if(cnt==M) return totaldist();
    
    int ret = INF;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            //선택한 치킨 집은 3으로 변경, 중복선택 제거
            if((i>y || (i==y && j>=x)) && map[i][j]==2) {
                map[i][j] = 3;
                ret = min(ret, chicken(i, j, cnt+1));
                map[i][j] = 2;
            } 
        }
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
    int answer = chicken(-1, -1, 0);
    cout<<answer;
}