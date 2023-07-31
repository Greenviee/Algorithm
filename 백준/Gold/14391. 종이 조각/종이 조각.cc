#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N, M;
int paper[4][4];

int solution() {
    int ret = 0;
    
    //모든 칸을 한 줄로 붙인 후 가로로 자른 칸은 0, 세로로 자른 칸은 1로 표현
    for(int i=0;i<(1<<(N*M));i++) {
        int sum = 0;
        
        //가로로 자른 칸들 합
        for(int y=0;y<N;y++) {
            int num = 0;
            for(int x=0;x<M;x++) {
                int idx = M*y+x;
                //idx번째 칸이 가로로 자른 칸일 경우
                if(!(i&(1<<idx))) 
                    num = num*10 + paper[y][x];
                //idx번째 칸이 세로로 자른 칸일 경우
                else {
                    sum += num;
                    num = 0;
                }
            }
            sum += num;
        }
        
        //세로로 자른 칸들 합
        for(int x=0;x<M;x++) {
            int num = 0;
            for(int y=0;y<N;y++) {
                int idx = M*y+x;
                //idx번째 칸이 세로로 자른 칸일 경우
                if(i&(1<<idx))
                    num = num*10 + paper[y][x];
                else {
                    sum += num;
                    num = 0;
                }
            }
            sum += num;
        }
        
        ret = max(ret, sum);
    }
    return ret;
}

int main() {
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        for(int j=0;j<M;j++)
            paper[i][j] = s[j] - '0';
    }
    int answer = solution();
    cout<<answer;
}