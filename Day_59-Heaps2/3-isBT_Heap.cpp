#include<iostream>
#include<queue>
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

int countNodes(Node* root){
    //base case
    if(root == NULL)
        return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root, int index, int cnt){
    if(root == NULL)
        return NULL;
    
    // 0 based indexing
    if(index >= cnt)
        return false;
    
    else{
        bool left = isCBT(root->left, 2 * index +1, cnt);
        bool right = isCBT(root->right, 2 * index +2, cnt);
        return (left && right);
    }
}

bool isMaxOrder(Node* root){
    //base case
    //left Node
    if(root->left == NULL && root->right == NULL)
        return true;

    if(root->right == NULL)
        return (root-> data > root->left->data);
    
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return left && right && 
              (root->data > root->left->data && 
               root->data > root->right->data);
    }
}

bool isHeap(Node* root){
    int index = 0;
    int totalCnt = countNodes(root);

    if(isCBT (root, index, totalCnt) && isMaxOrder(root))
        return true;
    else
        return false;
}
int main(){

    Node* root = NULL;

    root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);
 
    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
 
    return 0;
}