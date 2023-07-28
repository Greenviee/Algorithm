#include <iostream>
#include <vector>
using namespace std;

int one = 0, zero = 0, minusone = 0;

void solve(vector<vector<int>>& paper, int y, int x, int size)
{
    int first = paper[y][x];
    bool ok = true;
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) {
            if(paper[i][j]!=first) {
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    
    int one_third = size/3;
    
    if(ok) {
        switch(first)
        {
            case -1 :
                minusone++;
                break;
            
            case 0 :
                zero++;
                break;
            
            case 1 :
                one++;
                break;
        }
    }
    else {
        solve(paper, y, x, one_third);
        solve(paper, y, x+one_third, one_third);
        solve(paper, y, x+one_third*2, one_third);
        solve(paper, y+one_third, x, one_third);
        solve(paper, y+one_third, x+one_third, one_third);
        solve(paper, y+one_third, x+one_third*2, one_third);
        solve(paper, y+one_third*2, x, one_third);
        solve(paper, y+one_third*2, x+one_third, one_third);
        solve(paper, y+one_third*2, x+one_third*2, one_third);
    }
}

int main()
{
    int size, k;
    cin>>size;
    vector<vector<int>> paper;
    vector<int> v[size];
    for(int i=0;i<size;i++) {
        paper.push_back(v[i]);
        for(int j=0;j<size;j++) {
            cin>>k;
            paper[i].push_back(k);
        }
    }
    solve(paper, 0, 0, size);
    cout<<minusone<<endl;
    cout<<zero<<endl;
    cout<<one<<endl;
}