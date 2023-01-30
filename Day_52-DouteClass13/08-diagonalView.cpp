#include<iostream>
#include<vector>
#include<queue>
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

vector<int> diagonal(Node* root) {
 
    vector<int> diagonalVals;
    if (!root)
        return diagonalVals;
 
    // The leftQueue will be a queue which will store all
    // left pointers while traversing the tree, and will be
    // utilized when at any point right pointer becomes NULL
 
    queue<Node*> leftQueue;
    Node* node = root;
 
    while (node) {
 
        // Add current node to output
        diagonalVals.push_back(node->data);
        // If left child available, add it to queue
        if (node->left)
            leftQueue.push(node->left);
 
        // if right child, transfer the node to right
        if (node->right)
            node = node->right;
 
        else {
            // If left child Queue is not empty, utilize it
            // to traverse further
            if (!leftQueue.empty()) {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else {
                // All the right childs traversed and no
                // left child left
                node = NULL;
            }
        }
    }
    return diagonalVals;
}

int main(){
    Node* root = NULL;
    root = BuildTree();
    
    vector<int> ans;
    ans = diagonal(root);

    cout << "Diagonal View in Binary Tree" << endl;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
        
    cout << endl;
    return 0;
}