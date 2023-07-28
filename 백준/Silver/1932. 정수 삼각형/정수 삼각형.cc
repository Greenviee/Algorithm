#include <iostream>
#include <cstring>
using namespace std;

int cache[501][501];
int triangle[501][501];
int n;
//a = 줄, b = 칸
int MAX(int a, int b) {
    if(a==n-1) return triangle[a][b];
    int& ret = cache[a][b];
    if(ret!=-1) return ret;
    
    ret = max(MAX(a+1, b), MAX(a+1, b+1));
    ret += triangle[a][b];
    return ret;
}

int main() {
    cin>>n;
    int k = 0;
    memset(cache, -1, sizeof(cache));
    for(int i=0;i<n;i++) {
        k++;
        for(int j=0;j<k;j++)
            cin>>triangle[i][j];
    }
    
    int answer = MAX(0, 0);
    cout<<answer<<endl;
}