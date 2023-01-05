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

Node* LCA(Node* root, Node* p, Node* q) {
    if(root == NULL)
        return NULL;
        
    if(root == p || root == q)
        return root;
    
    else
    {
        Node* leftAns = LCA(root->left, p, q);
        Node* rightAns = LCA(root->right, p, q);
          
        if(leftAns != NULL && rightAns != NULL)
            return root;

        else if(leftAns == NULL)
            return rightAns;

        else
            return leftAns; 
    }
}

int main(){
    Node* root = NULL;
    root = BuildTree();

    Node* p = new Node(5);
    Node* q = new Node(1);

    Node* ans = LCA(root, p, q);
    cout << "Ans is " << ans-> data << endl;
    
}