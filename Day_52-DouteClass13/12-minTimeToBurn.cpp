#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int k) {
            data = k;
            left = right = NULL;
        }
};

Node* BuildTree(){
    cout <<"Enter a data ";
    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    Node* newNode = new Node(data);

    cout << "Enter the data for left child of " << data << endl;
    newNode -> left = BuildTree();

    cout << "Enter the data for right child of " << data << endl;
    newNode -> right = BuildTree();

    return newNode;
}

int res = 0;

int burnTime(Node* root, int leaf, int& dist) {
	if (root == NULL)
		return 0;
	if (root->data == leaf) {
		dist = 0;
		return 1;
	}
	int ldist = -1, rdist = -1;
	int lh = burnTime(root->left, leaf, ldist);
	int rh = burnTime(root->right, leaf, rdist);

	if (ldist != -1) {
		dist = ldist + 1;
		res = max(res, dist + rh);
	}
	else if (rdist != -1) {
		dist = rdist + 1;
		res = max(res, dist + lh);
	}
	return max(lh, rh) + 1;
}

int main() {

    Node* root = NULL;
    root = BuildTree();

	int dist = -1;
	int target = 8;

	burnTime(root, target, dist);
	cout << res;
	return 0;
}