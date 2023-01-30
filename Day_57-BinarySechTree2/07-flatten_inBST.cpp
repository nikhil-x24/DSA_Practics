#include<iostream>
#include<vector>
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

void inorder(Node* root, vector<int> &in) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    inorder(root->left, in);
    //N
    in.push_back(root->data);
    //R
    inorder(root->right, in);
}

Node* flatten(Node* root){
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    //step2->
    for(int i = 1; i < n; i++){
        Node* temp = new Node(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    //step3->
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}

int main(){

    Node* root = NULL;
    root = buildTree();

    Node* t = flatten(root);
    while (t != NULL)
        cout << t->data << " ", t = t->right;

    return 0;
}