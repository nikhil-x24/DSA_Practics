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

//Function to return the maximum sum of non-adjacent nodes.
pair<int,int> solve(Node* root) {
    //base case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
      
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
        
    pair<int,int> res;
        
    res.first = root->data + left.second + right.second;
        
    res.second = max(left.first, left.second) + max(right.first, right.second);
        
    return res;
        
}

int getMaxSum(Node *root) {

    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(){
    
    Node* root = NULL;
    root = BuildTree();

    cout << getMaxSum(root);
    return 0;
}