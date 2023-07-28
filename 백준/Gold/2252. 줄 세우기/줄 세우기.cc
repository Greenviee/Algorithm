#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;

int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(discovered[there]==-1)
            ret = min(ret, scc(there));
        else if(sccId[there]==-1)
            ret = min(ret, discovered[there]);
    }
    if(ret==discovered[here]) {
        while(1) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if(t==here) break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCounter = vertexCounter = 0;
    for(int i=0;i<adj.size();i++) if(discovered[i]==-1) scc(i);
    return sccId;
}

int main() {
    int N, M;
    cin>>N>>M;
    adj = vector<vector<int>>(N, vector<int>());
    int n1, n2;
    for(int i=0;i<M;i++) {
        cin>>n1>>n2;
        adj[n1-1].push_back(n2-1);
    }
    vector<int> scc = tarjanSCC();
    vector<pair<int, int>> order;
    for(int i=0;i<scc.size();i++) 
        order.push_back(make_pair(-scc[i], i+1));
    sort(order.begin(), order.end());
    for(int i=0;i<order.size();i++)
        cout<<order[i].second<<' ';
}