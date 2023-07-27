#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> preorder;

//lstart = 트리 시작점, rstart = 트리 끝점
void printPostOrder(int s, int e) {
   if(s>e) return;
   
   int size = e - s + 1;
   int root = preorder[s];
   int L = 0;
   for(int i=s+1;i<=e;i++) {
       if(root>preorder[i]) L++;
       else break;
   }
   int R = size - L - 1;
   
   printPostOrder(s+1, s+L);
   printPostOrder(s+L+1, e);
   cout<<root<<endl;
}

int main() {
    int num;
    while(cin>>num) preorder.push_back(num);
    printPostOrder(0, preorder.size()-1);
}