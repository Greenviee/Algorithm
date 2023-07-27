#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n;
int forest[501][501];
int cache[501][501];
int dir_x[4] = {1, -1, 0, 0};
int dir_y[4] = {0, 0, 1, -1};

int solve(int y, int x) {
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    ret = 1;
    
    for(int i=0;i<4;i++) {
        int new_y = y + dir_y[i];
        int new_x = x + dir_x[i];
        if((0<=new_y && new_y<n) && (0<=new_x && new_x<n) && forest[y][x]<forest[new_y][new_x]) 
            ret = max(ret, 1+solve(new_y, new_x));
    }
    return ret;
}

int main() {
    cin>>n;
    memset(cache, -1, sizeof(cache));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>forest[i][j];
            
    int answer = 0;
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            answer = max(answer, solve(i, j));
        
    cout<<answer;
}