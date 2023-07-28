#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[500][500];
bool visited[500][500];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
int answer = 0;

void tetris(int n, int y, int x, int sum) {
    if(n==3) {
        answer = max(answer, sum);
        return;
    }
    
    for(int i=0;i<4;i++) {
        int new_x = x + dir_x[i];
        int new_y = y + dir_y[i];
        if((0<=new_x && new_x<M) && (0<=new_y && new_y<N) && visited[new_y][new_x]==0) {
            sum += map[new_y][new_x];
            visited[new_y][new_x] = 1;
            tetris(n+1, new_y, new_x, sum);
            //T자 블럭 고려
            tetris(n+1, y, x, sum);
            sum -= map[new_y][new_x];
            visited[new_y][new_x] = 0;
        }
    }
    return;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++)
            cin>>map[i][j];
    
    for(int i=0;i<N;i++) { 
        for(int j=0;j<M;j++) {
            visited[i][j] = 1;
            tetris(0, i, j, map[i][j]);
        }
    }
    cout<<answer;
}