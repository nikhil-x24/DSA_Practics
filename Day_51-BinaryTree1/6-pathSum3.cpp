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

int count = 0 ;

void solve(Node* root, int target, int sum ) {
    if(root == NULL)
        return;
       
    if(target == sum)
        count++;
        
    if(root->left != NULL)
        solve(root->left, target, sum + root->left->data);
        
    if(root->right != NULL)
        solve(root->right, target, sum + root->right->data);
        
}
    
int pathSum(Node* root, int targetSum) {
    if(root == NULL)
        return 0;
        
    //jis node pr khade ho,usko starting node maankar solve krne ka try karo
    solve(root, targetSum, root->data);
       
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return count;
}

int main(){
    Node* root = NULL;
    root = BuildTree();

    cout << pathSum(root, 6);
    
}