#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
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

int height(Node* root ) {
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root){
    if(root == NULL)
        return true;

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(leftAns && rightAns && diff)
        return true;
    
    else
        return false;
}

int main(){
    Node* root = NULL;
    root = BuildTree();
    if(isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}