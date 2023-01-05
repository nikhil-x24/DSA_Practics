#include<iostream>
#include<queue>
#include<vector>
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

void inorder(Node* root, vector<int> &in) {
    //LNR
    //base case
    if(root == NULL)
        return;

    //L
    inorder(root->left, in);
    //N
    in.push_back(root->data);
    //R
    inorder(root->right, in);
}

Node* inorderToBST(int s, int e, vector<int>& in){
    //base case
    if(s > e)
        return NULL;
    
    int mid = (s+e) /2;
    Node* root = new Node(in[mid]);

    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

Node* balance(Node* root){

    vector<int> inorderVal;
    inorder(root, inorderVal);

    int s = 0;
    int e = inorderVal.size() - 1;

    return inorderToBST(s, e, inorderVal);
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

int main(){

    Node* root = NULL;
    root = buildTree();

    root = balance(root);
    
    lvlOrderTraversal(root);

    return 0;
}