#include<iostream>
#include<vector>
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

void traverseLeft(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
            
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
            
}
    
void traverseLeaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL)
        return ;
            
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
        
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
        
}
    
void traverseRight(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
        
    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
            
    //wapas aagye
    ans.push_back(root->data);
            
}
    
vector <int> boundary(Node *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;
            
    ans.push_back(root->data);
        
    //left part print/store
    traverseLeft(root->left, ans);
        
    //traverse Leaf Nodes    
        //left subtree
        traverseLeaf(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
    //traverse right part
    traverseRight(root->right, ans);
        
    return ans;
        
        
}

int main() {

    Node* root = NULL;
    root = BuildTree();

    vector<int> ans;
    ans = boundary(root);

    cout << "Boundary Traversal of Binary Tree" << endl;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
        
    cout << endl;
    return 0;
}