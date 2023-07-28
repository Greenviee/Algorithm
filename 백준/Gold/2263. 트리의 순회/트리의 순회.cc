#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inorder;
vector<int> postorder;

//in1 : inorder 시작점, in2 : inorder 끝, po 동일
void printPreOrder(int in1, int in2, int po1, int po2) {
    const int N = in2-in1+1;
    if(in1>in2 || po1>po2) return;
    if(in1==in2) {
        cout<<inorder[in1]<<" ";
        return;
    }
    const int root = postorder[po2];
    const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin() - in1;
    const int R = N - L - 1;
    cout<<root<<" ";
    printPreOrder(in1, in1+L-1, po1, po1+L-1);
    printPreOrder(in1+L+1, in2, po1+L, po2-1);
}

int main() {
    int n, k;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>k;
        inorder.push_back(k);
    }
    for(int i=0;i<n;i++) {
        cin>>k;
        postorder.push_back(k);
    }
    printPreOrder(0, inorder.size()-1, 0, postorder.size()-1);
}