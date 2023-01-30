#include<iostream>
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

class Info {
    public:
        int mini;
        int maxi;
        int size;
        bool isBST;
        
    Info(int a, int b, int c, bool d){
        mini = a;
        maxi = b;
        size = c;
        isBST = d;
    }

    Info(){
    }
};

Info solve(Node* root, int& ans) {

    //base case
    if(root == NULL) {
        return Info(INT_MAX, INT_MIN, 0, true);
    }
    
    //solve for left
    Info leftAns = solve(root->left, ans);
    //solve for right
    Info rightAns = solve(root->right, ans);

    //create ans for current node/subtree
    Info curr;

    curr.size = leftAns.size + rightAns.size + 1;
    curr.mini = min(leftAns.mini, root->data);
    curr.maxi = max(rightAns.maxi, root->data);

    if(leftAns.isBST && rightAns.isBST && 
       (root->data > leftAns.maxi && root->data < rightAns.mini) ) 
       {
        curr.isBST = true;
       }
    else {
        curr.isBST = false;
    }

    //ifcurr subtree is BST, then update ans
    if(curr.isBST)
        ans = max(ans, curr.size);

    //return all values of current subtree to upper levels
    return curr;
}
int largestBST(Node* root) {
    int ans = 0;
    solve(root, ans);
    return ans;
}

int main(){

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << " Size of the largest BST is " << largestBST(root);
    return 0;

}