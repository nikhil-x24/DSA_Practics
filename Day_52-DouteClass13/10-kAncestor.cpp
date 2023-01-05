#include<iostream>
#include<limits.h>
#include<vector>
#include<queue>
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

Node* solve(Node* root, int &k, int node) {
    if(root == NULL)
        return NULL;
        
    if(root->data == node) {
        return root;
    }    
    
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k ,node);
    
    if(left != NULL && right == NULL) 
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    else if(left == NULL && right != NULL) 
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    else
    {
        return NULL;
    }
}

int kthAncestor(Node *root, int k, int node) {

    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
    
}

int main(){
    
    Node* root = NULL;
    root = BuildTree();

    int node = 5;
    int k = 2;

    cout << kthAncestor(root, k, node);
    return 0;
}