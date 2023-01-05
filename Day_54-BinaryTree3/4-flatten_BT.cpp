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

void flatten(Node* root) {
    
    Node* curr = root;
    while(curr != NULL){

        if(curr -> left){

            Node* pred = curr->left;
            while(pred->right)
                pred = pred->right;
            
            pred->right = curr->right;
            curr->right = curr->left;
            //ya fir aise left part ko null kr do
            curr->left = NULL;
        }
        curr = curr->right;
    }
    ////left part to null krte chlo
    // curr = root;
    // while(curr != NULL){
    //     curr->left = NULL;
    //     curr = curr->right;
    // }
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
    Node* root = NULL;
    root = BuildTree();
    
    flatten(root);

    cout << "Printing Inorder " << endl;
    inOrder(root);
    cout << endl;

    return 0;
}