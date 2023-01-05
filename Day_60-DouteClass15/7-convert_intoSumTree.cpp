//convert a tree into its sum tree
#include <bits/stdc++.h>
using namespace std;

class node{
	public:
        int data;
        node *left;
        node *right;
};

int toSumTree(node *Node){
	// Base case
	if(Node == NULL)
	return 0;

	// Store the old value
	int old_val = Node->data;

	// right subtrees and store the sum as
	// old value of this node
	Node->data = toSumTree(Node->left) + toSumTree(Node->right);

	// in left and right subtrees and
	// old_value of this node
	return Node->data + old_val;
}

void printInorder(node* Node){
	if (Node == NULL)
		return;
	printInorder(Node->left);
	cout<<" "<<Node->data;
	printInorder(Node->right);
}

node* newNode(int data){
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int main(){
	node *root = NULL;
	int x;

	root = newNode(9);
	root->left = newNode(7);
	root->right = newNode(6);
	root->left->left = newNode(2);
	root->left->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	
	toSumTree(root);

	cout<<"Inorder Traversal of the resultant tree is: \n";
	printInorder(root);
	return 0;
}