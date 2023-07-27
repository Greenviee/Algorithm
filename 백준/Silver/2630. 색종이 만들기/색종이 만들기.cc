#include <iostream>
#include <vector>
using namespace std;

int b = 0, w = 0;

void solve(vector<vector<int>>& paper, int y, int x, int size)
{
    int first = paper[y][x];
    bool ok = true;
    int half = size / 2;
    for(int i=y;i<size+y;i++) {
        for(int j=x;j<size+x;j++) {
            if(paper[i][j]!=first) {
                ok =false;
                break;
            }
        }
        if(!ok) break;
    }
    if(!ok) {
        solve(paper, y, x, half);
        solve(paper, y+half, x, half);
        solve(paper, y, x+half, half);
        solve(paper, y+half, x+half, half);
    }
    else {
        if(first==0) w++;
        else b++;
    }
}

int main()
{
    vector<vector<int>> paper;
    int size, x;
    cin>>size;
    vector<int> v[size];
    for(int i=0;i<size;i++) {
        paper.push_back(v[i]);
        for(int j=0;j<size;j++) {
            cin>>x;
            paper[i].push_back(x);
        }
    }
    solve(paper, 0, 0, size);
    cout<<w<<endl;
    cout<<b<<endl;
}