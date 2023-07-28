#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[8][8];
int map_copy[8][8];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

void mapviewer() {
    cout<<endl;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) 
            cout<<map[i][j]<<' ';
        cout<<endl;
    }
}

void infection() {
    //감염 진행을 위해 맵 사본 사용
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            map_copy[i][j] = map[i][j];
    //바이러스 좌표 저장 queue (y, x)
    queue<pair<int, int>> virus;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(map_copy[i][j]==2) virus.push(make_pair(i, j));
    
    while(!virus.empty()) {
        int y = virus.front().first;
        int x = virus.front().second;
        virus.pop();
        for(int i=0;i<4;i++) {
            int new_y = y + dir_y[i];
            int new_x = x + dir_x[i];
            if((new_y>=0 && new_y<N) && (new_x>=0 && new_x<M) && map_copy[new_y][new_x]==0) {
                map_copy[new_y][new_x] = 2;
                virus.push(make_pair(new_y, new_x));
            }
        }
    }
}

int safepoint() {
    infection();
    int cnt = 0;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++)
            if(map_copy[i][j]==0) cnt++;
    return cnt;
}

//바로 이전에 벽을 세운 좌표 y, x, 반복횟수 k
int lab(int y, int x, int k) {
    //벽 3개를 다 세움
    if(k==3) return safepoint();
    int ret = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            //지나간 부분 제외
            if((i>y || (i==y && j>x)) && map[i][j]==0) {
                map[i][j] = 1;
                ret = max(ret, lab(i, j, k+1));
                map[i][j] = 0;
            }
        }
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    
   int answer = lab(-1, -1, 0);
   cout<<answer;
}