#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree() {
    cout << "Enter the value of data " << endl;
    int data;
    cin >> data;

    if(data == -1) 
        return NULL;

    Node* newNode = new Node(data);

    cout << "Enter the data for left child of " << data << endl;
    newNode -> left = buildTree();

    cout << "Enter the data for right child of " << data << endl;
    newNode -> right = buildTree();

    return newNode;
}

int height(Node* root ) {
    if(root == NULL)
        return 0;
    
    // int leftAns = height(root->left);
    // int rightAns = height(root->right);
    // return 1+max(leftAns, rightAns);
    return 1 + max(height(root->left), height(root->right));
}

int main() {

    Node* root = NULL;
    root = buildTree();
    cout << "Height of tree is: " << height(root) << endl;

}