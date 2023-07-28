#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    vector<pair<TreeNode*, int>> children;
    int data;
};

int longest;

int height(TreeNode* root) {
    vector<int> heights;
    vector<int> plus;
    for(int i=0;i<root->children.size();i++) {
        plus.push_back(height(root->children[i].first));
        heights.push_back(root->children[i].second + plus[i]);
    }
    if(heights.empty()) return 0;
    sort(heights.begin(), heights.end());
    if(heights.size()>=2) longest = max(longest, heights[heights.size()-1]+heights[heights.size()-2]);
    return heights.back();
}

int solve(TreeNode* root) {
    longest = 0;
    int h = height(root);
    return max(h, longest);
}

int main() {
    int C;
    cin>>C;
    int r, d, length;
    vector<TreeNode*> treeData;
    for(int i=0;i<C;i++) {
        TreeNode* newTree = new TreeNode();
        newTree->data = i+1;
        treeData.push_back(newTree);
    }
    int root, child, l;
    while(cin>>root>>child>>l) {
        treeData[root-1]->children.push_back(make_pair(treeData[child-1], l));
    }
    int answer = solve(treeData[0]);
    cout<<answer;
}