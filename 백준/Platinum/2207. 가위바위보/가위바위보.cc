#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N, M;

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

void makeGraph(vector<int>& rpc) {
    int vars = M;
    adj = vector<vector<int>>(2*(vars+1), vector<int>());
    for(int i=0;i<rpc.size();i+=2) {
        int n1 = rpc[i], n2 = rpc[i+1];
        if(n1>0) {
            if(n2>0) adj[n1*2+1].push_back(n2*2);
            else adj[n1*2+1].push_back(-n2*2+1);
        }
        else {
            if(n2>0) adj[-n1*2].push_back(n2*2);
            else adj[-n1*2].push_back(-n2*2+1);
        }
        
        if(n2>0) {
            if(n1>0) adj[n2*2+1].push_back(n1*2);
            else adj[n2*2+1].push_back(-n1*2+1);
        }
        else {
            if(n1>0) adj[-n2*2].push_back(n1*2);
            else adj[-n2*2].push_back(-n1*2+1);
        }
    }
}

vector<int> solve2SAT() {
    int n = M;
    vector<int> label = tarjanSCC();
    for(int i=2;i<label.size();i+=2) {
        if(label[i]==label[i+1]) return vector<int>();
    }
    vector<int> value(2*(n+1), -1);
    vector<pair<int, int>> order;
    for(int i=2;i<value.size();i++) 
        order.push_back(make_pair(-label[i], i));
    sort(order.begin(), order.end());
    
    for(int i=0;i<2*n;i++) {
        int vertex = order[i].second;
        int variable = vertex/2, isTrue = vertex%2==0;
        if(value[variable]!=-1) continue;
        value[variable] = !isTrue;
    }
    return value;
}

int main() {
    cin>>N>>M;
    int n1, n2;
    vector<int> rpc;
    for(int i=0;i<N;i++) {
        cin>>n1>>n2;
        rpc.push_back(n1);
        rpc.push_back(n2);
    }
    makeGraph(rpc);
    vector<int> answer = solve2SAT();
    if(answer.empty()) cout<<"OTL"<<endl;
    else cout<<"^_^"<<endl;
}