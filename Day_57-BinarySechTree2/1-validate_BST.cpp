#include<iostream>
#include<queue>
#include<limits.h>
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

Node* buildTree() {
    cout << "Enter the value of data " << endl;
    int data;
    cin >> data;

    if(data == -1) 
        return NULL;

    Node* newNode = new Node(data);

    cout << "Enter the data for left child of " << data << endl;
    newNode -> left = buildTree();

    cout << "Enter the data for right child of " << data << endl;
    newNode -> right = buildTree();

    return newNode;
}

void lvlOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    //change no. 1
    q.push(NULL);

    while(!q.empty()) {
        //tu nikal
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            cout << endl;
            //catch here
            if(!q.empty())//still elements are present
                q.push(NULL);
        }
        else{
            cout << front->data << " ";

            //bache chor jaio
            if(front->left != NULL)
                q.push(front->left);
            if(front->right != NULL)
                q.push(front->right);
        }
    }
}

int isBST(Node* root, int min, int max){
    //base case
    if(root == NULL){
        return 1;
    }

    if(root->data >= min && root->data <= max){
        return isBST(root->left, min, root->data) && 
                isBST(root->right, root->data, max);  
    }
    else
        return false;
}

int validateBST(Node* root){
    return(isBST(root, INT_MIN, INT_MAX));
}

int main(){

    Node* root = NULL;
    root = buildTree();

    if(validateBST(root))
        cout<<"Yes BST" << endl;
    else
        cout<<"Not a BST" << endl;

    cout << "Printing Level Order " << endl;
    lvlOrderTraversal(root);
    cout << endl;

}