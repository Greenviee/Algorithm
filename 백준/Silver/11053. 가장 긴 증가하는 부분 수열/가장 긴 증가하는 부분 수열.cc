#include <iostream>
#include <vector>

using namespace std;

int cache[1001];

int lis(int start, vector<int>& S)
{
    int& ret = cache[start+1];
    if(ret!=-1) return ret;
    ret = 1;
    for(int next = start+1;next<S.size();next++) {
        if(start==-1 || S[start] < S[next]) {
            ret = max(ret, lis(next, S) + 1);
        }
    }
    return ret;
}

int main()
{
    for(int i=0;i<1001;i++) cache[i] = -1;
    int num, k;
    cin>>num;
    vector<int> S;
    for(int i=0;i<num;i++) {
        cin>>k;
        S.push_back(k);
    }
    int answer = lis(-1, S) - 1;
    cout<<answer;
}