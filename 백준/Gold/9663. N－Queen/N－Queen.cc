#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
int map[15][15];

void unablepoint(int h, int w) {
    map[h][w] = 1;
    int w1 = w-1;
    int w2 = w+1;
    for(int i=h+1;i<N;i++) {
        if(w1>=0) map[i][w1] += 1;
        if(w2<N) map[i][w2] += 1;
        map[i][w] += 1;
        w1--; w2++;
    }
}

void ablepoint(int h, int w) {
    map[h][w] -= 1;
    int w1 = w-1;
    int w2 = w+1;
    for(int i=h+1;i<N;i++) {
        if(w1>=0) map[i][w1] -= 1;
        if(w2<N) map[i][w2] -= 1;
        map[i][w] -= 1;
        w1--; w2++;
    }
}

int queencount(int h) {
    //퀸 배치 완료한 경우
    if(h==N) return 1;
    
    int ret = 0;
    for(int i=0;i<N;i++) {
        if(map[h][i]==0) {
            unablepoint(h, i);
            ret += queencount(h+1);
            ablepoint(h, i);
        }
    }
    return ret;
}

int main() {
    cin>>N;
    int answer = queencount(0);
    cout<<answer;
}