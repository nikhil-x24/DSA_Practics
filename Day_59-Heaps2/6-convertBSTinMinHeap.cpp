#include <bits/stdc++.h>
using namespace std;

struct Node {

	int data;
	Node *left, *right;
};

struct Node* getNode(int data) {
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void preorderTraversal(Node*);

void inorderTraversal(Node* root, vector<int>& arr) {
	if (root == NULL)
		return;

	// first recur on left subtree
	inorderTraversal(root->left, arr);

	// then copy the data of the node
	arr.push_back(root->data);

	// now recur for right subtree
	inorderTraversal(root->right, arr);
}

void BSTToMinHeap(Node* root, vector<int> arr, int* i) {
	if (root == NULL)
		return;

	// first copy data at index 'i' of 'arr' to
	// the node
	root->data = arr[++*i];

	// then recur on left subtree
	BSTToMinHeap(root->left, arr, i);

	// now recur on right subtree
	BSTToMinHeap(root->right, arr, i);
}

void convertToMinHeapUtil(Node* root){

	vector<int> arr;
	int i = -1;

	// inorder traversal to populate 'arr'
	inorderTraversal(root, arr);

	// BST to MIN HEAP conversion
	BSTToMinHeap(root, arr, &i);
}

void preorderTraversal(Node* root) {
	if (!root)
		return;

	// first print the root's data
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

int main() {
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	// Function call
	convertToMinHeapUtil(root);
	cout << "Preorder Traversal:" << endl;
	preorderTraversal(root);

	return 0;
}
