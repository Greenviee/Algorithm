#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int board[100000][3];
int C[2][3];

int max() {
    for(int x=0;x<3;x++) C[(N-1)%2][x] = board[N-1][x];
    for(int y=N-2;y>=0;y--) {
        C[y%2][0] = board[y][0] + max(C[(y+1)%2][0], C[(y+1)%2][1]);
        C[y%2][1] = board[y][1] + max(max(C[(y+1)%2][0], C[(y+1)%2][1]), C[(y+1)%2][2]);
        C[y%2][2] = board[y][2] + max(C[(y+1)%2][1], C[(y+1)%2][2]);
    }
    int ret =  max(max(C[0][0], C[0][1]), C[0][2]);
    return ret;
}

int min() {
    for(int x=0;x<3;x++) C[(N-1)%2][x] = board[N-1][x];
    for(int y=N-2;y>=0;y--) {
        C[y%2][0] = board[y][0] + min(C[(y+1)%2][0], C[(y+1)%2][1]);
        C[y%2][1] = board[y][1] + min(min(C[(y+1)%2][0], C[(y+1)%2][1]), C[(y+1)%2][2]);
        C[y%2][2] = board[y][2] + min(C[(y+1)%2][1], C[(y+1)%2][2]);
    }
    int ret =  min(min(C[0][0], C[0][1]), C[0][2]);
    return ret;
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++)
        for(int j=0;j<3;j++)
            cin>>board[i][j];

    cout<<max()<<' '<<min();
}