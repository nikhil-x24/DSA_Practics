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

bool solve(Node* a, Node* b) {
    if( a == NULL && b == NULL)
        return true;
    if(a != NULL && b == NULL)
        return false;
    if(a == NULL && b != NULL)
        return false;
    if(a->data != b->data )
        return false;
        
    //catch hai -> lateral img - left <-> right
    return solve(a->left, b->right) && solve(a->right, b->left);
}

bool isSymmetric(Node* root) {
    if(root == NULL)
        return true;
       
    return solve(root->left, root->right);
}

int main(){
    Node* root = NULL;
    root = BuildTree();
    if(isSymmetric(root))
        cout << "Symmetric";
    else
        cout << "Not Symmetric";
}