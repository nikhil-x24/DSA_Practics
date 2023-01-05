#include<iostream>
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

bool twoSuminBST(Node* root, int target){
    vector<int> inorderVal;
    inorder(root, inorderVal);

    int i = 0;
    int j = inorderVal.size() - 1;

    while(i < j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return true;
        }
        else if(sum > target){
            j--;
        }
        else{
            i++;
        }
        return false;
    }
}

int main(){

    Node* root = NULL;
    root = buildTree();

    int target = 20;
    if(twoSuminBST(root, target))
        cout << "Target is Present ";
    
    else
        cout << "Not Present";

    return 0;
}