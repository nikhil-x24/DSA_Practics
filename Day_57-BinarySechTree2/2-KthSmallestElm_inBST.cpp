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

int solve(Node* root, int &i, int k){
    //base case
    if(root == NULL){
        return -1;
    }

    //L
    int left = solve(root->left, i ,k);
    if(left != -1)
        return left;
    
    //N
    i++;
    if(i == k)
        return root->data;
    
    //R
    return solve(root->right, i , k);
}

int KthSmallest(Node* root, int i, int k){
    int ans= solve(root, i , k);
    return ans;
}

int main(){

    Node* root = NULL;
    root = buildTree();

    cout << "Kth smallest value is : " << KthSmallest(root, 0, 3);
    cout << endl;
    
    
    cout << "Printing Level Order " << endl;
    lvlOrderTraversal(root);
    cout << endl;

}