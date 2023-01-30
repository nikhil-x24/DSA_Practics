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

void solve(Node* root, vector<int> &ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        

    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
    //solve(root->right, ans, level+1);   -> right wala RCall phle kr do 
}

vector<int> rightView(Node *root){
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}

int main(){
    Node* root = NULL;
    root = BuildTree();
    
    vector<int> ans;
    ans = rightView(root);

    cout << "Right View in Binary Tree" << endl;

    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " ";
        
    cout << endl;
    return 0;
}