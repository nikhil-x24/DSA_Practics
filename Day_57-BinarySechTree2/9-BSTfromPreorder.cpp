#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node* solve(vector<int>& preorder, int mini, int maxi, int &i){

    if(i >= preorder.size())
        return NULL;
    
    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;
    
    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

Node* preorderToBST(vector<int> &preorder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

void inOrder(Node* root) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    inOrder(root->left);
    //N
    cout << root->data << " ";
    //R
    inOrder(root->right);
}

int main(){

    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
    Node* root = preorderToBST(preorder);

    cout << "Inorder traversal of the constructed tree: \n";
    inOrder(root);
}