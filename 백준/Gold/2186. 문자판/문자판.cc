#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N, M, K;
char board[101][101];
//(x,y)에서 시작, n번째 글자부터 단어 끝까지 완성하는 경우의 수
int cache[101][101][81];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};
string word;

int path(int y, int x, int start) {
    if(start==word.length()-1) return 1;
    
    int& ret = cache[y][x][start];
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=0;i<4;i++) {
        for(int j=1;j<=K;j++) {
            int new_y = y + dir_y[i]*j;
            int new_x = x + dir_x[i]*j;
            if((0<=new_y && new_y<N) && (0<=new_x && new_x<M) && board[new_y][new_x]==word[start+1])
                ret += path(new_y, new_x, start+1);
        }
    }
    return ret;
}

int main() {
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>board[i][j];
    cin>>word;
    memset(cache, -1, sizeof(cache));
    int answer = 0;
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) 
            if(board[i][j]==word[0])
                answer += path(i, j, 0);
        
    cout<<answer;
}