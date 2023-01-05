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

bool hasPathSum(Node* root, int targetSum) {
        if(root == NULL)
            return false;
        
        if(root->data == targetSum && 
           root->left == NULL && 
           root->right == NULL)
           return true;
        
        bool leftAns = hasPathSum(root->left, targetSum - root->data);
        bool rightAns = hasPathSum(root->right, targetSum - root->data);
        
        return leftAns || rightAns;
    }

int main(){
    Node* root = NULL;
    root = BuildTree();
    if(hasPathSum(root, 22))
        cout << "Yes, Target is present";
    else
        cout << "No, Not present ";
}