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

void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    //base case
    if( root == NULL ) {
           
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) {
                maxSum = max(sum, maxSum);
        }
        return;
    }
        
    sum = sum + root->data;
        
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);

}
    
int sumOfLongRootToLeafPath(Node *root) {

    int len = 0;
    int maxLen = 0;
        
    int sum = 0;
    int maxSum = INT_MIN;
        
    solve(root, sum, maxSum, len, maxLen);
        
    return maxSum;
}

int main(){
    
    Node* root = NULL;
    root = BuildTree();

    cout << sumOfLongRootToLeafPath(root);
    return 0;
}