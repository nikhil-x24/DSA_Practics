#include <iostream>
#include <climits>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to check if a given binary tree is a sum tree or not
int isSumTree(Node* root)
{
    // base case: empty tree
    if (root == nullptr) {
        return 0;
    }
 
    // special case: leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return root->key;
    }
 
    int left = isSumTree(root->left);
    int right = isSumTree(root->right);
 
    // if the root's value is equal to the sum of all elements present in its
    // left and right subtree
    if (left != INT_MIN && right != INT_MIN && root->key == left + right) {
        return 2 * root->key;
    }
 
    return INT_MIN;
}
 
int main()
{
    /* Construct the following tree
             44
            /  \
           /    \
          9     13
         / \    / \
        4   5  6   7
    */
 
    Node* root = new Node(44);
    root->left = new Node(9);
    root->right = new Node(13);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    if (isSumTree(root) != INT_MIN) {
        cout << "Binary tree is a sum tree";
    }
    else {
        cout << "Binary tree is not a sum tree";
    }
 
    return 0;
}