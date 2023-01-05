#include<iostream>
#include<queue>
#include<limits.h>
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

Node* LCA(Node* root, int a, int b){
    //bc
    if(root == NULL)
        return NULL;
    
    if(root->data < a && root->data < b)
        return LCA(root->right, a, b);


    if(root->data > a && root->data > b)
        return LCA(root->left, a, b);
    
    else   
        return root;
}

int main(){

    Node* root = NULL;
    root = buildTree();

    int a = 2, b = 5;
    Node *t = LCA(root, a, b);
    cout << "LCA of " << a << " and " << b << " is " << t->data<<endl;
 
    return 0;
}