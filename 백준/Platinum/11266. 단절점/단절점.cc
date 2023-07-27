#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;
int V, E;

int findCutVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    for(int i=0;i<adj[here].size();i++) {
        int there = adj[here][i];
        if(discovered[there]==-1) {
            children++;
            int subtree = findCutVertex(there, false);
            if(!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    if(isRoot) isCutVertex[here] = (children >= 2);
    return ret;
}

void findAll() {
    for(int i=1;i<=V;i++) {
        if(discovered[i]==-1) findCutVertex(i, true);
    }
}

int main() {
    cin>>V>>E;
    int n1, n2;
    adj = vector<vector<int>>(V+1, vector<int>(0, 0));
    discovered = vector<int>(V+1, -1);
    isCutVertex = vector<bool>(V+1, false);
    for(int i=0;i<E;i++) {
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    findAll();
    vector<int> answer;
    for(int i=1;i<isCutVertex.size();i++) 
        if(isCutVertex[i]) answer.push_back(i);
    cout<<answer.size()<<endl;
    for(int i=0;i<answer.size();i++) cout<<answer[i]<<' ';
}