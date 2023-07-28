#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int M, N, H;
int box[101][101][101];
int dist[101][101][101];
queue<tuple<int, int, int>> q;

int dir_x[6] = {1, -1, 0, 0, 0, 0};
int dir_y[6] = {0, 0, 1, -1, 0, 0};
int dir_z[6] = {0, 0, 0, 0, 1, -1};


void bfs() {
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for(int i=0;i<6;i++) {
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            int new_z = z + dir_z[i];
            if((0<=new_x&&new_x<M) && (0<=new_y&&new_y<N) && (0<=new_z&&new_z<H) && dist[new_x][new_y][new_z]==-1 && box[new_x][new_y][new_z]==0) {
                q.push(make_tuple(new_x, new_y, new_z));
                dist[new_x][new_y][new_z] = dist[x][y][z] + 1;
            }
        }
    }
}

int main() {
    cin>>M>>N>>H;
    memset(dist, -1, sizeof(dist));
    //box[x][y][z]
    for(int i=0;i<H;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                cin>>box[k][j][i];
                if(box[k][j][i]==1) {
                    q.push(make_tuple(k, j, i));
                    dist[k][j][i] = 0;
                }
                //-1이 아닌 값 아무거나로 설정
                else if(box[k][j][i]==-1) dist[k][j][i] = -11;
            }
        }
    }
    int answer = 0;
    bfs();
    for(int i=0;i<H;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                if(dist[k][j][i]==-1) {
                    answer = -1;
                    break;
                }
                answer = max(answer, dist[k][j][i]);
            }
            if(answer==-1) break;
        }
        if(answer==-1) break;
    }
    cout<<answer;
}