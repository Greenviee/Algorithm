#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    
    Node* CreateNode();
    Node* CreateNode(char data);
    bool GetData(Node* node, char data);
    bool SetData(Node* node, char data);
    
    bool GetLeftNode(Node* parent, Node** node);
	bool GetRightNode(Node* parent, Node** node);	

	bool SetLeftNode(Node* parent, Node* child);
	bool SetRightNode(Node* parent, Node* child);
	
	void PreOrder(Node* node);
	void InOrder(Node* node);
	void PostOrder(Node* node);
	
	void RemoveNode(Node* node);
};

Node* BinaryTree::CreateNode() {
    Node* newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* BinaryTree::CreateNode(char data) {
    Node* newNode = new Node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

bool BinaryTree::GetData(Node* node, char data) {
    
    data = node->data;
    cout<<data<<endl;
    return true;
}

bool BinaryTree::SetData(Node* node, char data) {
    node->data = data;
    return true;
}

bool BinaryTree::GetLeftNode(Node* parent, Node** node)
{
	if (parent == NULL || parent->left == NULL)
	{
		*node = NULL;
		return false;
	}

	*node = parent->left;
	return true;
}

bool BinaryTree::GetRightNode(Node* parent, Node** node)
{
	if (parent == NULL || parent->right == NULL)
	{
		*node = NULL;
		return false;
	}

	*node = parent->right;
	return true;
}

bool BinaryTree::SetLeftNode(Node* parent, Node* child)
{
	if (parent == NULL || child == NULL)
		return false;

	if (parent->left != NULL)				
		RemoveNode(parent->left);			

	parent->left = child;
	return true;
}

bool BinaryTree::SetRightNode(Node* parent, Node* child)
{
	if (parent == NULL || child == NULL)
		return false;

	if (parent->right != NULL)				
		RemoveNode(parent->right);			

	parent->right = child;
	return true;
}

void BinaryTree::PreOrder(Node* node) {
    if(node==NULL) return;
    
    cout<<node->data;
    PreOrder(node->left);
    PreOrder(node->right);
}

void BinaryTree::InOrder(Node* node) {
    if(node==NULL) return;
    
    InOrder(node->left);
    cout<<node->data;
    InOrder(node->right);
}

void BinaryTree::PostOrder(Node* node) {
    if(node==NULL) return;
    
    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->data;
}

void BinaryTree::RemoveNode(Node* node) {
    if (node == NULL)
		return;

	RemoveNode(node->left);					
	RemoveNode(node->right);
	delete node;
}

int main() {
    int C;
    cin>>C;
    BinaryTree* newTree;
    Node* obj[27];
    for(int i=0;i<C;i++) obj[i] = newTree->CreateNode();
    for(int i=0;i<C;i++) {
        char data = 'A'+i;
        newTree->SetData(obj[i], data);
    }
    char root, left, right;
    for(int i=0;i<C;i++) {
        cin>>root>>left>>right;
        if(left!='.') newTree->SetLeftNode(obj[root-'A'], obj[left-'A']);
        if(right!='.') newTree->SetRightNode(obj[root-'A'], obj[right-'A']);
    }
    newTree->PreOrder(obj[0]); cout<<endl;
    newTree->InOrder(obj[0]); cout<<endl;
    newTree->PostOrder(obj[0]);
}