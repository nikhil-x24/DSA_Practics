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
    if(root == NULL || i >= k){
        return -1;
    }

    //R
    solve(root->right, i, k);
  
    //increment count of visited nodes
    i++;
  
    // If c becomes k now, then this is the k'th largest 
    if (i == k){
        return root->data;
    }
  
    //L
    return solve(root->left, i, k);
}

int KthLargest(Node* root, int i, int k){
    int ans= solve(root, i , k);
    return ans;
}

int main(){

    Node* root = NULL;
    root = buildTree();

    cout << "Kth largest value is : " << KthLargest(root, 0, 3);
    cout << endl;
    
    
    cout << "Printing Level Order " << endl;
    lvlOrderTraversal(root);
    cout << endl;

}