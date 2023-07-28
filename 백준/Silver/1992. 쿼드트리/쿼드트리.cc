#include <iostream>
#include <vector>
using namespace std;

string answer;

void solve(vector<vector<int>>& quad, int y, int x, int size)
{
    answer += '(';
    int first = quad[y][x];
    bool ok = true;
    int half = size/2;
    for(int i=y;i<size+y;i++) {
        for(int j=x;j<size+x;j++) {
            if(quad[i][j]!=first) {
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    if(!ok) {
        solve(quad, y, x, half);
        solve(quad, y, x+half, half);
        solve(quad, y+half, x, half);
        solve(quad, y+half, x+half, half);
    }
    else {
        answer.pop_back();
        if(first==0) answer += '0';
        else answer += '1';
        return;
    }
    answer += ')';
}

int main()
{
    int size, x;
    string k;
    cin>>size;
    vector<int> v[size];
    vector<vector<int>> quad;
    for(int i=0;i<size;i++) {
        quad.push_back(v[i]);
        cin>>k;
        for(int j=0;j<size;j++) {
            x = k[j] - '0';
            quad[i].push_back(x);
        }
    }
    solve(quad, 0, 0, size);
    cout<<answer<<endl;
}